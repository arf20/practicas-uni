package pruebas;

import geometria.Punto;
import geometria.Circulo;

public class PruebaCirculo {
    public static void main(String[] args) {
        // 2
        Punto punto1 = new Punto(2, 3);
        Circulo circulo1 = new Circulo(punto1, 3);

        System.out.println("circulo1: { centro = {" + circulo1.getCentro().getX() + ", " + circulo1.getCentro().getY()
            + "}, radio = " + circulo1.getRadio() + " }");
     
        Circulo circulo2 = new Circulo();

        System.out.println("circulo2: { centro = {" + circulo2.getCentro().getX() + ", " + circulo2.getCentro().getY()
            + "}, radio = " + circulo2.getRadio() + " }");

        circulo1.desplazar(3, 2);

        System.out.println("circulo1: { centro = {" + circulo1.getCentro().getX() + ", " + circulo1.getCentro().getY()
            + "}, radio = " + circulo1.getRadio() + " }");

        circulo2.escalar(1.5);

        System.out.println("circulo2: { centro = {" + circulo2.getCentro().getX() + ", " + circulo2.getCentro().getY()
            + "}, radio = " + circulo2.getRadio() + " }");


        // 3
        Circulo circulo3 = new Circulo(punto1, 5);

        circulo1.desplazar(3, 2);

        System.out.println("circulo1: { centro = {" + circulo1.getCentro().getX() + ", " + circulo1.getCentro().getY()
            + "}, radio = " + circulo1.getRadio() + " }");
        System.out.println("circulo3: { centro = {" + circulo3.getCentro().getX() + ", " + circulo3.getCentro().getY()
            + "}, radio = " + circulo3.getRadio() + " }");

        Punto punto2 = circulo3.getCentro();

        punto2.desplazar(1, 0);

        System.out.println("punto2: {" + punto2.getX() + ", " + punto2.getY()
            + "}");
        System.out.println("circulo3.getCentro(): {" + circulo3.getCentro().getX()
            + ", " + circulo3.getCentro().getY() + "}");
    }
}
