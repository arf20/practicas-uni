package subastas;

import java.util.ArrayList;

public class Subasta {
    protected String producto;
    protected String propietario;
    protected boolean abierta;
    protected ArrayList<Puja> pujas;

    public Subasta(String producto, String propietario) {
        this.producto = producto;
        this.propietario = propietario;

        abierta = true;
        pujas = new ArrayList<Puja>();
    }

    public boolean pujar(String usuario, double puja) {
        if (!abierta || (propietario == usuario) || (puja <= getPujaMayor()))
            return false;
        
        pujas.add(new Puja(usuario, puja));
        return true;
    }

    public boolean pujar(String usuario) {
        return pujar(usuario, getPujaMayor() + 1.0);
    }

    public boolean ejecutar() {
        if (pujas.isEmpty() || !abierta) return false;

        abierta = false;
        return true;
    }

    public double getPujaMayor() {
        double c = 0.0;
        for (Puja e : pujas) {
            if (e.cantidad() > c) 
                c = e.cantidad();
        }

        return c;
    }

    public String getProducto() {
        return producto;
    }

    public String getPropietario() {
        return propietario;
    }

    public boolean isAbierta() {
        return abierta;
    }
}
