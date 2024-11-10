package cursos;

import java.time.LocalDate;
import java.util.Collection;
import java.util.LinkedList;

public class CursoOnline extends Curso {
    private LinkedList<Curso> cursosRequeridos;

    public CursoOnline(String titulo, LocalDate fechaInicio, LocalDate fechaFin, double precio, Curso cursosRequeridos) {
        super(titulo, fechaInicio, fechaFin, precio);
        this.cursosRequeridos = new LinkedList<Cursos>();
        Collection.addAll(this.cursosRequeridos, cursosRequeridos);
    }

    protected boolean matricularCumpleRequisitosEspecificos(Alumno a) {
        return !cursosRequeridos.containsAll(a.getCursos());
    }
    
}
