import java.io.*;
import java.net.*;
import java.util.*;
import org.json.*;

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

    public String toString() {
        return id + ": [" + name + "] " + desc + " $" + price;
    }
}

class RequestResult {
    int status;
    String body;

    public RequestResult(int status, String body) {
        this.status = status;
        this.body = body;
    }
}

class Client {

    private static RequestResult doRequest(Map<String, String> cookies, String host, int port, String method, String url) throws IOException {
        // open socket, connect
        Socket s = new Socket(host, port);
        PrintWriter out = new PrintWriter(s.getOutputStream(), true);
        // send request
        out.println(method + " " + url + " HTTP/1.1");
        out.println("Host: " + host + ":" + port);
        out.println("User-Agent: pcc-client");
        out.println("Accept: */*");
        for (Map.Entry<String, String> e : cookies.entrySet())
            out.println("Cookie: " + e.getKey() + "=" + e.getValue());
        out.println("");

        // read response and parse headers and body
        BufferedReader in = new BufferedReader(new InputStreamReader(s.getInputStream()));

        String[] responseLine = in.readLine().split(" ", 2);
        String httpVer = responseLine[0];
        String status = responseLine[1];

        //System.out.println(Arrays.toString(responseLine));

        ArrayList<String[]> headers = new ArrayList<String[]>();
        String header = null;
        while ((header = in.readLine()) != null) {
            if (header.equals(""))
                break;
            headers.add(header.split("\\s*:\\s*", 2));
        }

        String body = "";
        String bodyLine = null;
        while ((bodyLine = in.readLine()) != null) {
            if (bodyLine.equals(""))
                break;
            body += bodyLine;
        }

        // print headers and set cookies, print body
        for (String[] h : headers) {
            //System.out.println(h[0] + ": " + h[1]);
            if (h[0].equals("Set-Cookie")) {
                String[] cookiecomp = h[1].split("\\s*;\\s*");
                String[] c = cookiecomp[0].split("\\s*=\\s*");
                cookies.put(c[0], c.length > 1 ? c[1] : "");
            }
        }

        //System.out.print(body);

        // close socket
        s.close();

        return new RequestResult(Integer.parseInt(status.split(" ")[0]), body);
    }


    public static void main(String[] args) {
        System.out.println("PCC Java Client");

        String host = "localhost";
        int port = 8080;

        try {
            // load cookies
            HashMap<String, String> cookies = new HashMap<String, String>();
            File cookieLoad = new File("cookies.txt");
            try (Scanner s = new Scanner(cookieLoad)) {
                while (s.hasNextLine()) {
                    String[] p = s.nextLine().split("=");
                    if (p.length > 1)
                        cookies.put(p[0], p[1]);
                }
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }

            Scanner s = new Scanner(System.in);
            while (true) {
                System.out.print("ppc> ");
                String cmd = s.nextLine();

                if (cmd.equals("cat")) {
                    RequestResult rs = doRequest(cookies, host, port, "GET", "/json");
                    if (rs.status != 200) {
                        System.out.println("error: " + rs.status);
                        break;
                    }

                    JSONArray a = new JSONArray(rs.body);
                    for (int i = 0; i < a.length(); i++) {
                        JSONObject o = a.getJSONObject(i);
                        Product p = new Product(o.getString("id"), o.getString("name"), o.getString("desc"), o.getFloat("price"));
                        System.out.println(p.toString());
                    }

                } else if (cmd.startsWith("add")) {
                    String id = cmd.split(" ")[1];
                    RequestResult rs = doRequest(cookies, host, port, "POST", "/cart/" + id);
                    if (rs.status != 200) {
                        System.out.println("error: " + rs.status);
                        break;
                    }
                    
                } else if (cmd.startsWith("cart")) {
                    RequestResult rs = doRequest(cookies, host, port, "GET", "/cart/json");

                    if (rs.status != 200) {
                        System.out.println("error: " + rs.status);
                        break;
                    }

                    JSONArray a = new JSONArray(rs.body);
                    float total = 0.0f;
                    for (int i = 0; i < a.length(); i++) {
                        JSONObject o = a.getJSONObject(i);
                        Product p = new Product(o.getString("id"), o.getString("name"), "", o.getFloat("price"));
                        System.out.println(p.toString());
                        total += o.getFloat("price");
                    }
                    System.out.println("total: $" + total);

                } else if (cmd.startsWith("del")) {
                    String id = cmd.split(" ")[1];
                    RequestResult rs = doRequest(cookies, host, port, "DELETE", "/cart/" + id);
                    if (rs.status != 200) {
                        System.out.println("error: " + rs.status);
                        break;
                    }
                    
                } else if (cmd.equals("exit")) {
                    break;
                } else {
                    System.out.println("no such command");
                }
            }

            FileWriter cookieStore = new FileWriter("cookies.txt");
            for (Map.Entry<String, String> c : cookies.entrySet())
                cookieStore.write(c.getKey() + "=" + c.getValue() + "\n");
            cookieStore.close();

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}

