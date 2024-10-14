#include <iostream>

int main() {
    std::string p;
    int i = 1;
    while (std::cin >> p) {
        std::cout << i << ". " << p << std::endl;
        i++;
    }
}
