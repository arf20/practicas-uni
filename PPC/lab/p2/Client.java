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
import java.util.stream.*;

class Client implements Runnable {
    private static final int port = 6767;
    private static final InetSocketAddress group = new InetSocketAddress("ff12::caca", port);

    private MulticastSocket socket;
    private final NetworkInterface netif;

    private DocumentBuilder dbuilder;
    private Validator validator;
    private Transformer transformer;

    private void sendUnicast(String host, String msg) throws IOException {
        byte[] buf = msg.getBytes();
        DatagramPacket p = new DatagramPacket(buf, buf.length, InetAddress.getByName(host), port);
        socket.send(p);
    }

    public Client(String ifname) throws IOException, ParserConfigurationException, SAXException, TransformerConfigurationException {
        socket = new MulticastSocket(port);
        socket.setReuseAddress(true);
        netif = NetworkInterface.getByName(ifname);
        socket.joinGroup(group, netif);

        DocumentBuilderFactory dbFactory = DocumentBuilderFactory.newInstance();
        dbuilder = dbFactory.newDocumentBuilder();

        SchemaFactory sfactory = SchemaFactory.newInstance(XMLConstants.W3C_XML_SCHEMA_NS_URI);
        Source schemaFile = new StreamSource(new File("data.xsd"));
        Schema schema = sfactory.newSchema(schemaFile);
        validator = schema.newValidator();
    }

    @Override
    public void run() {
        byte[] buf = new byte[1024];
        while (true) {
            DatagramPacket p = new DatagramPacket(buf, buf.length);
            try { socket.receive(p); }
            catch (IOException e) { e.printStackTrace(); }
            String s = new String(p.getData(), 0, p.getLength());

            Element root;

            try {
                Document document = dbuilder.parse(new ByteArrayInputStream(p.getData(), p.getOffset(), p.getLength()));
                document.getDocumentElement().normalize();
                root = document.getDocumentElement();
                validator.validate(new DOMSource(root));

                NodeList nlserver = root.getElementsByTagName("server");
                NodeList nltemp = root.getElementsByTagName("temp");
                NodeList nlhumid = root.getElementsByTagName("humid");
                NodeList nlpress = root.getElementsByTagName("press");

                System.out.println(nlserver.item(0).getTextContent() + ":");
                
                for (int i = 0; i < nltemp.getLength(); i++)
                    System.out.println(" temperature: " + nltemp.item(i).getTextContent() + " " + nltemp.item(i).getAttributes().getNamedItem("unit").getTextContent());
                for (int i = 0; i < nlhumid.getLength(); i++)
                    System.out.println(" humidity:    " + nlhumid.item(i).getTextContent() + " %");
                for (int i = 0; i < nlpress.getLength(); i++)
                    System.out.println(" pressure:    " + nlpress.item(i).getTextContent() + " " + nlpress.item(i).getAttributes().getNamedItem("unit").getTextContent());

            } catch (Exception e) {
                e.printStackTrace();
                continue;
            }
        }
    }

    private static void usage() {
        System.out.println("usage: client [-i <interface>] {listen | cmd <server> <command> <value> [magnitude]}");
        System.exit(1);
    }

    private static void sendPacket(String server, String content) throws Exception {
        byte[] buf = content.getBytes();
        DatagramSocket s = new DatagramSocket();
        DatagramPacket packet = new DatagramPacket(buf, buf.length, InetAddress.getByName(server), port+1);
        s.send(packet);
        s.close();
    }

    private static void sendCmd(String server, String cmd, String val) throws Exception {
        DocumentBuilderFactory dbFactory = DocumentBuilderFactory.newInstance();
        DocumentBuilder dbuilder = dbFactory.newDocumentBuilder();
        Document doc = dbuilder.newDocument();

        Element rootElement = doc.createElement("control");
        doc.appendChild(rootElement);

        Element cmdE = doc.createElement(cmd);
        cmdE.appendChild(doc.createTextNode(val));
        rootElement.appendChild(cmdE);

        DOMSource source = new DOMSource(doc);
        StringWriter sw = new StringWriter();
        StreamResult result = new StreamResult(sw);
        TransformerFactory transformerFactory = TransformerFactory.newInstance();
        Transformer transformer = transformerFactory.newTransformer();
        transformer.transform(source, result);
        sendPacket(server, sw.toString());
    }

    private static void sendCmd(String server, String cmd, String val, String mag) throws Exception {
        if (!cmd.equals("unit"))
            throw new IllegalArgumentException();

        DocumentBuilderFactory dbFactory = DocumentBuilderFactory.newInstance();
        DocumentBuilder dbuilder = dbFactory.newDocumentBuilder();
        Document doc = dbuilder.newDocument();

        Element rootElement = doc.createElement("control");
        doc.appendChild(rootElement);

        Element cmdE = doc.createElement(cmd);
        cmdE.appendChild(doc.createTextNode(val));
        rootElement.appendChild(cmdE);

        Attr magA = doc.createAttribute("magnitude");
        magA.setValue(mag);
        cmdE.setAttributeNode(magA);

        DOMSource source = new DOMSource(doc);
        StringWriter sw = new StringWriter();
        StreamResult result = new StreamResult(sw);
        TransformerFactory transformerFactory = TransformerFactory.newInstance();
        Transformer transformer = transformerFactory.newTransformer();
        transformer.transform(source, result);
        sendPacket(server, sw.toString());
    }

    public static void main(String[] args) {
        System.out.println("pcc practica2 cliente mxn");

        String ifname = "lo";
        for (int i = 0; i < args.length; i++) {
            if (args[i].equals("-i")) {
                if (args.length < 3)
                    usage();
                ifname = args[i+1];
                i++;
            } else if (args[i].equals("listen")) {
                try {
                    Client c = new Client(ifname);
                    Thread st = new Thread(c);
                    st.start();
                    st.join();
                } catch (Exception e) {
                    e.printStackTrace();
                }
            } else if (args[i].equals("cmd")) {
                if (args.length - i < 3)
                    usage();

                try {
                    if (args[i+2].equals("format")) {
                        sendCmd(args[i+1], "format", args[i+3]);
                        break;
                    } else if (args[i+2].equals("frequency")) {
                        sendCmd(args[i+1], "frequency", args[i+3]);
                        break;
                    } else if (args[i+2].equals("enable")) {
                        sendCmd(args[i+1], "enable", args[i+3]);
                        break;
                    } else if (args[i+2].equals("unit") && ((args.length - i) == 5)) {
                        sendCmd(args[i+1], "unit", args[i+3], args[i+4]);
                        break;
                    } else
                        usage();
                } catch (Exception e) {
                    e.printStackTrace();
                    System.exit(1);
                }

            } else
                usage();
        }
    }
}


