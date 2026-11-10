import java.io.*;
import java.net.*;
import java.util.*;
import javax.xml.*;
import javax.xml.transform.*;
import javax.xml.transform.dom.*;
import javax.xml.transform.stream.*;
import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import org.w3c.dom.Document;
import org.w3c.dom.NodeList;
import org.w3c.dom.Element;
import org.w3c.dom.Node;
import org.w3c.dom.Attr;
import javax.xml.validation.*;
import org.xml.sax.*;
import javax.xml.parsers.*;
import java.util.stream.*;
import com.google.gson.*;
import com.google.gson.stream.*;

class Server implements Runnable {
    private MulticastSocket socket;
    private final InetAddress group = InetAddress.getByName("ff12::caca");
    private final int port = 6767;

    private DatagramSocket ctrlSocket;

    private int periodms = 1000;

    private DocumentBuilder dbuilder;
    private Validator validator;
    private Transformer transformer;

    private final String id;

    private boolean weather = true, quality = false;

    private float tempVal = 25, humidVal = 40, pressVal = 1000.0f;
    private boolean tempC = true, pressMbar = true;

    private float pm10val = 1, so2val = 1, no2val = 1, o3val = 1;
    private boolean pm10ppm = true, gasppm = true;


    private boolean json = false;
    private boolean enabled = true;

    public Server(String[] args) throws IOException, ParserConfigurationException, SAXException, TransformerConfigurationException {
        String ifname = "lo";
        if (args.length > 0)
            ifname = args[0];

        if (args.length > 1)
            id = args[1];
        else
            id = "default";

        if (args.length > 2) {
            weather = args[2].equals("weather");
            quality = args[2].equals("quality");
        }


        socket = new MulticastSocket();
        socket.setReuseAddress(true);
        socket.setNetworkInterface(NetworkInterface.getByName(ifname));

        ctrlSocket = new DatagramSocket(null);
        ctrlSocket.setReuseAddress(true);
        ctrlSocket.bind(new InetSocketAddress(InetAddress.getByAddress(new byte[]{0,0,0,0}), port+1));

        DocumentBuilderFactory dbFactory = DocumentBuilderFactory.newInstance();
        dbuilder = dbFactory.newDocumentBuilder();

        SchemaFactory sfactory = SchemaFactory.newInstance(XMLConstants.W3C_XML_SCHEMA_NS_URI);
        Source schemaFile = new StreamSource(new File("control.xsd"));
        Schema schema = sfactory.newSchema(schemaFile);
        validator = schema.newValidator();

        TransformerFactory transformerFactory = TransformerFactory.newInstance();
        transformer = transformerFactory.newTransformer();

    }

    private void sendBroadcast(String msg) throws IOException {
        byte[] buf = msg.getBytes();
        DatagramPacket p = new DatagramPacket(buf, buf.length, group, port);
        socket.send(p);
    }

    @Override
    public void run() {
        byte[] buf = new byte[1024];
        while (true) {
            DatagramPacket p = new DatagramPacket(buf, buf.length);
            try { ctrlSocket.receive(p); }
            catch (IOException e) { e.printStackTrace(); }
            String s = new String(p.getData(), 0, p.getLength());
            System.out.println("received: " + s);

            Element root;

            try {
                Document document = dbuilder.parse(new ByteArrayInputStream(p.getData(), p.getOffset(), p.getLength()));
                document.getDocumentElement().normalize();
                root = document.getDocumentElement();
                validator.validate(new DOMSource(root));
            } catch (Exception e) {
                e.printStackTrace();
                continue;
            }

            NodeList nlfmt = root.getElementsByTagName("format");
            NodeList nlfreq = root.getElementsByTagName("frequency");
            NodeList nlunit = root.getElementsByTagName("unit");
            NodeList nlen = root.getElementsByTagName("enable");
            if (nlfmt.getLength() == 1) {
                System.out.println(" format: " + nlfmt.item(0).getTextContent());
                json = nlfmt.item(0).getTextContent().equals("json");
            }
            else if (nlfreq.getLength() == 1) {
                System.out.println(" frequency: " + nlfreq.item(0).getTextContent());
                periodms = 1000/Integer.parseInt(nlfreq.item(0).getTextContent());
            } else if (nlen.getLength() == 1) {
                System.out.println(" enable: " + nlen.item(0).getTextContent());
                enabled = nlen.item(0).getTextContent().equals("true");
            }

            for (int i = 0; i < nlunit.getLength(); i++) {
                String mag = nlunit.item(i).getAttributes().getNamedItem("magnitude").getTextContent();
                String unit = nlunit.item(i).getTextContent();
                System.out.println(" unit(" + mag + "): " + unit);
                if (mag.equals("temp")) {
                    if (unit.equals("F"))
                        tempC = false;
                    else if (unit.equals("C"))
                        tempC = true;
                } else if (mag.equals("press")) {
                    if (unit.equals("mbar"))
                        pressMbar = true;
                    else if (unit.equals("hpa"))
                        pressMbar = false;
                } else if (mag.equals("pm10")) {
                    if (unit.equals("ppm"))
                        pm10ppm = true;
                    else if (unit.equals("ugpsqm"))
                        pm10ppm = false;
                } else if (mag.equals("gas")) {
                    if (unit.equals("ppm"))
                        gasppm = true;
                    else if (unit.equals("ugpsqm"))
                        gasppm = false;
                }
            }
        }
    }

    /* internal units
     * temp: C
     * humid: %
     * press: mbar
     */
    private void genSensorData() {
        if (weather) {
            tempVal += 0.01f;
            humidVal *= 0.99;
            pressVal *= 1.01;
        }
        if (quality) {
            pm10val += 1;
            so2val += 1;
            no2val += 1;
            o3val += 1;

        }
    }

    private Element serializeMeasurementXML(Document doc, String mag, String unit, float val) {
        Element elem = doc.createElement("measurement");
        Attr magA = doc.createAttribute("magnitude");
        magA.setValue(mag);
        elem.setAttributeNode(magA);
        Attr unitA = doc.createAttribute("unit");
        unitA.setValue(unit);
        elem.setAttributeNode(unitA);
        elem.appendChild(doc.createTextNode(Float.toString(val)));
        return elem;
    }

    private String serializeDataXML() {
        try {
            Document doc = dbuilder.newDocument();

            Element rootElement = doc.createElement("data");
            doc.appendChild(rootElement);

            Element serverE = doc.createElement("server");
            serverE.appendChild(doc.createTextNode(id));
            rootElement.appendChild(serverE);

            if (weather) {
                rootElement.appendChild(serializeMeasurementXML(doc, "temp", tempC ? "C" : "F", tempC ? tempVal : (tempVal * 1.8f) + 32.0f));
                rootElement.appendChild(serializeMeasurementXML(doc, "humid", "%", humidVal));
                rootElement.appendChild(serializeMeasurementXML(doc, "press", pressMbar ? "mbar" : "hpa", pressVal));
            }

            if (quality) {
                rootElement.appendChild(serializeMeasurementXML(doc, "pm10", "ugpsqm", pm10val));
                rootElement.appendChild(serializeMeasurementXML(doc, "so2", gasppm ? "ppm" : "ugpsqm", gasppm ? so2val : so2val * 64.1f * 40.9f));
                rootElement.appendChild(serializeMeasurementXML(doc, "no2", gasppm ? "ppm" : "ugpsqm", gasppm ? no2val : no2val * 46.1f * 40.9f));
                rootElement.appendChild(serializeMeasurementXML(doc, "o3", gasppm ? "ppm" : "ugpsqm", gasppm ? o3val : o3val * 48.0f * 40.9f));
            }

            DOMSource source = new DOMSource(doc);
            StringWriter sw = new StringWriter();
            StreamResult result = new StreamResult(sw);
            transformer.transform(source, result);
            return "Content-Type: application/xml\r\n\r\n" + sw.toString();
        } catch (Exception e) {
            e.printStackTrace();
        }
        return "xml error";
    }

    private String serializeDataJSON() throws Exception {
        ByteArrayOutputStream baos = new ByteArrayOutputStream();
        JsonWriter writer = new JsonWriter(new OutputStreamWriter(baos, "UTF-8"));
        writer.setIndent(" ");
        writer.beginObject();
        writer.name("server").value(id);

        writer.name("measurements");
        writer.beginArray();

        if (weather) {
            writer.beginObject();
            writer.name("magnitude").value("temp");
            writer.name("unit").value(tempC ? "C" : "F");
            writer.name("value").value(tempC ? tempVal : (tempVal * 1.8f) + 32.0f);
            writer.endObject();

            writer.beginObject();
            writer.name("magnitude").value("humid");
            writer.name("unit").value("%");
            writer.name("value").value(humidVal);
            writer.endObject();

            writer.beginObject();
            writer.name("magnitude").value("press");
            writer.name("unit").value(pressMbar ? "mbar" : "hpa");
            writer.name("value").value(pressVal);
            writer.endObject();
        }

        if (quality) {
            writer.beginObject();
            writer.name("magnitude").value("pm10");
            writer.name("unit").value("ugpsqm");
            writer.name("value").value(pm10val);
            writer.endObject();

            writer.beginObject();
            writer.name("magnitude").value("so2");
            writer.name("unit").value(gasppm ? "ppm" : "ugpsqm");
            writer.name("value").value(gasppm ? no2val : no2val * 64.1f * 40.9f);
            writer.endObject();

            writer.beginObject();
            writer.name("magnitude").value("no2");
            writer.name("unit").value(gasppm ? "ppm" : "ugpsqm");
            writer.name("value").value(gasppm ? no2val : no2val * 46.1f * 40.9f);
            writer.endObject();

            writer.beginObject();
            writer.name("magnitude").value("o3");
            writer.name("unit").value(gasppm ? "ppm" : "ugpsqm");
            writer.name("value").value(gasppm ? no2val : no2val * 48.0f * 40.9f);
            writer.endObject();
        }


        writer.endArray();

        writer.endObject();
        writer.close();

        return "Content-Type: application/json\r\n\r\n" + baos.toString();
    }


    public void sendLoop() {
        while (true) {
            if (enabled) {
                try {
                    genSensorData();
                    String serData;
                    serData = json ? serializeDataJSON() : serializeDataXML();
                    sendBroadcast(serData);
                    System.out.println("sent: " + serData);
                }
                catch (Exception e) { e.printStackTrace(); }
            }

            try {
                Thread.sleep(periodms);
            } catch (Exception e) { e.printStackTrace(); }
        }
    }


    public static void main(String[] args) {
        System.out.println("pcc practica2 servidor mxn");

        try {
            Server s = new Server(args);
            Thread st = new Thread(s);
            st.start();
            s.sendLoop();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}

