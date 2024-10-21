package maquinas;

public class Programa {
    public static void main(String[] args) {
        Maquina m = new Maquina("Agua", new Monedero(Moneda.CENT_10, 6), 10);
        m.insertar(Moneda.EUR_1);
        m.devolver();
        m.insertar(Moneda.CENT_50);

        if (m.comprar())
            System.out.println("comprado");
        else
            System.out.println("no comprado");

        m.insertar(Moneda.CENT_20);
        
        if (m.comprar())
            System.out.println("comprado");
        else
            System.out.println("no comprado");

        
        
        System.out.println("stock: "+ m.getStock());
    }
}
