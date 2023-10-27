#include <iostream>
using namespace std;

int main() {
	int cont = 0;
	char c = 0;
	
	do {
		cin.get(c);
		cont += (c == ' ');
	}
	while (c != '\n');
	
	cout << cont << endl; 
}
