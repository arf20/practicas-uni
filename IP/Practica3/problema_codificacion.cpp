#include <iostream>
using namespace std;

int main() {
	char c;
	cout << "c> ";
	cin >> c;

	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
		c++;
		if (c - 1 == 'Z') c = 'A';
		else if (c - 1 == 'z') c = 'a';
		else if (c - 1 == '9') c = '0';
	}
	else c = '*';

	cout << c << endl;
}
