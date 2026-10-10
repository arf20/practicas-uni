import java.io.*;
import java.net.*;
import java.util.*;
import org.json.*;

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
    private Set<Product> cart;

    public Cart(String fromCookie, Database db) {
        for (String id : fromCookie.split(",")) {
            cart.add(db.get(id));
        }
    }

    public void add(Product p) {
        cart.add(p);
    }

    public void delete(Product p) {
        cart.
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
        if (method.equals("GET") && path.equals("/")) {
            out.print("HTTP/1.1 200 OK\r\n");
            out.print("Connection: close\r\n");
            out.print("Server: PCC java shit/1\r\n");
            out.print("Set-Cookie: test=a;test2=b\r\n");
            out.print("Content-Type: text/html\r\n\r\n");
            out.print("<html><head><title>PCC cosa</title></head><body>\r\n");
            out.print("<h1>PCC servidor tienda</h1>");
            out.print("<form>\r\n");
            out.print("<table><tr><th>Producto</th><th>Precio</th><th>Accion</th></tr>\r\n");

            for (Product p : db.list()) {
                out.print("<tr><td><a href=\"/product/html/" + p.id + "\">" + p.name + "</td><td>" + p.price + "</td><td><button formaction=\"/cart/" + p.id + "\">Añadir</button></td></tr>");
            }

            out.print("</form></table></body></html>\r\n");
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
                out.print("Content-Type: text/html\r\n\r\n");
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
                out.print("Content-Type: text/json\r\n\r\n");
                out.print(o.toString());
            }
        } else if (method.equals("POST") && path.startsWith("/cart/")) {
            String id = path.substring(6).replace("?", "");

            

            out.print("HTTP/1.1 200 OK\r\n");
            out.print("Connection: close\r\n");
            out.print("Server: PCC java shit/1\r\n");
            out.print("Set-Cookie");

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
                System.out.println(h[0] + ": " + h[1]);
                if (h[0].equals("Set-Cookie")) {
                    String[] resCookies = h[1].split("\\s*;\\s*");
                    for (String c : resCookies) {
                        String[] p = c.split("\\s*=\\s*");
                        cookies.put(p[0], p[1]);
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


class Server {
    private Server() throws IOException {
        ServerSocket ss = new ServerSocket(8080);
        Database db = new Database();

        while (true) {
            Socket c = ss.accept();
            System.out.println("client accepted");

            ServerThread st = new ServerThread(c, db);
            Thread t = new Thread(st);
            t.start();
        }
    }


    public static void main(String[] args) {
        System.out.println("http server");

        try { new Server(); }
        catch (IOException e) {
            e.printStackTrace();
        }
    }
}

