#include <iostream>
#include <vector>

constexpr int n = 3, m = 6;
constexpr std::vector<int> p = {2, 3, 4}, b = {1, 2, 5};

// PASO 1: descomposición recurrente
// k: objeto
// c: capacidad restante
// beneficio Mochila(k, c)
// caso base: si k o c son 0
//  Mochila(k, c) = 0
// si k o c < 0
//  Mochila(k, c) = -inf
// si se coje el objeto k
//  Mochila(k, c) = b[k] + Mochila(k - 1, c - p[k])
// si no
//  Mochila(k, c) = Mochila(k - 1, c)
// optimo: max entre los dos
//  max(Mochila(k - 1, c), Mochila(k - 1, c - p[k]))

// PASO 2: rellenar tabla

std::vector<std::vector<int>> rellenar_tabla() {
    // todo ceros (caso base 0s)
    std::vector<std::vector<int>> V(n + 1, std::vector<int>(m + 1, 0)); 

    for (int k = 0; k < 
}


int main() {

}

