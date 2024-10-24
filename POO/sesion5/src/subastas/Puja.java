package subastas;

public class Puja {
    final private String pujador;
    final private double cantidad;

    public Puja(String pujador, double cantidad) {
        this.pujador = pujador;
        this.cantidad = cantidad;
    }

    String getPujador() {
        return pujador;
    }

    double getCantidad() {
        return cantidad;
    }
}
