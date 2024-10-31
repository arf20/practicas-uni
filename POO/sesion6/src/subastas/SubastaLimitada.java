package subastas;

import java.util.ArrayList;

public class SubastaLimitada extends Subasta {
    private int maxPujas;
    public SubastaLimitada(String nombre, String propietario, int maxPujas) {
        super(nombre, propietario);
        this.maxPujas = maxPujas;
    }

    public boolean pujar(String usuario, double puja) {
        if (!abierta || (propietario == usuario) || (puja <= getPujaMayor()))
            return false;
        
        pujas.add(new Puja(usuario, puja));
        if (getPujasPendientes() == 0)
            ejecutar();
        return true;
    }

    public int getPujasPendientes() {
        return maxPujas - pujas.size();
    }
}
