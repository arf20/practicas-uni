#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "cola.h"

#define N 	5

void flush() {
	while (getchar() != '\n');
}

int main() {
	int especialidad;

	char especialidades[N][17] = {
		"Medicina general",
		"Pediatría",
		"Reumatología",
		"Medicina interna",
		"Enfermería"
	};

	queue_t **consultorio = malloc(sizeof(queue_t*) * N);

	for (int i = 0; i < N; i++)
		consultorio[i] = queue_create();

	int pacientes = 0;
	data_t paciente;
	do {
		printf("Introduce especialidad [1-5,0=end]> ");
		scanf("%d", &especialidad);
		flush();
		if (especialidad != 0) {
			printf("Introduce nombre> ");
			fgets(paciente.nombre, 30, stdin);
			paciente.nombre[strlen(paciente.nombre) - 1] = '\0';
			printf("Introduce DNI> ");
			fgets(paciente.DNI, 10, stdin);
			paciente.DNI[strlen(paciente.DNI) - 1] = '\0';
			if (especialidad >= 1 && especialidad <= N) {
				queue_insert(consultorio[especialidad-1], paciente);
				pacientes++;
			}
		}
	} while(especialidad != 0);

	// dar paso
	srand(time(NULL));

	while (pacientes > 0) {
		int colarnd = rand() % N;
		while (queue_empty(consultorio[colarnd])) {
			colarnd = (colarnd + 1) % N;
		}
		
		data_t d = queue_pop(consultorio[colarnd]);
		printf("Nombre %s, con DNI %s, especialidad %s\n", d.nombre, d.DNI, especialidades[colarnd]);
		pacientes--;
	}

	for (int i = 0; i < N; i++)
		queue_free(consultorio[i]);
	free(consultorio);

	return 0;
}
