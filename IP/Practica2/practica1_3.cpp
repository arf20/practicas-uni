#include <iostream>
using namespace std;

int main() {
	// entrada: recorrido, combustible, precio_combustible, mantenimiento
	// salido: coste
	
	float recorrido, combustible, precio_combustible, mantenimiento;
	cout << "recorrido (km)> ";
	cin >> recorrido;
	cout << "combustible (L)> ";
	cin >> combustible;
	cout << "precio combustibe (€/L)> ";
	cin >> precio_combustible;
	cout << "mantenimiento (€/km)> ";
	cin >> mantenimiento;

	float coste = recorrido * mantenimiento * combustible * precio_combustible;

	cout << coste << " €" << endl;

	return 0;
}
