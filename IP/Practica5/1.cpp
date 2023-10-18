#include <iostream>
using namespace std;

struct Point {
	float x, y;
};

struct Rect {
	Point p1, p2, p3, p4;
};

void readpoint(std::istream& is, Point& p) {
	is >> p.x >> p.y;
}

void readrect(std::istream& is, Rect& r) {
	readpoint(is, r.p1);
	readpoint(is, r.p2);
	readpoint(is, r.p3);
	readpoint(is, r.p4);
}

int main() {
	Point mip;
	Rect cuadrado;
	cout << "Introducir x, y> ";
	cin >> mip.x >> mip.y;
	cout << "x: " << mip.x << "y: " << mip.y << endl;

	cout << "Introducir puntos del cuadrado> ";
	readrect(cin, cuadrado);
}
