#include <iostream>
using namespace std;

typedef int mat[20][20];

void scan_matrix(mat& a, int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << "[" << i << "][" << j << "]> ";
			cin >> a[i][j];
		}
	}
}

void print_matrix(mat& a, int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << "[" << i << "][" << j << "]: " << a[i][j] << endl;
		}
	}
}

void add_matrix(mat& a, mat& b, mat& r, int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			r[i][j] = a[i][j] + b[i][j];
		}
	}
}


int main() {
	mat a, b, c;
	int rows, cols;

	cout << "Rows> ";
	cin >> rows;
	cout << "Cols> ";
	cin >> cols;

	cout << "Input A:" << endl;
	scan_matrix(a, rows, cols);
	cout << "Input B:" << endl;
	scan_matrix(b, rows, cols);

	add_matrix(a, b, c, rows, cols);

	cout << "A + B:" << endl;
	print_matrix(c, rows, cols);
}
