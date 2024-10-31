import java.time.LocalDate;
import java.util.ArrayList;

public class Viaje {
    private String codigo, propietario, coche, ruta;
    private LocalDate salida;
    private int plazasOfertadas; //plazasReservadas;
    private ArrayList<Reserva> reservas;
    
    public Viaje(String propietario, String coche, String ruta,
        LocalDate salida, int plazasOfertadas)
    {
        this.propietario = propietario;
        this.coche = coche;
        this.ruta = ruta;
        this.salida = salida;
        this.plazasOfertadas = plazasOfertadas;

        codigo = UUID.randomUUID().toString();
        reservas = new ArrayList<Reserva>();
    }
}
