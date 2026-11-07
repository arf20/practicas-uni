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
    private MulticastSocket socket;
    private final int port = 6767;
    private final InetSocketAddress group = new InetSocketAddress("ff12::caca", port);;
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
            System.out.println("recv: " + s);


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
        }
    }


    public static void main(String[] args) {
        System.out.println("pcc practica2 cliente mxn");

        try {
            Client c;
            if (args.length > 0)
                c = new Client(args[0]);
            else
                c = new Client("lo");

            Thread st = new Thread(c);
            st.start();
            st.join();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}


