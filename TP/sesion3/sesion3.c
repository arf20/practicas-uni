#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void flushstdin(void) {
	while (getchar());
}

int read_int(int *i) {
	if (i == NULL) return -1;
	if (scanf("%d", i) != 1) return -1;
	return 0;
}

int main() {
	int i = 0, res = 0;
	printf("Introduce un numero entero> ");
	do {
		res = read_int(&i);
		if (res) printf("Formato incorrecto, introduce un numero entero> ");
		
	} while (res);


	return 0;
}
