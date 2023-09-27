#include <iostream>
using namespace std;

int main() {
	int a = 1, b = 2, c = 3, aux;

	cout << "a\tb\tc" << endl << a << "\t" << b << "\t" << c << endl;

	// a b c
	// c a b

	aux = b;
	b = a;
	a = c;
	c = aux;

	cout << a << "\t" << b << "\t" << c << endl;

	return 0;
}
