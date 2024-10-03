package geometria;

public class Punto {
    private int x, y;

    public Punto(int x, int y) {
        this.x = x; this.y = y;
    }

    public Punto() {
        this(0, 0);
    }

    public Punto(Punto p) {
        this(p.x, p.y);
    }

    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }

    public Punto desplazar(int dx, int dy) {
        return new Punto(x + dx, y + dy);
    }
}
