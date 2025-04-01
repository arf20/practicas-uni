#include <iostream>
#include <vector>
#include <limits>
#include <tuple>

constexpr int n = 3;    // num objetos
constexpr int m = 6;    // capacidad mochila
const std::vector<int> p = {2, 3, 4}, b = {1, 2, 5};

// PASO 1: descomposición recurrente
// k: objeto
// c: capacidad restante
// beneficio Mochila(k, c)
// caso base: si k o c son 0
//  Mochila(k, c) = 0
// si k o c < 0
//  Mochila(k, c) = -inf
// si se coje el objeto k
//  Mochila(k, c) = b_k + Mochila(k - 1, c - p_k)
// si no
//  Mochila(k, c) = Mochila(k - 1, c)
// optimo: max entre los dos
//  max(Mochila(k - 1, c), Mochila(k - 1, c - p_k))
//

// PASO 2: rellenar tabla

std::vector<std::vector<int>> rellenar_tabla() {
    // todo ceros (caso base 0s)
    std::vector<std::vector<int>> V(n + 1, std::vector<int>(m + 1, 0)); 

    for (int k = 1; k <= n; k++) {      // objeto
        for (int c = 1; c <= m; c++) {  // capacidad
            int bno = V[k - 1][c];
            int byes = (c - p[k - 1] >= 0) ? b[k - 1] + V[k - 1][c - p[k - 1]] : std::numeric_limits<int>::min();
            V[k][c] = std::max(bno, byes);
        }
    }

    return V;
}

// PASO 3: recomponer solucion optima

std::pair<int, std::vector<int>> recomponer_solucion(const std::vector<std::vector<int>> V) {
    int c = m;
    std::vector<int> x(n, 0);
    for (int k = n; k >= 1; k--) {
        if (V[k][c] == b[k - 1] + V[k - 1][c - p[k - 1]]) {
            // se ha cogido
            x[k - 1] = 1;
            c -= p[k - 1];
        }
    }

    return {V[n][m], x};
}

std::pair<int, std::vector<int>> mochila01_paso3_reconstruir_solucion(const std::vector<std::vector<int>>& V) {
    int k_actual = n;
    int m_actual = m;
    std::vector<int> S(n, 0); // S es inicializado a ceros
    while (k_actual > 0) {
        int m1 = (m_actual - p[k_actual - 1] >= 0) ? b[k_actual - 1] + V[k_actual - 1][m_actual -
            p[k_actual - 1]] : std::numeric_limits<int>::min();
        int m2 = V[k_actual - 1][m_actual];
        if (m1 != m2) {
            S[k_actual - 1] = 1;
            m_actual -= p[k_actual - 1];
        }
        //else... S ha sido inicializado a ceros
        k_actual--;
    }
    return {V[n][m], S};
}


int main() {
    auto V = rellenar_tabla();

    for (int k = 0; k <= n; k++) {      // objeto
        for (int c = 0; c <= m; c++) {  // capacidad
            std::cout << V[k][c] << ", ";
        }
        std::cout << std::endl;
    }

    //auto sol = recomponer_solucion(V);
    auto sol = recomponer_solucion(V);
    std::cout << "max val: " << sol.first << std::endl;
    for (auto& i : sol.second) {
        std::cout << i << ", ";
    }
    std::cout << std::endl;
}

