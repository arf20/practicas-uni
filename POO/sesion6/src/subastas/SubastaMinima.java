package subastas;

import java.util.ArrayList;

public class SubastaMinima extends Subasta {
    private int pujaMinima;
    public SubastaMinima(String nombre, String propietario, int pujaMinima) {
        super(nombre, propietario);
        this.pujaMinima = pujaMinima;
    }

    public boolean ejecutar() {
        if (pujas.isEmpty() || !abierta || (getPujaMayor() < pujaMinima))
            return false;

        abierta = false;
        return true;
    }

    public int getSubastaMinima() {
        return pujaMinima;
    }

    public void setSubastaMinima(int pujaMinima) {
        this.pujaMinima = pujaMinima;
    }
}
