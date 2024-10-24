package subastas;

public class Programa {
    public static void main(String[] args) {
        Subasta subasta = new Subasta("Teléfono Móvil", "Juan");
        subasta.pujar("Pedro", 100.0);
        System.out.println("Puja mayor: " + subasta.getPujaMayor());
        subasta.pujar("Enrique", 50.0);
        System.out.println("Puja mayor: " + subasta.getPujaMayor());
        subasta.ejecutar();
        subasta.pujar("Enrique", 200.0);
        System.out.println("Puja mayor: " + subasta.getPujaMayor());
    }
}
