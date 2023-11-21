#include <iostream>
using namespace std;

int main() {
	int n = 3, m = 0, a0 = 1, a1 = 2, a2 = 3, an = 3;
	cout << "m> ";
	cin >> m;
	if (n > 2)
		while (an < m) {
			an = (3 * a2) - (2 * a0);
			n++;
			a0 = a1;
			a1 = a2;
			a2 = an;
		}
	cout << "n = " << n << "\tan = " << an << " > m = " << m << endl;
}
