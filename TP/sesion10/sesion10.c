#include <stdio.h>

int sumatorio(int n) {
	if (n == 1) return 1;
	return sumatorio(n - 1) + n;
}

int main() {
	int n = 15;
	printf("Sumatorio de %d es %d\n", n, sumatorio(n));

	return 0;
}

