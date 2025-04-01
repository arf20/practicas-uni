#include <iostream>
#include <vector>
#include <cmath>

const std::vector<int> A = {2, 3, 5, 2};
const int K = 7;

int main() {
    std::cout << "A: ";
    for (int k = 0; k < A.size(); k++)
        std::cout << A[k] << " ";
    std::cout << std::endl << "K: " << K << std::endl << "naive" << std::endl;

    // naive
    for (int i = 0; i < std::pow(2, A.size()); i++) {
        int sum = 0;
        for (int j = 0; j < A.size(); j++) {
            if ((i >> j) & 1) {
                sum += A[j];
                std::cout << A[j] << " ";
            }
        }
        std::cout << ": " << sum << (sum == K ? " yes" : " no") << std::endl;
    }

    // paso 1
    // suma suma_exacta(k, r)
    //  si k o r es 0: 0
    //  si k o r < 0: -inf
    //  si se coje k:
    //      suma_exacta(k, r) = A[k] + suma_exacta(k - 1, r - A[k])
    //  si no
    //      suma_exacta(k, r) = suma_exacta(k - 1, r)

    std::cout << "dinamica" << std::endl;
    // paso 2: rellenar tabla
    std::vector<std::vector<int>> V(A.size() + 1, std::vector<int>(K + 1, 0));
    for (int k = 1; k <= A.size(); k++) {
        for (int r = 1; r <= K; r++) {
            int no = V[k - 1][r];
            int si = A[k - 1] + V[k - 1][r - A[k - 1]];
            V[k][r] = (si <= K) ? si : no;
        }
    }

    for (int k = 0; k <= A.size(); k++) {
        for (int r = 0; r <= K; r++)
            std::cout << V[k][r] << " ";
        std::cout << std::endl;
    }

    // paso 3
    int r = K;
    std::vector<int> S(A.size(), 0);
    for (int k = A.size(); k > 0; k--) {
        if (V[k][r] == A[k - 1] + V[k - 1][r - A[k - 1]]) {
            r -= A[k - 1];
            S[k - 1] = 1;
        }
    }

    for (int k = 0; k < A.size(); k++)
        std::cout << S[k] << "(" << A[k] << ") ";
    std::cout << ": " << V[A.size()][K] << std::endl;
}
