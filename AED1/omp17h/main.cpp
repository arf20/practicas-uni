#include <iostream>
#include <math.h>

int main() {
    int N;
    std::cin >> N;

    std::string line;
    for (int i = 0; i < N; i++) {

        int t0, t1;
        std::cin >> t0 >> t1;

        std::cout << (int)std::round(32.96 * pow(0.9512, double(t1 - t0))) << std::endl;
    }
}
