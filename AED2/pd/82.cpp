#include <iostream>
#include <vector>

int count = 0;

unsigned int factorial(unsigned int n) {
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}

// O(2^n)
int combinaciones(int n, int m) {
    count++;
    if (m == 0 || m == n)
        return 1;
    else if (0 < m && m < n) {
        return combinaciones(n - 1, m) + combinaciones(n - 1, m - 1);
    } else return -1;
}

std::vector<std::vector<int>> pascal(int n) {
    std::vector<std::vector<int>> tri;
    for (int row = 0; row <= n; row++) {
        std::vector<int> aux;
        for (int i = 0; i <= row; i++) {
            if (i == 0 || i == row)
                aux.push_back(1);
            else
                aux.push_back(tri[row-1][i-1] + tri[row-1][i]);
        }
        tri.push_back(aux);
    }
    return tri;
}

int main() {
    int n = 6, m = 3;
    std::cout << combinaciones(n, m) << " " << factorial(n)/(factorial(m)*factorial(n-m)) << " " << count << std::endl;

    auto tri = pascal(n);
    for (auto& row : tri) {
        for (auto& x : row)
            std::cout << x << " ";
        std::cout << std::endl;
    }
    std::cout << tri[n][m] << std::endl;
}

