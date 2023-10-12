#include <iostream>
using namespace std;

int max(int a, int b) {
	return a > b ? a : b;
}

int main() {
	int n1, n2, n3;
	cout << "n1> ";
	cin >> n1;
	cout << "n2> ";
	cin >> n2;
	cout << "n3> ";
	cin >> n3;

	cout << "mayor: " << max(n1, max(n2, n3)) << endl;
}
