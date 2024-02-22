#include <stdio.h>
#include <stdlib.h>

#define MAX_STRING_SIZE	100
#define MAX_MATRIX_HEIGHT	100

void array_print(int *v, int n) {
	for (int i = 0; i < n; i++) {
		printf("v[%d] = %d\n", i, v[i]);
	}
}

int array_contains(int *v, int n, int x) {
	for (int i = 0; i < n; i++)
		if (v[i] == x) return 1;
	return 0;
}

int matrix_print(int **v, int w, int h) {
	for (int y = 0; y < h; y++)
		for (int x = 0; x < w; x++)
			printf("v[%d][%d] = %d\n", x, y, v[x][y]);
}

int main() {
	/*int n;
	printf("Enter array size> ");
	scanf("%d", &n);

	int *v = malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		printf("Enter v[%d]> ", i);
		scanf("%d", &v[i]);
	}

	array_print(v, n);

	free(v);
	*/
	/*	
	int w, h;

	printf("Enter matrix width> ");
	scanf("%d", &w);
	printf("Enter matrix height> ");
	scanf("%d", &h);

	int **m = malloc(sizeof(int*) * w);
	for (int i = 0; i < h; i++)
		m[i] = malloc(sizeof(int) * h);

	for (int y = 0; y < h; y++)
		for (int x = 0; x < w; x++) {
			printf("v[%d][%d]> ", x, y);
			scanf("%d", &m[x][y]);
	}

	matrix_print(m, w, h);

	for (int i = 0; i < w; i++)
		free(m[i]);
	free(m);*/


	
	return 0;
}

