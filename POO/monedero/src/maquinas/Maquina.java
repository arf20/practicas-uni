package maquinas;

public class Maquina {
    private String producto;
    private Monedero precio;
    private int stock;
    private Monedero dinero;
    private Monedero dinero_transaccion;
    private boolean vacia;

    public Maquina() {
        dinero = new Monedero(precio);
        dinero_transaccion = new Monedero(precio);
    }

    public Maquina(String producto, Monedero precio, int stock) {
        this();
        this.producto = producto;
        this.precio = new Monedero(precio);
        this.stock = stock;
    }

    public void insertar(Moneda m) {
        dinero_transaccion.insertar(m);
    }

    public Monedero devolver() {
        Monedero mon = new Monedero(dinero_transaccion);
        dinero_transaccion.vaciar();
        return mon;
    }

    public boolean comprar() {
        if ((dinero_transaccion.valorTotal() < precio.valorTotal())
            || (stock == 0)) return false;
        
        stock--;
        dinero.combinar(dinero_transaccion);
        return true;
    }

    public int getStock() {
        return stock;
    }
}
