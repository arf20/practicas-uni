package geometria;

import java.lang.Math;

public class Punto {
    private int x, y;

    public Punto(int _x, int _y) {
        x = _x; y = _y;
    }

    public Punto() {
        this(0, 0);
    }

    public Punto(Punto _p) {
        this(_p.x, _p.y);
    }

    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }

    public void setX(int _x) {
        x = _x;
    }

    public void setY(int _y) {
        y = _y;
    }

    public void desplazar(int dx, int dy) {
        x += dx;
        y += dy;
    }

    public void desplazar(Direction d) {
        switch (d) {
            case ARRIBA: y -= 1; break;
            case ABAJO: y += 1; break;
            case IZQUIERDA: x -= 1; break;
            case DERECHA: y += 1; break;
        }
    }

    public double distancia(Punto p) {
        return Math.sqrt(Math.pow(p.getX() - this.getX(), 2) + Math.pow(p.getY() - this.getY(), 2));
    }
}
