#include <stdio.h>
#include <stdint.h>
#include <math.h>

#define DISTANCE_EARTH_SUN 147.34e9
#define DISTANCE_EARTH_MOON 384400000

int main() {
	long double v = 0.0, v2 = 0.0;
	int res = 0;
	do {
		printf("Velocidad nave 1 (km/h)> ");
		res = scanf("%Lf", &v);

		if (res != 1) {
			printf("Mal formato, introduce numero real\n");
			while (getchar() != '\n');
			continue;
		}

		printf("Velocidad nave 2 (km/h)> ");	
		res = scanf("%Lf", &v2);

		if (res != 1) {
			printf("Mal formato, introduce numero real\n");
			while (getchar() != '\n');
			continue;
		}

		v /= 3.6f;	/* m/s */
		
		long double t = DISTANCE_EARTH_SUN / v;
		long double s = t;
		long double m = t / 60;
		long double h = t / 3600;
		long double d = t / (3600*24);
		long double a = t / (3600*24*365);

		if (t == INFINITY) {
			printf("Desbordamiento\n");
			continue;
		}

		printf("Tiempo de llegada al Sol:\n\ts: %Lf\n\tm: %Lf\n\th: %Lf\n\td: %Lf\n\ta: %Lf\n", s, m, h, d, a);

		long double t2 = DISTANCE_EARTH_MOON / (v + v2);
		s = t2;
		m = t2 / 60;
		h = t2 / 3600;
		d = t2 / (3600*24);
		a = t2 / (3600*24*365);

		if (t == INFINITY) {
			printf("Desbordamiento\n");
			continue;
		}

		printf("Tiempo de colision:\n\ts: %Lf\n\tm: %Lf\n\th: %Lf\n\td: %Lf\n\ta: %Lf\n", s, m, h, d, a);

	} while (res != 1.0f);

	return 0;
}
