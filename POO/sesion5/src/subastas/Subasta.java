package subastas;

import java.util.ArrayList;

public class Subasta {
    private String nombre;
    private String propietario;
    private boolean abierta;
    private ArrayList<Puja> pujas;

    public double getPujaMayor() {
        double c = 0.0;
        for (Puja e : pujas) {
            if (e.cantidad() > c) 
                c = e.cantidad();
        }

        return c;
    }

    public Subasta(String nombre, String propietario) {
        this.nombre = nombre;
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
}
