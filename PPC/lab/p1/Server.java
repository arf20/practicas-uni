import java.io.*;
import java.net.*;
import java.util.*;
import org.json.*;
import javax.net.ssl.*;
import java.security.*;

/**
 * Carrito de la compra
 *
 * GET /
 * Index
 *
 * GET /product/html/<id>
 * GET /product/json/<id>
 * Consulta de producto
 *
 * GET /cart/html
 * GET /cart/json
 * Consulta de carrito
 *
 * POST /cart/<id>
 * Incorporación de producto
 *
 * DELETE /cart/<id>
 * Eliminación de producto
 */

class Product {
    public String id;
    public String name;
    public String desc;
    public float price;

    public Product(String id, String name, String desc, float price) {
        this.id = id;
        this.name = name;
        this.desc = desc;
        this.price = price;
    }
}

class Database {
    private HashMap<String, Product> store = new HashMap<String, Product>();

    public Database() {
        store.put("canon50e", new Product("canon50e", "Canon EOS 50E", "", 80.0f));
        store.put("canon300d", new Product("canon300d", "Canon EOS 300D", "", 60.0f));
        store.put("casiozs150", new Product("casiozs150", "Casio ZS-150", "", 10.0f));
        store.put("olympusepl7", new Product("olympusepl7", "Olympus Pen E-PL7", "", 500.0f));
        store.put("canon77d", new Product("canon77d", "Canon EOS 77D", "", 300.0f));
        store.put("fed2", new Product("fed2", "FED-2c", "", 20.0f));
    }

    public Product get(String key) {
        return store.get(key);
    }

    public Collection<Product> list() {
        return store.values();
    }
}

class Cart {
    private HashSet<Product> cart = new HashSet<Product>();

    public Cart() {
    
    }

    public Cart(String fromCookie, Database db) {
        if (fromCookie == null)
            return;

        for (String id : fromCookie.split("\\$")) {
            if (!id.equals(""))
                cart.add(db.get(id));
        }
    }

    public void add(Product p) {
        cart.add(p);
    }

    public void delete(Product p) {
        cart.remove(p);
    }
    
    public Set<Product> list() {
        return Collections.unmodifiableSet(cart);
    }

    public String toJSON() {
        JSONArray a = new JSONArray();
        for (Product p : cart) {
            JSONObject o = new JSONObject();
            o.put("id", p.id);
            o.put("name", p.name);
            o.put("price", p.price);
            a.put(o);
        }
        return a.toString();
    }
    
    public String toCookie() {
        StringBuilder sb = new StringBuilder();
        for (Product p : cart) {
            sb.append(p.id);
            sb.append("$");
        }
        if (cart.size() > 0)
            sb.deleteCharAt(sb.length()-1);
        return sb.toString();
    }
}

class ServerThread implements Runnable {
    private Socket s;
    private Database db;

    public ServerThread(Socket socket, Database db) {
        this.s = socket;
        this.db = db;
    }

    private void serve(String method, String path, List<String[]> headers, Map<String, String> cookies, List<String> body) throws IOException {
        PrintWriter out = new PrintWriter(s.getOutputStream(), true);
        Cart cart = new Cart(cookies.get("cart"), db);
        path = path.replace("?", "");

        if (method.equals("GET") && path.equals("/")) {
            out.print("HTTP/1.1 200 OK\r\n");
            out.print("Connection: close\r\n");
            out.print("Server: PCC java shit/1\r\n");
            out.print("Content-Type: text/html; charset=utf8\r\n\r\n");

            out.print("<html><head><title>PCC cosa</title></head><body>\r\n");
            out.print("<h1>PCC servidor tienda</h1>\r\n");

            out.print("<h2>Catálogo</h2>");
            out.print("<table><tr><th>Producto</th><th>Precio</th><th>Accion</th></tr>\r\n");
            for (Product p : db.list()) {
                out.print("<tr><td><a href=\"/product/html/" + p.id + "\">" + p.name + "</td><td>" + p.price +
                        "</td><td><button type=\"button\" onclick=\"" +
                   "event.preventDefault(); (async() => { const res = window.fetch(location.protocol + '//' + location.host + '/cart/" + p.id + "', { method: 'post' }).then(res => { console.log(res); location.reload(); }); })()\">Añadir</button></td></tr>");
            }
            out.print("</table>");

            out.print("<h2>Cesta</h2>\r\n");

            System.out.println(cart);
            out.print("<table><tr><th>Producto</th><th>Precio</th><th>Accion</th></tr>\r\n");
            for (Product p : cart.list()) {
                out.print("<tr><td><a href=\"/product/html/" + p.id + "\">" + p.name + "</td><td>" + p.price + "</td><td><button type=\"button\" onclick=\"" +
                   "event.preventDefault(); (async() => { const res = window.fetch(location.protocol + '//' + location.host + '/cart/" + p.id + "', { method: 'delete' }).then(res => { console.log(res); location.reload(); }); })()\">Eliminar</button></td></tr>");
                // location.reload();
            }
            out.print("</table>");

            out.print("</body></html>\r\n");
        } else if (method.equals("GET") && path.startsWith("/product/html/")) {
            Product p = db.get(path.substring(14));
            if (p == null) {
                out.print("HTTP/1.1 404 Not Found\r\n");
                out.print("Connection: close\r\n");
                out.print("Server: PCC java shit/1\r\n");
            } else {
                out.print("HTTP/1.1 200 OK\r\n");
                out.print("Connection: close\r\n");
                out.print("Server: PCC java shit/1\r\n");
                out.print("Content-Type: text/html; charset=utf8\r\n\r\n");
                out.print("<html><head><title>PCC cosa</title></head><body><h1>" + p.name + "</h1><p>" + p.desc + "</p><i>" +p.price + "€</i></body></html>\r\n");
            }
        } else if (method.equals("GET") && path.startsWith("/product/json/")) {
            Product p = db.get(path.substring(14));
            if (p == null) {
                out.print("HTTP/1.1 404 Not Found\r\n");
                out.print("Connection: close\r\n");
                out.print("Server: PCC java shit/1\r\n");
            } else {
                JSONObject o = new JSONObject();
                o.put("id", p.id);
                o.put("name", p.name);
                o.put("desc", p.desc);
                o.put("price", p.price);

                out.print("HTTP/1.1 200 OK\r\n");
                out.print("Connection: close\r\n");
                out.print("Server: PCC java shit/1\r\n");
                out.print("Content-Type: text/json; charset=utf8\r\n\r\n");
                out.print(o.toString());
            }
        } else if (method.equals("POST") && path.startsWith("/cart/")) {
            String id = path.substring(6);

            Product p = db.get(id);
            if (p == null) {
                out.print("HTTP/1.1 404 Not Found\r\n");
                out.print("Connection: close\r\n");
                out.print("Server: PCC java shit/1\r\n");
            } else {
                cart.add(p);
                out.print("HTTP/1.1 201 Created\r\n");
                out.print("Connection: close\r\n");
                out.print("Server: PCC java shit/1\r\n");
                out.print("Location: /\r\n");
                out.print("Set-Cookie: cart=" + cart.toCookie() + "; Path=/\r\n");
            }
        } else if (method.equals("DELETE") && path.startsWith("/cart/")) {
            String id = path.substring(6);

            Product p = db.get(id);
            if (p == null) {
                out.print("HTTP/1.1 404 Not Found\r\n");
                out.print("Connection: close\r\n");
                out.print("Server: PCC java shit/1\r\n");
            } else {
                cart.delete(p);
                out.print("HTTP/1.1 200 OK\r\n");
                out.print("Connection: close\r\n");
                out.print("Server: PCC java shit/1\r\n");
                out.print("Set-Cookie: cart=" + cart.toCookie() + "; Path=/\r\n");
            }
        } else if (method.equals("GET") && path.startsWith("/cart/json")) {
            out.print("HTTP/1.1 200 OK\r\n");
            out.print("Connection: close\r\n");
            out.print("Server: PCC java shit/1\r\n");
            out.print("Set-Cookie: cart=" + cart.toCookie() + "; Path=/\r\n");
            out.print("Content-Type: text/json; charset=utf8\r\n\r\n");
            out.print(cart.toJSON());
        } else {
            out.print("HTTP/1.1 404 Not Found\r\n");
            out.print("Connection: close\r\n");
            out.print("Server: PCC java shit/1\r\n");
        }

        out.flush();
        s.close();
    }

    @Override
    public void run() {
        try {
            // create reader and writer
            BufferedReader in = new BufferedReader(new InputStreamReader(s.getInputStream()));

            // parse request and print
            String[] requestLine = in.readLine().split(" ");
            String method = requestLine[0];
            String path = requestLine[1];
            String httpVer = requestLine[2];

            System.out.println(Arrays.toString(requestLine));

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
            //for (String[] h : headers) {
            //    System.out.println(h[0] + ": " + h[1]);
            //}
            //for (String s : body) {
            //    System.out.println(s);
            //}

            HashMap<String, String> cookies = new HashMap<String, String>();
            for (String[] h : headers) {
                //System.out.println(h[0] + ": " + h[1]);
                if (h[0].equals("Cookie")) {
                    String[] resCookies = h[1].split("\\s*;\\s*");
                    for (String c : resCookies) {
                        String[] p = c.split("\\s*=\\s*", 2);
                        if (p.length == 2)
                            cookies.put(p[0], p[1]);
                        //System.out.println(p[0] + "=" + p[1]);
                    }
                }
            }

            // send response
            serve(method, path, headers, cookies, body);
            System.out.println();
            System.out.println();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}


class TLSServer implements Runnable {
    private Database db;
    private SSLServerSocket serverSocket;

    public TLSServer(Database db) throws IOException {
        this.db = db;

        char[] password = "ppcppc".toCharArray();

        // TLS stuff
        try {
            KeyStore keyStore = KeyStore.getInstance("JKS");

            try (FileInputStream fis = new FileInputStream("servidor.ks")) {
                keyStore.load(fis, password);
            }

            KeyManagerFactory kmf = KeyManagerFactory.getInstance("SunX509");
            kmf.init(keyStore, password);

            SSLContext sslContext = SSLContext.getInstance("TLS");
            sslContext.init(kmf.getKeyManagers(), null, null);
            SSLServerSocketFactory ssf = sslContext.getServerSocketFactory();

            serverSocket = (SSLServerSocket) ssf.createServerSocket(8443);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    @Override
    public void run() {
        while (true) {
            try {
                SSLSocket c = (SSLSocket)serverSocket.accept();
                System.out.println("Client connected.");

                ServerThread st = new ServerThread(c, db);
                Thread t = new Thread(st);
                t.start();
            } catch (IOException e) { e.printStackTrace(); }
        }
    }
}

class Server implements Runnable {
    private Database db;
    private ServerSocket ss;

    public Server(Database db) throws IOException {
        this.db = db;

        ss = new ServerSocket(8080);
    }

    @Override
    public void run() {
        while (true) {
            try {
                Socket c = ss.accept();
                System.out.println("client accepted");

                ServerThread st = new ServerThread(c, db);
                Thread t = new Thread(st);
                t.start();
            } catch (IOException e) { e.printStackTrace(); }
        }
    }


    public static void main(String[] args) {
        System.out.println("http server");

        Database db = new Database();

        try {
            Server server = new Server(db);
            TLSServer tlsserver = new TLSServer(db);

            Thread st = new Thread(server);
            Thread tlsst = new Thread(tlsserver);

            st.start();
            tlsst.start();

            st.join();
            tlsst.join();

        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}

