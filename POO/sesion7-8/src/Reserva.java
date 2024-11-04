import java.time.LocalDate;
import java.util.Objects;

public record Reserva(
    String usuario,
    int numPlazas,
    LocalDate fecha,
    String codigo
) {
    public Reserva(String usuario, int numPlazas, String codigo) {
        this(usuario, numPlazas, LocalDate.now(), codigo);
    }

    public boolean equals(Object o) {
        if (o == null) return false;
        if (getClass() != o.getClass()) return false;
        Reserva r = (Reserva)o;
        return this == r || (usuario == r.usuario && numPlazas == r.numPlazas &&
            fecha == r.fecha && codigo == r.codigo);
    }

    public int hashCode() {
        return Objects.hash(usuario, numPlazas, fecha, codigo);
    }
}
