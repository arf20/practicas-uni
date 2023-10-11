#include <iostream>
using namespace std;

void divint(int dd, int ds, int& q, int& r) {
	q = dd / ds;
	r = dd % ds;
}

int main() {
	int cantidad, resto, b500, b100, b50, b20, b10, b5;

	cout << "Cantidad> ";
	cin >> cantidad;
	
	divint(cantidad, 500, b500, resto);
	divint(resto, 100, b100, resto);
	divint(resto, 50, b50, resto);
	divint(resto, 20, b20, resto);
	divint(resto, 10, b10, resto);
	divint(resto, 5, b5, resto);

	cout << "Bill\t500\t100\t50\t20\t10\t5" << endl;
	cout << "\t" << b500 << "\t" << b100 << "\t" << b50 << "\t" << b20 << "\t" << b10 << "\t" << b5 << endl;
	cout << "Resto:\t" << resto << endl;
}
