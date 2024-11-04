import java.time.LocalDate;

public class ViajePremium extends Viaje {
    public ViajePremium(String propietario, String coche, String ruta,
        LocalDate salida, int plazasOfertadas)
    {
        super(propietario, coche, ruta, salida, plazasOfertadas);
    }

    public boolean cancelarReserva(String usuario) {
        for (Reserva r : reservas) {
            if (r.usuario() == usuario) {
                reservas.remove(r);
                return true;
            }
        }
        return false;
    }

    public void cancelaTodas() {
        reservas.clear();
    }
}
