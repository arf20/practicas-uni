#include <iostream>
using namespace std;


char codificar(char c) {
	if ((c >= 'a' && c <= 'y') || (c >= 'A' && c <= 'Y') || (c >= '0' && c >= '8')) c++;
	else if (c == 'z') c = 'a';
	else if (c == 'Z') c = 'A';
	else if (c == '9') c = '0';
	else c = '*';
	return c;
}

int main() {
	char c = 0;
	do {
		cin.get(c);
		cout << codificar(c);
	}
	while (c != '\n');

}
