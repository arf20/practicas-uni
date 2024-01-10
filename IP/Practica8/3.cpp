#include <iostream>
using namespace std;

int main() {
	const int n = 8;
	int notas[n] = { 2, 7, 6, 7, 7, 8, 5, 0 };
	int freqs[11] = { };

	for (int i = 0; i < n; i++)
		freqs[notas[i]]++;


	cout << "Notas: ";
	for (int i = 0; i < n; i++)
		cout << notas[i] << " ";
	cout << endl << "Frecuencias: ";
	for (int i = 0; i < 11; i++) 
		cout << freqs[i] << " ";
	cout << endl;
}
