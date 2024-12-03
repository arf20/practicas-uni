import java.time.LocalDate;

public record Tarea(String descripcion, LocalDate plazo) {
    public Tarea(String descripcion) {
        this(descripcion, null); // debe llamar constructor canonico
    }

    public boolean tienePlazo() {
        return plazo != null;
    }

    public boolean isVencida() {
        if (plazo == null) return false;
        return plazo.isBefore(LocalDate.now());
    }
}
