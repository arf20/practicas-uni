#include <iostream>
using namespace std;

int main() {
	uint64_t n = 2, a0 = 1, a1 = 2, a2 = 3, an = 3;
	cout << "n> ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		an = (3 * a2) - (2 * a0);
		a0 = a1;
		a1 = a2;
		a2 = an;
		cout << an << endl;
	}
	cout << "an = " << an << endl;
}
