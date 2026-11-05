import java.io.*;
import java.net.*;
import java.util.*;
import org.json.*;
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

class Server implements Runnable {
    private MulticastSocket socket;
    private final InetAddress group = InetAddress.getByName("ff12::caca");
    private final int port = 6767;
    private int periodms = 1000;

    private DocumentBuilder dbuilder;
    private Validator validator;
    private Transformer transformer;

    private boolean temp = false, humid = false, press = false;
    private float tempVal = 25, humidVal = 40, pressVal = 1000.0f;
    private boolean tempC = true, pressMbar = true;

    private boolean json = false;

    public Server(String[] args) throws IOException, ParserConfigurationException, SAXException, TransformerConfigurationException {
        String ifname = "lo";
        if (args.length > 0)
            ifname = args[0];

        if (args.length > 1) {
            String[] sens = args[1].split(",");
            for (String s : sens) {
                temp |= s.equals("temp");
                humid |= s.equals("humid");
                press |= s.equals("press");
            }
        }
        else
            temp = humid = press = true;

        socket = new MulticastSocket(port);
        socket.setReuseAddress(true);
        socket.setNetworkInterface(NetworkInterface.getByName(ifname));

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

    private void sendUpdate() throws IOException {

    }

    @Override
    public void run() {
        byte[] buf = new byte[1024];
        while (true) {
            DatagramPacket p = new DatagramPacket(buf, buf.length);
            try { socket.receive(p); }
            catch (IOException e) { e.printStackTrace(); }
            String s = new String(p.getData(), 0, p.getLength());
            System.out.println("received: " + s);


            Element root;

            try {
                Document document = dbuilder.parse(new ByteArrayInputStream(p.getData()));
                document.getDocumentElement().normalize();
                root = document.getDocumentElement();
                validator.validate(new DOMSource(root));
                System.out.println(" xml verified");
            } catch (Exception e) {
                e.printStackTrace();
                continue;
            }

            NodeList nlfmt = root.getElementsByTagName("format");
            NodeList nlfreq = root.getElementsByTagName("frequency");
            NodeList nlunit = root.getElementsByTagName("unit");
            NodeList nlen = root.getElementsByTagName("enabled");
            if (nlfmt.getLength() == 1)
                System.out.println(" format: " + nlfmt.item(0).getTextContent());
            else if (nlfreq.getLength() == 1)
                System.out.println(" frequency: " + nlfreq.item(0).getTextContent());
            else if (nlen.getLength() == 1)
                System.out.println(" enabled: " + nlen.item(0).getTextContent());

        }
    }

    /* internal units
     * temp: C
     * humid: %
     * press: mbar
     */
    private void genSensorData() {
        if (temp)
            tempVal += 0.01f;
        if (humid)
            humidVal *= 0.99;
        if (press)
            pressVal *= 1.05;
    }

    private String serializeDataXML() {
        try {
            Document doc = dbuilder.newDocument();

            Element rootElement = doc.createElement("data");
            doc.appendChild(rootElement);

            if (temp) {
                Element tempE = doc.createElement("temp");
                tempE.appendChild(doc.createTextNode(Float.toString(tempVal)));
                rootElement.appendChild(tempE);
                Attr unitA = doc.createAttribute("unit");
                unitA.setValue(tempC ? "C" : "F");
                tempE.setAttributeNode(unitA);
            }

            if (humid) {
                Element humidE = doc.createElement("humid");
                humidE.appendChild(doc.createTextNode(Float.toString(humidVal)));
                rootElement.appendChild(humidE);
            }

            if (press) {
                Element pressE = doc.createElement("temp");
                pressE.appendChild(doc.createTextNode(Float.toString(tempVal)));
                rootElement.appendChild(pressE);
                Attr unitA = doc.createAttribute("unit");
                unitA.setValue(pressMbar ? "mbar" : "hpa");
                pressE.setAttributeNode(unitA);
            }

            DOMSource source = new DOMSource(doc);
            StringWriter sw = new StringWriter();
            StreamResult result = new StreamResult(sw);
            transformer.transform(source, result);
            return sw.toString();
        } catch (Exception e) {
            e.printStackTrace();
        }
        return "xml error";
    }

    private String serializeDataJSON() {
        return "{}";
    }


    public void sendLoop() {
        while (true) {
            try {
                genSensorData();
                String serData = json ? serializeDataJSON() : serializeDataXML();
                sendBroadcast(serData);
                System.out.println("sent: " + serData);
            }
            catch (IOException e) { e.printStackTrace(); }

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

