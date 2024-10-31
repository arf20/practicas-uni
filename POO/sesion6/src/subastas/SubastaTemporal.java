package subastas;

import java.util.ArrayList;
import java.time.LocalDateTime;
import java.time.temporal.ChronoUnit;

public class SubastaTemporal extends SubastaLimitada {
    private int duracionHoras;
    private LocalDateTime tiempoCreacion, tiempoVencimiento;

    public SubastaTemporal(String nombre, String propietario, int duracionHoras) {
        super(nombre, propietario, duracionHoras * 2);
        this.duracionHoras = duracionHoras;

        tiempoCreacion = LocalDateTime.now();
        tiempoVencimiento = tiempoCreacion.plusHours(duracionHoras);
    }

    public boolean pujar(String usuario, double puja) {
        if (
            !abierta ||
            (propietario == usuario) ||
            (puja <= getPujaMayor()) ||
            LocalDateTime.now().isAfter(tiempoVencimiento)
        )
            return false;
        
        pujas.add(new Puja(usuario, puja));
        if (getPujasPendientes() == 0)
            ejecutar();
        return true;
    }

    public boolean ejecutar() {
        if (
            pujas.isEmpty() ||
            !abierta ||
            LocalDateTime.now().isBefore(tiempoVencimiento)
        ) return false;

        abierta = false;
        return true;
    }

    public int getDuracionHoras() {
        return duracionHoras;
    }

    public long getHorasRestantes() {
        return ChronoUnit.HOURS.between(tiempoCreacion, LocalDateTime.now());
    }
}
