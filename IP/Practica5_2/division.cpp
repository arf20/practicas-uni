#include <iostream>
using namespace std;

int main() {
	int d, c = 0, r;
	cout << "Dividendo> ";
	cin >> r;
	cout << "Divisor> ";
	cin >> d;

	while (r > d) {
		c++;
		r -= d;
	}

	cout << "Cociente: " << c << "\tResto: " << r << endl;
}
