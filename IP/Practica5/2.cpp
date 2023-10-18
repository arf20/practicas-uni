#include <iostream>
#include <cmath>
using namespace std;

float sqr(float x) {
	return x * x;
}

struct Point {
	float x, y;
};

float dist(Point p1, Point p2) {
	return sqrt(sqr(p2.x - p1.x) + sqr(p2.y - p1.y));
}

struct Triangle {
	Point p1, p2, p3;	
};

float perimeter(Triangle t) {
	return dist(t.p1, t.p2) + dist(t.p2, t.p3) + dist(t.p3, t.p1);
}

int main() {
	Point p1, p2;
	float s;

	cout << "p1 x, y> ";
	cin >> p1.x >> p1.y;
	cout << "p2 x, y> ";
	cin >> p2.x >> p2.y;

	s = sqrt(sqr(p2.x - p1.x) + sqr(p2.y - p1.y));

	cout << "s: " << s << endl;
}
