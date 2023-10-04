#include <iostream>
using namespace std;

int main() {
	int d, m, y, nm;
	cout << "d> ";
	cin >> d;
	cout << "m> ";
	cin >> m;
	cout << "y> ";
	cin >> y;

	d++;

	int dpm[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	nm = m + (d / dpm[m - 1]);
	d %= dpm[m - 1];
	m = nm;

	y += m / 12;
	m %= 12;

	printf("next day (d/m/y): %d-%d-%d\n", d, m, y);

}
