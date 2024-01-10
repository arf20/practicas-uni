#include <iostream>
using namespace std;

constexpr int n = 10;

int main() {
	float vec[n] {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int aux;

	// rotate right
	aux = vec[n-1];
	for (int i = n-1; i > 0; i--)
		vec[i] = vec[i-1];
	vec[0] = aux;

	for (int i = 0; i < n; i++)
		cout << vec[i] << " ";
	cout << endl;
}
