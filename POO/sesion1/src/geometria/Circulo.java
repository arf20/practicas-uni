package geometria;

import java.lang.Math;
import geometria.Punto;

public class Circulo {
    private Punto centro;
    private int radio;

    public static final Punto ORIGEN_COORDENADAS = new Punto(0, 0);
    public static final int RADIO_POR_DEFECTO = 5;

    public Circulo(Punto centro, int radio) {
        this.centro = new Punto(centro);
        this.radio = radio;
    }

    public Circulo() {
        this(ORIGEN_COORDENADAS, RADIO_POR_DEFECTO);
    }

    public Punto getCentro() {
        return new Punto(centro);
    }

    public int getRadio() {
        return radio;
    }

    public double perimetro() {
        return 2 * Math.PI * radio;
    }

    public void desplazar(int dx, int dy) {
        centro = centro.desplazar(dx, dy);
    }

    public void escalar(double f) {
        radio = (int)((double)radio * f);
    }
}
