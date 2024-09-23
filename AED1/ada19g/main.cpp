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

        std::sort(precios.begin(), precios.end());

        int descuento = std::accumulate(precios.begin(), precios.begin() + (precios.size() / 3), 0);

        std::cout << descuento << std::endl;
    }
}
