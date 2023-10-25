#include <iostream>
using namespace std;

void PrecioFinal(float precio, float impuestos, float& precio_final) {
	precio_final = precio + (precio * (impuestos / 100.0f));
}



int main() {
	float precio, impuestos, precio_final;
	cout << "Precio inicial> ";
	cin >> precio;
	cout << "Impuestos (%)> ";
	cin >> impuestos;
	PrecioFinal(precio, impuestos, precio_final);
	cout << "Precio final: " << precio_final << endl;
}

