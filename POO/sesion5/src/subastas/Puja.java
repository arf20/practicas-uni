package subastas;

public class Puja {
    private String pujador;
    private double cantidad;

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
