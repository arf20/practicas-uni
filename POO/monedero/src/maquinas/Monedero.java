package maquinas;

public class Monedero {
    private int[] cantidades;

    public Monedero() {
        cantidades = new int[Moneda.values().length];
    }

    public Monedero(Monedero mon) {
        this();
        for (int i = 0; i < cantidades.length; i++) {
            cantidades[i] = mon.get(Moneda.values()[i]);
        }
    }

    public Monedero(Moneda m, int cant) {
        this();
        cantidades[m.ordinal()] = cant;
    }

    public Monedero(Moneda m) {
        this(m, 1);
    }


    public int getCents1() { 
        return cantidades[Moneda.CENT_1.ordinal()];
    }

    public int getCents2() { 
        return cantidades[Moneda.CENT_2.ordinal()];
    }

    public int getCents5() { 
        return cantidades[Moneda.CENT_5.ordinal()];
    }

    public int getCents10() { 
        return cantidades[Moneda.CENT_10.ordinal()];
    }

    public int getCents20() { 
        return cantidades[Moneda.CENT_20.ordinal()];
    }

    public int getCents50() { 
        return cantidades[Moneda.CENT_50.ordinal()];
    }

    public int getEur1() { 
        return cantidades[Moneda.EUR_1.ordinal()];
    }

    public int getEur2() { 
        return cantidades[Moneda.EUR_2.ordinal()];
    }

    public int get(Moneda m) {
        return cantidades[m.ordinal()];
    }

    public double valorTotal() {
        return 
            0.01 * cantidades[Moneda.CENT_1.ordinal()] +
            0.02 * cantidades[Moneda.CENT_2.ordinal()] +
            0.05 * cantidades[Moneda.CENT_5.ordinal()] +
            0.10 * cantidades[Moneda.CENT_10.ordinal()] +
            0.20 * cantidades[Moneda.CENT_20.ordinal()] +
            0.50 * cantidades[Moneda.CENT_50.ordinal()] +
            1.00 * cantidades[Moneda.EUR_1.ordinal()] +
            2.00 * cantidades[Moneda.EUR_2.ordinal()];
    }

    public void insertar(Moneda m, int cant) {
        cantidades[m.ordinal()] += cant;
    }

    public void insertar(Moneda m) {
        insertar(m, 1);
    }

    public void vaciar() {
        for (int i = 0; i < cantidades.length; i++) {
            cantidades[i] = 0;
        }
    }

    public void combinar(Monedero mon) {
        for (int i = 0; i < cantidades.length; i++) {
            cantidades[i] += mon.get(Moneda.values()[i]);
        }
        mon.vaciar();
    }

}
