#include <iostream>
using namespace std;

constexpr int size_max = 100;
typedef float vec[size_max];

void read_vec(vec &v, int n) {
	for (int i = 0; i < n; i++) {
		cout << "v[" << i << "] = ";
		cin >> v[i];
	}
}

int main() {
	int i, n;
	vec a, b;
	
	cout << "Input n> ";
	cin >> n;
	cout << "Vector a> " << endl;
	read_vec(a, n);
	cout << "Vector b> " << endl;
	read_vec(b, n);

	float dot_product = 0.0f;
	for (int i = 0; i < n; i++)
		dot_product += a[i] * b[i];

	cout << "Dot product: " << dot_product << endl;
}
