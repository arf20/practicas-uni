import java.time.LocalDate;
import java.util.ArrayList;
import java.util.UUID;

public class ViajeSelectivo extends Viaje {
    private ArrayList<String> usuariosVetados;

    public ViajeSelectivo(String propietario, String coche, String ruta,
        LocalDate salida, int plazasOfertadas)
    {
        super(propietario, coche, ruta, salida, plazasOfertadas);
        usuariosVetados = new ArrayList<String>();
    }

    public void vetarUsuario(String usuario) {
        usuariosVetados.add(usuario);
    }

    public void desvetarUsuario(String usuario) {
        usuariosVetados.removeIf(u -> u == usuario);
    }

    public Reserva realizarReserva(String usuario, int plazas) {
        if (plazas > getPlazasDisponibles() || LocalDate.now().isAfter(salida))
            return null;

        for (String u : usuariosVetados)
            if (u == usuario)
                return null;

        for (Reserva r : reservas)
            if (r.usuario() == usuario)
                return null;

        Reserva r = new Reserva(usuario, plazas, codigo);
        reservas.add(r);
        return r;
    }

    public String toString() {
        return String.format("Viaje[codigo=%s, propietario=%s, coche=%s, " + 
            "ruta=%s, salida=%s, plazasOfrecidas=%d, reservas=%s, " +
            "usuariosVetados=%s]",
            codigo, propietario, coche, ruta, salida.toString(),
            plazasOfrecidas, reservas.toString(), usuariosVetados.toString());
    }

    public ViajeSelectivo clone() {
        ViajeSelectivo copia = (ViajeSelectivo)copiaSuperficial();
        copia.codigo = UUID.randomUUID().toString();
        copia.reservas = (ArrayList<Reserva>)copia.reservas.clone();
        copia.usuariosVetados = (ArrayList<String>)copia.usuariosVetados.clone();
        return copia;
    }
}
