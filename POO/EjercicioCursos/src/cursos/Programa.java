package cursos;

import java.time.LocalDate;
import java.util.Collections;
import java.util.LinkedList;

public class Programa {

	public static void main(String[] args) {
		Alumno pepe = new Alumno("Pepe", "34678904");
		Alumno andrea = new Alumno("Andrea", "17679456", 50);

		LocalDate hoy = LocalDate.now();
		
		CursoPresencial presencial = new CursoPresencial("Diseño de bases de datos", hoy.plusMonths(1), hoy.plusMonths(1), 55, 20);
		
		CursoOnline online = new CursoOnline("Administración de base de datos", hoy.plusDays(7), hoy.plusDays(7), 25, presencial);
		
		LinkedList<Curso> cursos = new LinkedList<Curso>();
		
		Collections.addAll(cursos, presencial, online);
		
		for (Curso curso: cursos) {
			curso.matricular(pepe);
			curso.matricular(andrea);
			
			System.out.println(curso);
		}
	}

}
