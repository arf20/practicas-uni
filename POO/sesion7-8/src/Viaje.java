import java.security.DrbgParameters.Reseed;
import java.time.LocalDate;
import java.util.ArrayList;
import java.util.Objects;
import java.util.UUID;

public class Viaje implements Cloneable {
    protected String codigo, propietario, coche, ruta;
    protected LocalDate salida;
    protected int plazasOfrecidas;
    protected ArrayList<Reserva> reservas;
    
    public Viaje(String propietario, String coche, String ruta,
        LocalDate salida, int plazasOfertadas)
    {
        this.propietario = propietario;
        this.coche = coche;
        this.ruta = ruta;
        this.salida = salida;
        this.plazasOfrecidas = plazasOfertadas;

        codigo = UUID.randomUUID().toString();
        reservas = new ArrayList<Reserva>();
    }

    public Viaje(String propietario, String coche, String ruta,
        LocalDate salida)
    {
        this(propietario, coche, ruta, salida, 1);
    }

    public String getCodigo() {
        return codigo;
    }

    public String getPropietario() {
        return propietario;
    }

    public String getCoche() {
        return coche;
    }

    public String getRuta() {
        return ruta;
    }

    public LocalDate getSalida() {
        return salida;
    }

    public int getPlazasOfrecidas() {
        return plazasOfrecidas;
    }

    public int getPlazasReservadas() {
        int plazasReservadas = 0;
        for (Reserva r : reservas)
            plazasReservadas += r.numPlazas();
        return plazasReservadas;
    }

    public int getPlazasDisponibles() {
        return plazasOfrecidas - getPlazasReservadas();
    }

    public Reserva realizarReserva(String usuario, int plazas) {
        if (plazas > getPlazasDisponibles() || LocalDate.now().isAfter(salida))
            return null;

        for (Reserva r : reservas)
            if (r.usuario() == usuario)
                return null;

        Reserva r = new Reserva(usuario, plazas, codigo);
        reservas.add(r);
        return r;
    }

    public Reserva realizarReserva(String usuario) {
        return realizarReserva(usuario, 1);
    }

    public Reserva getReservaByUsuario(String usuario) {
        for (Reserva r : reservas)
            if (r.usuario() == usuario)
                return r;
        return null;
    }

    public String toString() {
        return String.format("Viaje[codigo=%s, propietario=%s, coche=%s, " + 
            "ruta=%s, salida=%s, plazasOfrecidas=%d, reservas={%s}]",
            codigo, propietario, coche, ruta, salida.toString(),
            plazasOfrecidas, reservas.toString());
    }

    public boolean equals(Object v) {
        if (v == null) return false;
        if (getClass() != v.getClass()) return false;
        return this == v || codigo == ((Viaje)v).getCodigo();
    }

    public int hashCode() {
        return Objects.hash(codigo);
    }

    public Viaje copiaSuperficial() {
        try {
            return (Viaje)super.clone();
        } catch (CloneNotSupportedException e) {
            System.err.println("La clase no es cloneable");
        }
        return null;
    }

    public Viaje clone() {
        Viaje copia = copiaSuperficial();
        copia.codigo = UUID.randomUUID().toString();
        copia.reservas = (ArrayList<Reserva>)copia.reservas.clone();
        return copia;
    }
}
