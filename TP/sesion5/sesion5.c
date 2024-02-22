#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int w, h;
	printf("Intruduce tamaño (w,h)> ");
	scanf("%d,%d", &w, &h);
	while (getchar() != '\n');

	printf("w: %d, h: %d\n", w, h);

	int **v = malloc(sizeof(int*) * w);
	for (int i = 0; i < w; i++)
		v[i] = malloc(sizeof(int) * h);

	for (int x = 0; x < w; x++)
		for (int y = 0; y < h; y++) {
			printf("Introduce v[%d][%d]> ", x, y);
			scanf("%d", &v[x][y]);
		}
			
	for (int x = 0; x < w; x++)
		for (int y = 0; y < h; y++) {
			printf("v[%d][%d]: %d\n", x, y, v[x][y]);
		}

	printf("Introduce nuevo tamaño (w,h)> ");
	scanf("%d,%d", &w, &h);

	printf("w: %d, h: %d\n", w, h);

	v = realloc(v, sizeof(int*) * w);
	for (int i = 0; i < w; i++)
		v[i] = realloc(v[i], sizeof(int) * h);

	for (int x = 0; x < w; x++)
		for (int y = 0; y < h; y++) {
			printf("v[%d][%d]: %d\n", x, y, v[x][y]);
		}


}
