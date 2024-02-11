/* Adivina un numero */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

int main() {
	printf("Hola\n¿Cómo te llamas?> ");

	char buff[20];
	fgets(buff, 20, stdin);
	if (strlen(buff) > 0) buff[strlen(buff)-1] = '\0';

	printf("Encantado/a %s\n\nEstoy pensando en un numero del 1 al 10, adivina cual> ", buff);

	srand(time(NULL));
	int numi = 1 + (rand() % 9);

	int nume = 0, intentos = 0;

	do {
		fgets(buff, 20, stdin);
		nume = atoi(buff);

		if (!(nume >= 1 && nume <= 10)) {
			printf("Mete un numero cabron> ");
			continue;
		}

		if (nume > numi) printf("No era ese xd, es menor> ");
		else if (nume < numi) printf("No era ese xd, es mayor> ");

		intentos++;
	} while (numi != nume);

	printf("GG lo has adivinado :D\nEn %d intentos damm\n", intentos);

	return 0;
}

