#include <iostream>
using namespace std;

constexpr int matmax = 10;
typedef int mat[matmax][matmax];

void leer_tabla(mat& a, int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << "[" << i << "][" << j << "]> ";
			cin >> a[i][j];
		}
	}

}


int main() {
	int rows, cols;
	mat a;

	cout << "Rows> ";
	cin >> rows;
	cout << "Cols> ";
	cin >> cols;

	leer_tabla(a, rows, cols);
	
	int rowmaxsum = 0;
	for (int i = 0; i < rows; i++) {
		int rowmax = 0;
		for (int j = 0; j < cols; j++) {
			if (a[i][j] > rowmax) rowmax = a[i][j];

		}
		rowmaxsum += rowmax;
		cout << "row " << i << " max: " << rowmax << endl;
	}

	cout << "row max sum: " << rowmaxsum << endl;
}
