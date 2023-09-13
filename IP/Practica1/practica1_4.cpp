#include <iostream>
using namespace std;

int main() {
	string name;
	float fTeoria, fPractica, fFinal;

	cout << "Introducir nombre de alumno> ";
	getline(cin, name);

	cout << "Introducir nota de teoria y practicas> ";
	cin >> fTeoria >> fPractica;
	
	fFinal = (fTeoria * 0.7) + (fPractica * 0.3);
	cout << "La nota final de " << name << " es " << fFinal << endl;
}
