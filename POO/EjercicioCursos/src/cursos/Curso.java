package cursos;

import java.time.LocalDate;
import java.util.LinkedList;

public abstract class Curso {
	private String titulo;
	private LocalDate fechaInicio;
	private LocalDate fechaFin;
	private double precio;
	private LinkedList<Alumno> matriculados;
		
	public Curso(String titulo, LocalDate fechaInicio, LocalDate fechaFin, double precio) {
		this.titulo = titulo;
		this.fechaInicio = fechaInicio;
		this.fechaFin = fechaFin;
		this.precio = precio;
		this.matriculados = new LinkedList<Alumno>();
	}

	public String getTitulo() {
		return titulo;
	}

	public LocalDate getFechaInicio() {
		return fechaInicio;
	}

	public LocalDate getFechaFin() {
		return fechaFin;
	}

	public double getPrecio() {
		return precio;
	}

	public LinkedList<Alumno> getMatriculados() {
		return new LinkedList<Alumno>(matriculados);
	}

	//Propiedad calculada
	public int getNumAlumnos() {
		return matriculados.size();
	}

	public boolean haTerminado() {
		return LocalDate.now().isAfter(fechaFin);
	}
	
	protected abstract boolean matricularCumpleRequisitosEspecificos(Alumno a);

	public boolean matricular(Alumno a) {
		if (haTerminado() || (a.getCredito() < precio)
			|| matricularCumpleRequisitosEspecificos(a)) return false;
		matriculados.add(a);
		a.decrementarCredito(precio);
		a.addCurso(this);
		return true;
	}

	@Override
	public String toString() {
		return getClass().getName() 
				+ "\n[titulo=" + titulo 
				+ ",\n fechaInicio=" + fechaInicio 
				+ ",\n fechaFin=" + fechaFin 
				+ ",\n precio=" + precio 
				+ ",\n matriculados=" + matriculados 
				+ "]";
	} 
	
	
}
