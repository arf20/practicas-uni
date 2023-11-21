#include <iostream>
using namespace std;

int main() {
	constexpr char dist = 'a' - 'A';
	char c;
	while (cin.get(c) && c != '#') {
		if (c == ' ' || c == '\n' || (c >= '0' && c <= '9')) cout << c;
		else cout << char(c - dist);
	}
}
