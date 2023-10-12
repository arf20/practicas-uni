#include <iostream>
using namespace std;

void bindec(int b1, int b2, int b3, int b4, int &dec) {
	dec = b4 << 3 | b3 << 2 | b2 << 1 | b1;
}

void intercambio(char &a, char &b) {
	char aux = a;
	a = b;
	b = aux;
}

int main() {
	int d1 = 0, d2 = 1, dec1, dec2;
	char x = 'A', y = 'C', z = 'B';

	intercambio(x, y);
	intercambio(y, z);
	bindec(1, 0, 1, 1, dec1);	// 1101 1011
	bindec(0, 0, 0, 0, dec2);	// 0000 0000

	cout << "x, y, z = " << x << " " << y << " " << z << endl;
	cout << "dec1, dec2 = " << dec1 << " " << dec2 << endl;

	return 0;
}
