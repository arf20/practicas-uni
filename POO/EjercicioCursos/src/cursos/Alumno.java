package cursos;

import java.util.LinkedList;

public class Alumno {
	private static final double DEFAULT_CREDITO = 100;
	
	private final String nombre;
	private final String dni;
	private double credito;
	private LinkedList<Curso> cursos;
	
	public Alumno(String nombre, String dni, double credito) {
		this.nombre = nombre;
		this.dni = dni;
		this.credito = credito;
		this.cursos = new LinkedList<Curso>();
	}

	public Alumno(String nombre, String dni) {
		this(nombre, dni, DEFAULT_CREDITO);
	}
	
	public String getNombre() {
		return nombre;
	}

	public String getDni() {
		return dni;
	}

	public double getCredito() {
		return credito;
	}

	public LinkedList<Curso> getCursos() {
		return new LinkedList<Curso>(cursos);
	}

	public void incrementarCredito(double cantidad) {
		credito += cantidad;
	}
	
	public void decrementarCredito(double cantidad) {
		credito -= cantidad;
	}
	
	public boolean addCurso(Curso curso) {
		if (!cursos.contains(curso))
				return cursos.add(curso);
		
		return false;
	}

	@Override
	public String toString() {
		return getClass().getName() + 
				"[nombre=" + nombre 
				+ ", dni=" + dni 
				+ ", credito=" + credito 
				+ ", cursos=" + cursos.size() 
				+ "]";
	}
	
	
}
