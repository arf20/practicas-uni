#include <stdlib.h>
#include <string.h>

#include "bombo.h"

char mensaje[100];

struct BomboRep {
	int *bolas;
	int n;
	int maxn;
};

// Construye y devuelve un bombo vacío que puede contener un
// máximo de n bolas. Si n<2 devuelve NULL y asigna error=1.
Bombo BomboCrea(int n) {
	if (n < 2) {
		error = 1;
		return NULL;
	}

	Bombo b = malloc(sizeof(Bombo));
	b->bolas = malloc(n * sizeof(int));
	b->n = 0;
	b->maxn = n;

	return b;
}

// Inserta una bola en el bombo b.
void BomboInserta(Bombo b, int bola) {
	b->bolas[b->n] = bola;
	b->n++;
}

// Libera el bombo b.
void BomboLibera(Bombo b) {
	free(b->bolas);
	free(b);
}

// Extrae y devuelve una bola del bombo b.
// Si el bombo b está vacío devuelve -1 y asigna error=2.
int BomboExtrae(Bombo b) {
	if (BomboVacio(b)) {
		error = 2;
		return -1;
	}

	int i = rand() % b->n;
	int t = b->bolas[i];
	b->bolas[i] = b->bolas[b->n];
	b->n--;
	return t;
}

// Devuelve 1 si el bombo b está vacío y 0 en caso contrario.
int BomboVacio(Bombo b) {
	return b->n == 0;
}

// Devuelve el mensaje de error asociado a un código de error
// del bombo b.
char *BomboMensajeError(Bombo b, int codigoError) {
	switch (codigoError) {
		case 1: strncpy(mensaje, "Numero de bolas inicial debe ser >=2.", 100); break;
		case 2: strncpy(mensaje, "Bombo vacío.", 100); break;
		default: strncpy(mensaje, "Error desconocido.", 100); break;
	}
	return mensaje;
}

