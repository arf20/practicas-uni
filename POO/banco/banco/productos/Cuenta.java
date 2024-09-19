package banco.productos;

public class Cuenta {
    private String titular;
    private double saldo;

    public Cuenta(String _titular) {
        this(_titular, 0);
    }

    public Cuenta(String _titular, double _saldo) {
        titular = _titular;
        saldo = _saldo;
    }

    public void ingreso(double in) {
        saldo += in;
    }

    public double getSaldo() {
        return saldo;
    }
}
