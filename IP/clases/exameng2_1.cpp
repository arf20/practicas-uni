#include <iostream>
using namespace std;

struct Fecha {
	int d, m, y;
};

bool ComienzoEstacion(Fecha f) {
	return (f.d == 20 && f.m == 3)
	|| (f.d == 21 && f.m == 6)
	|| (f.d == 23 && f.m == 9)
	|| (f.d == 21 && f.m == 12);
}

int main() {
	Fecha f;
	cout << "Dia> ";
	cin >> f.d;
	cout << "Mes> ";
	cin >> f.m;
	cout << "Año> ";
	cin >> f.y;
	
	// Opcion 1 (guay)
	cout << (ComienzoEstacion(f) ? "Es principio de estación." : "No es principio de estación") << std::endl;
	
	// Opcion 2 (noob)
	if (ComienzoEstacion(f)) cout << "Es principio de estación.";
	else cout << "No es principio de estación.";
	cout << endl;
	

}
