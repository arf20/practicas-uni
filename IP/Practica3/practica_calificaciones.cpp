#include <iostream>
using namespace std;


int main() {
	float a, b, c, f;
	cin >> a;
	cin >> b;
	cin >> c;
	
	f = (a * 0.5f) + (b * 0.3f) + (c * 0.2f);

	if (f < 5.0f) cout << "Suspenso" << endl;
	else if (f < 7.0f) cout << "Aprobado" << endl;
	else if (f < 9.0f) cout << "Notable" << endl;
	else if (f < 10.0f) cout << "Sobresaliente" << endl;
	else if (f == 10.0f) cout << "M. de honor" << endl;


}
