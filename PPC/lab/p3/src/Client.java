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
import javax.net.ssl.*;
import java.security.*;

class WebServeThread implements Runnable {
    private Socket sock;
    private Broker broker;

    public WebServeThread(Socket sock, Broker broker) {
        this.sock = sock;
        this.broker = broker;
    }

    private String response(String status, String mimetype, String body) {
        StringBuilder sb = new StringBuilder();
        sb.append("HTTP/1.1 " + status + "\n");
        sb.append("Connection: close\n");
        sb.append("Server: ppc p3\n");
        if (mimetype != null)
            sb.append("Content-Type: " + mimetype + "\n\n");
        if (body != null)
            sb.append(body);
        sb.append("\n");
        return sb.toString().replaceAll("\n", "\r\n");
    }

    private void serve(String method, String path, List<String[]> headers, List<String> body) throws Exception {
        if (method.equals("GET") && path.equals("/")) {
            StringBuilder sb = new StringBuilder();
            sb.append("HTTP/1.1 301 Moved Permanently\n");
            sb.append("Connection: close\n");
            sb.append("Server: ppc p3\n");
            sb.append("Location: /index.html\n");
            String response = sb.toString().replaceAll("\n", "\r\n");
            sock.getOutputStream().write(response.getBytes());
            System.out.println("[site]  301 OK [" + response.length() + "]");
        } else if (method.equals("GET") && path.equals("/index.html")) {
            StringBuilder sb = new StringBuilder();
            sb.append("<!DOCTYPE html>\n<html>\n");
            sb.append(" <head>\n");
            sb.append("  <title>ppc</title>\n");
            sb.append(" </head>\n");
            sb.append(" <body>\n");
            sb.append("  <h1>PPC Broker</h1>\n");
            sb.append("  <h2><a href=\"/data.html\">Mostrar datos</a></h1>\n");
            sb.append("  <h2><a href=\"/api/\">API REST</a></h1>\n");
            sb.append(" </body>\n");
            sb.append("</html>");

            String response = response("200 OK", "text/html", sb.toString());
            sock.getOutputStream().write(response.getBytes());
            System.out.println("[site]  200 OK [" + response.length() + "]");
        } else if (method.equals("GET") && path.equals("/data.html")) {
            // generate html
            StringBuilder sb = new StringBuilder();
            sb.append("<!DOCTYPE html>\n<html>\n");
            sb.append(" <head>\n");
            sb.append("  <title>ppc</title>\n");
            sb.append(" </head>\n");
            sb.append(" <body>\n");
            sb.append("  <h1>PPC Broker</h1>\n");


            for (Map.Entry<String, Set<Map.Entry<String, Datapoint>>> e : broker.getSourcesNow()) {
                sb.append("  <h2>" + e.getKey() + "</h2>\n");
                sb.append("  <table>\n");
                sb.append("   <tr><th>Magnitude</th><th>Value</th><th>Unit</th></tr>\n");
                for (Map.Entry<String, Datapoint> ee : e.getValue()) {
                    sb.append("   <tr>\n");
                    sb.append("    <td>" + ee.getValue().mag + "</td>\n");
                    sb.append("    <td>" + ee.getValue().val+ "</td>\n");
                    sb.append("    <td>" + ee.getValue().unit + "</td>\n");
                    sb.append("   </tr>\n");
                }
                sb.append("  </table>\n");
            }

            sb.append(" </body>\n");
            sb.append("</html>");

            String response = response("200 OK", "text/html", sb.toString());
            sock.getOutputStream().write(response.getBytes());
            System.out.println("[site]  200 OK [" + response.length() + "]");
        } else if (method.equals("GET") && path.equals("/api/")) {
            // generate json
            ByteArrayOutputStream baos = new ByteArrayOutputStream();
            JsonWriter writer = new JsonWriter(new OutputStreamWriter(baos, "UTF-8"));

            writer.beginArray();

            for (Map.Entry<String, Set<Map.Entry<String, Datapoint>>> e : broker.getSourcesNow()) {
                writer.beginObject();
                writer.name("source").value(e.getKey());
                writer.name("measurements");
                writer.beginArray();
                for (Map.Entry<String, Datapoint> ee : e.getValue()) {
                    writer.beginObject();
                    writer.name("magnitude").value(ee.getValue().mag);
                    writer.name("value").value(ee.getValue().val);
                    writer.name("unit").value(ee.getValue().unit);
                    writer.endObject();
                }
                writer.endArray();
                writer.endObject();
            }

            writer.endArray();
            writer.close();

            String response = response("200 OK", "application/json", baos.toString());
            sock.getOutputStream().write(response.getBytes());
            System.out.println("[api]  200 OK [" + response.length() + "]");
        } else {
            String response = response("404 Not Found", null, null);
            sock.getOutputStream().write(response.getBytes());
            System.out.println("[web]  404 Not Found [" + response.length() + "]");
        }
    }

    @Override
    public void run() {
        try {
            // create reader and writer
            BufferedReader in = new BufferedReader(new InputStreamReader(sock.getInputStream()));

            // parse request
            String[] requestLine = in.readLine().split(" ");
            String method = requestLine[0];
            String path = requestLine[1];
            String httpVer = requestLine[2];

            // parse headers
            ArrayList<String[]> headers = new ArrayList<String[]>();
            String header = null;
            while ((header = in.readLine()) != null) {
                if (header.equals(""))
                    break;
                headers.add(header.split("\\s*:\\s*", 2));
            }

            // parse body
            ArrayList<String> body = new ArrayList<String>();
            if (method == "POST") {
                String bodyLine = null;
                while ((bodyLine = in.readLine()) != null) {
                    if (bodyLine.equals(""))
                        break;
                    body.add(bodyLine);
                }
            }

            // print them
            System.out.println("[web] " + method + " " + path + " " + httpVer + " -> ");

            // send response
            serve(method, path, headers, body);

            sock.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}

class HTTPSListener implements Runnable {
    private final int port = 8443;
    
    private SSLServerSocket ss;
    private Broker broker;

    public HTTPSListener(Broker broker) throws Exception {
        this.broker = broker;
        char[] password = "ppcppc".toCharArray();

        // TLS stuff
        KeyStore keyStore = KeyStore.getInstance("JKS");

        try (FileInputStream fis = new FileInputStream("servidor.ks")) {
            keyStore.load(fis, password);
        }

        KeyManagerFactory kmf = KeyManagerFactory.getInstance("SunX509");
        kmf.init(keyStore, password);

        SSLContext sslContext = SSLContext.getInstance("TLS");
        sslContext.init(kmf.getKeyManagers(), null, null);
        SSLServerSocketFactory ssf = sslContext.getServerSocketFactory();

        ss = (SSLServerSocket)ssf.createServerSocket(8443);
        ss.setNeedClientAuth(true);
    }

    @Override
    public void run() {
        while (true) {
            try {
                SSLSocket c = (SSLSocket)ss.accept();
                System.out.println("[https] client accepted: " + c.getInetAddress());

                WebServeThread st = new WebServeThread(c, broker);
                Thread t = new Thread(st);
                t.start();
            } catch (IOException e) { e.printStackTrace(); }
        }
    }
}

class HTTPListener implements Runnable {
    private final int port = 8080;

    private ServerSocket ss;
    private Broker broker;

    public HTTPListener(Broker broker) throws IOException {
        this.broker = broker;
        ss = new ServerSocket(port);
    }

    @Override
    public void run() {
        while (true) {
            try {
                Socket c = ss.accept();
                System.out.println("[http] client accepted: " + c.getInetAddress());

                WebServeThread st = new WebServeThread(c, broker);
                Thread t = new Thread(st);
                t.start();
            } catch (IOException e) { e.printStackTrace(); }
        }
    }
}

class Datapoint {
    public String mag;
    public float val;
    public String unit;

    public Datapoint(String mag, float val, String unit) {
        this.mag = mag;
        this.val = val;
        this.unit = unit;
    }

    public String toString() {
        return mag + ": " + val + " " + unit;
    }
}

class Broker {
    // store last discovered datapoints
    HashMap<String, HashMap<String, Datapoint>> series;

    HTTPListener httpl;
    //HTTPSListener httpsl = new HTTPSListener(this);

    public Broker() {
        series = new HashMap<String, HashMap<String, Datapoint>>();

        try {
            httpl = new HTTPListener(this);
            Thread httpt = new Thread(httpl);
            httpt.start();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    void pushDatapoint(String source, String mag, float val, String unit) {
        HashMap<String, Datapoint> sourceSeries = series.get(source);

        if (sourceSeries != null) {
            // puts if mag does not exist or replaces if mag does exist
            sourceSeries.put(mag, new Datapoint(mag, val, unit));
        } else {
            // new source
            sourceSeries = new HashMap<String, Datapoint>();
            sourceSeries.put(mag, new Datapoint(mag, val, unit));
            series.put(source, sourceSeries);
        }
    }

    Set<Map.Entry<String, Set<Map.Entry<String, Datapoint>>>> getSourcesNow() {
        HashMap<String, Set<Map.Entry<String, Datapoint>>> views = new HashMap<>();

        for (Map.Entry<String, HashMap<String, Datapoint>> e : series.entrySet()) {
            views.put(e.getKey(), e.getValue().entrySet());
        }
        
        return views.entrySet();
    }
}

class Client implements Runnable {
    private static final int port = 6767;
    private static final InetSocketAddress group = new InetSocketAddress("ff12::cafe", port);

    private MulticastSocket socket;
    private final NetworkInterface netif;

    private DocumentBuilder dbuilder;
    private Validator validator;
    private Transformer transformer;

    private Broker broker;

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

        broker = new Broker();
    }

    private void sendUnicast(String host, String msg) throws IOException {
        byte[] buf = msg.getBytes();
        DatagramPacket p = new DatagramPacket(buf, buf.length, InetAddress.getByName(host), port);
        socket.send(p);
    }

    private void decodeXML(byte[] bytes) {
        Element root;

        try {
            Document document = dbuilder.parse(new ByteArrayInputStream(bytes));
            document.getDocumentElement().normalize();
            root = document.getDocumentElement();
            validator.validate(new DOMSource(root));
            System.out.println("[client]  xml good");

            NodeList nlserver = root.getElementsByTagName("server");
            NodeList nlmeas = root.getElementsByTagName("measurement");

            String server = nlserver.item(0).getTextContent();

            System.out.println("[client]  " + server + ":");
            
            for (int i = 0; i < nlmeas.getLength(); i++) {
                String mag = nlmeas.item(i).getAttributes().getNamedItem("magnitude").getTextContent();
                String val = nlmeas.item(i).getTextContent();
                String unit = nlmeas.item(i).getAttributes().getNamedItem("unit").getTextContent();
                System.out.println("[client]   " + mag + ": " + Float.parseFloat(val) + " " + unit);

                broker.pushDatapoint(server, mag, Float.parseFloat(val), unit);
            }

        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    private void decodeJSON(String s) {
        JsonParser parser = new JsonParser();
        JsonObject r = parser.parse(s).getAsJsonObject();

        String server = r.get("server").getAsString();
        System.out.println("[client]  " + server + ":");

        JsonArray meas = r.getAsJsonArray("measurements");

        for (JsonElement e : meas) {
            JsonObject m = e.getAsJsonObject();
            String mag = m.get("magnitude").getAsString();
            String val = m.get("value").getAsString();
            String unit = m.get("unit").getAsString();
            System.out.println("[client]   " + mag + ": " + val + " " + unit);

            broker.pushDatapoint(server, mag, Float.parseFloat(val), unit);
        }
    }

    @Override
    public void run() {
        byte[] buf = new byte[1024];
        while (true) {
            DatagramPacket p = new DatagramPacket(buf, buf.length);
            try { socket.receive(p); }
            catch (IOException e) { e.printStackTrace(); }
            String s = new String(p.getData(), 0, p.getLength());
            System.out.print("[client] message from " + p.getAddress() + ": ");

            if (s.startsWith("Content-Type: application/xml")) {
                System.out.println("xml[" + p.getLength() + "]");
                decodeXML(s.substring(33).getBytes());
            } else if (s.startsWith("Content-Type: application/json")) {
                System.out.println("json[" + p.getLength() + "]");
                decodeJSON(s.substring(34));
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


