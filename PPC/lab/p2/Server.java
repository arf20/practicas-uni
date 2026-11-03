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
import javax.xml.validation.*;
import org.xml.sax.*;
import javax.xml.parsers.*;

class Server implements Runnable {
    private MulticastSocket socket;
    private final InetAddress group = InetAddress.getByName("ff12::caca");;
    private final int port = 6767;
    private int periodms = 1000;

    DocumentBuilder dbuilder;
    Validator validator;


    public Server(String ifname) throws IOException, ParserConfigurationException, SAXException {
        socket = new MulticastSocket(port);
        socket.setReuseAddress(true);
        socket.setNetworkInterface(NetworkInterface.getByName(ifname));

        DocumentBuilderFactory dbFactory = DocumentBuilderFactory.newInstance();
        dbuilder = dbFactory.newDocumentBuilder();

        SchemaFactory sfactory = SchemaFactory.newInstance(XMLConstants.W3C_XML_SCHEMA_NS_URI);
        Source schemaFile = new StreamSource(new File("control.xsd"));
        Schema schema = sfactory.newSchema(schemaFile);
        validator = schema.newValidator();
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

    public void sendLoop() {
        while (true) {
            try {
                sendBroadcast("test");
                System.out.println("sent");
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
            Server s;
            if (args.length > 0)
                s = new Server(args[0]);
            else
                s =  new Server("lo");

            Thread st = new Thread(s);
            st.start();
            s.sendLoop();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}

