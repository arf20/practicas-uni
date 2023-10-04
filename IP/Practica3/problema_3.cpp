#include <iostream>
using namespace std;

int main() {
	int d, m, y;
	cout << "d> ";
	cin >> d;
	cout << "m> ";
	cin >> m;
	cout << "y> ";
	cin >> y;

	d++;

	switch (m) {
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			m += d / 31;
			d %= 31;
		break;
		case 4:
		case 6:
		case 9:
		case 11:
			m += d / 30;
			d %= 30;
		case 2:
			m += d / 28;
			d %= 28;
		break;
		default:
			printf("m: wtf\n");
	}

	y += m / 12;
	m %= 12;

	printf("next day (d/m/y): %d-%d-%d\n", d, m, y);

}
