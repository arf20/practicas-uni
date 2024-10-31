package subastas;

import java.util.ArrayList;

public class Programa {
    public static void main(String[] args) {
        String juan = "Juan";
        String enrique = "Enrique";

        SubastaLimitada limitada =
            new SubastaLimitada("Disco duro multimedia", juan, 1);

        SubastaTemporal temporal =
            new SubastaTemporal("Teclado", juan, 3);

        SubastaMinima minima = new SubastaMinima("Impresora Láser", juan, 100);

        ArrayList<Subasta> subastas = new ArrayList<Subasta>();

        subastas.add(limitada);
        subastas.add(temporal);
        subastas.add(minima);

        for (Subasta s : subastas) {
            System.out.println(s.getProducto() + ": ");
            s.pujar(enrique, 10);
            s.pujar(enrique, 20);
            if (s instanceof SubastaLimitada)
                System.out.println("  pujas pendientes: " + ((SubastaLimitada)s).getPujasPendientes());
            if (s.isAbierta())
                if (!s.ejecutar())
                    System.out.println("  Error ejecutando");

        }
        
    }
}
