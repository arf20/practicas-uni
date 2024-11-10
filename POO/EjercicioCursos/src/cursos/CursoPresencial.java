package cursos;

import java.time.LocalDate;
import java.util.LinkedList;

public class CursoPresencial extends Curso {
	private int cupo;

	public CursoPresencial(String titulo, LocalDate fechaInicio, LocalDate fechaFin, double precio, int cupo) {
		super(titulo, fechaInicio, fechaFin, precio);
		this.cupo = cupo;
	}

	public int getCupo() {
		return cupo;
	}

	public int getPlazasLibres() {
		return cupo - getNumAlumnos();
	}

	protected boolean matricularCumpleRequisitosEspecificos(Alumno a) {
		return getPlazasLibres() == 0;
    }
}
