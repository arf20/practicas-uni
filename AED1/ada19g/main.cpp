#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main() {
    int N, p;
    while (std::cin >> N) {
        std::vector<int> precios;

        for (int i = 0; i < N; i++) {
            std::cin >> p;
            precios.push_back(p);
        }

        int descuento = 0;
        for (int i = 0; i < N; i += 3) {
            int idx = std::min_element(precios.begin() + i, precios.begin() + i + 3) - precios.begin();
            descuento += precios[idx];
        }

        std::cout << descuento << std::endl;
    }
}