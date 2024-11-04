import java.time.LocalDate;
import java.util.ArrayList;

public class Programa {
    public static void main(String[] args) {
        Viaje v1 = new Viaje("José Antonio", "Seat León",
            "Murcia-Cartagena", LocalDate.of(2024, 11, 9));
        ViajeSelectivo v2 = new ViajeSelectivo("José Antonio", "Seat León",
            "Murcia-Campus", LocalDate.of(2024, 12, 11), 4);
        v2.vetarUsuario("Beatriz");
        ViajePremium v3 = new ViajePremium("José Antonio", "Seat León",
            "Murcia-Barcelona", LocalDate.of(2024, 12, 15), 6);

        System.out.println(v1.realizarReserva("Alberto", 2));
        System.out.println(v2.realizarReserva("Enrique", 3));
        System.out.println(v2.realizarReserva("Beatriz"));
        System.out.println(v3.realizarReserva("Ana", 2));

        System.out.println(v3.cancelarReserva("Ana"));

        ArrayList<Viaje> viajes = new ArrayList<Viaje>();
        viajes.add(v1);
        viajes.add(v2);
        viajes.add(v3);

        for (Viaje v : viajes) {
            if (v instanceof ViajeSelectivo) {
                ((ViajeSelectivo)v).desvetarUsuario("Beatriz");
                System.out.println(((ViajeSelectivo)v).toString());
            } else System.out.println(v.toString());
        }

        System.out.println(viajes.contains(v3));

        ArrayList<Viaje> copias =  new ArrayList<Viaje>();

        for (Viaje v : viajes) {
            Viaje copia = v.clone();
            if (copia instanceof ViajePremium) {
                ((ViajePremium)copia).cancelaTodas();
            }
            copias.add(copia.clone());
        }

        System.out.println(copias.toString());
        System.out.println(viajes.equals(copias));
    }
}
