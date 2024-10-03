package geometria;

public record Point(int x, int y) {
    public Point(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public Point(Point p) {
        this(p.x(), p.y());
    }
}
