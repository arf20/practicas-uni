package reastreadores;

public class Programa {
    public static void main(String[] args) {
        Rastreador rastreador = new Rastreador();

        rastreador.registrar("Ernesto", "Los rivales también juegan, no sólo el #Barça");
        rastreador.registrar("Manolete", "El #Barça es poco competitivo esta temporada");
        rastreador.registrar("Manolete", "#Barça y #RealMadrid han roto el mercado de fichajes");

        var ordenados1 = rastreador.getMensajesOrdenados();
        var ordenados2 = rastreador.getMensajesOrdenados(
            (m1, m2) -> m1.getAutor().compareTO(m2.getAutor())
        );
        System.out.println(ordenados1);

        

    }

}
