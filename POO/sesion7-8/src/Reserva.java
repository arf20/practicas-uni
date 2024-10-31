import java.time.LocalDate;

public record Reserva(
    String usuario,
    int num_plazas,
    LocalDate fecha,
    String codigo
) {
    public Reserva(String usuario, int num_plazas, String codigo) {
        this.usuario = usuario;
        this.num_plazas = num_plazas;
        this.codigo = codigo;
        fecha = LocalDate.now();
    }
}
