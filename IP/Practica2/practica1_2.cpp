#include <iostream>
using namespace std;

int main() {
	int val;
	cout << "Input value EUR> ";
	cin >> val;

	int b500, b100, b50, b20, b10, b5;
	b500 = val / 500;
	val  = val % 500;
	b100 = val / 100;
	val  = val % 100;
	b50  = val / 50;
	val  = val % 50;
	b20  = val / 20;
	val  = val % 20;
	b10  = val / 10;
	val  = val % 10;
	b5   = val / 5;
	val  = val % 5;

	cout << "B500\tB100\tB50\tB20\tB10\tB5\tR" << endl << b500 << "\t" << b100 << "\t" << b50 << "\t" << b20 << "\t" << b10 << "\t" << b5 << "\t" << val << endl;
}
