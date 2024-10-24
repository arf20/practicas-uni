package subastas;

import java.util.ArrayList;

public class Subasta {
    private String nombre;
    private String propietario;
    private boolean abierta;
    private ArrayList<Puja> pujas;
    //private double pujaMayor;

    public double getPujaMayor() {
        double c = 0.0;
        for (Puja e : pujas) {
            if (e.getCantidad() > c) 
                c = e.getCantidad();
        }

        return c;
    }

    public Subasta(String nombre, String propietario) {
        this.nombre = nombre;
        this.propietario = propietario;

        abierta = true;
        pujas = new ArrayList<Puja>();
        pujaMayor = 0.0;
    }

    public boolean pujar(String usuario, double puja) {
        if (!abierta || (propietario == usuario) || (puja <= pujaMayor))
            return false;
        
        pujas.add(new Puja(usuario, puja));
        pujaMayor = puja;
        return true;
    }

    public boolean pujar(String usuario) {
        return pujar(usuario, pujaMayor + 1.0);
    }

    public boolean ejecutar() {
        if (pujas.isEmpty() || !abierta) return false;

        abierta = false;
        return true;
    }
}
