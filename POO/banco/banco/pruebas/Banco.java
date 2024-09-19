package banco.pruebas;

public class Banco {
    

    public static void main(String[] args) {
        banco.productos.Cuenta c2 = new banco.productos.Cuenta("arf20");
        //Cuenta c2 = new Cuenta("pedro", 100);

        c2.ingreso(100);

        System.out.println("saldo " + c2.getSaldo());
    }
}