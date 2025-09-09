#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <climits>
#include <cmath>
using namespace std;

int n;
vector<int> pesos;
vector<int> s; // tupla solución: s[i] ∈ {-1, 0, 1}
vector<int> sINICIAL;

int nivel;
int sumA, sumB;
int mejor_dif;
int mejorA, mejorB;
int voa;
bool fin = false;



// Subprogramas
void Generar(int nivel) {
    if (s[nivel] == 0)
        sumA -= pesos[nivel];
    else if (s[nivel] == 1)
        sumB -= pesos[nivel];

    s[nivel]++;
    if (s[nivel] == 0)
        sumA += pesos[nivel];
    else if (s[nivel] == 1)
        sumB += pesos[nivel];
}

bool Solucion(int nivel) {
    return nivel == n - 1 && abs(count(s.begin(), s.end(), 0) - count(s.begin(), s.end(), 1)) <= 1;
}

bool Criterio(int nivel) {
    int diff = abs(sumA - sumB);
    int restantes = accumulate(pesos.begin() + nivel, pesos.end(), 0);
    int eq0 = count(s.begin(), s.end(), 0);
    int eq1 = count(s.begin(), s.end(), 1);
    return (restantes > diff) && (abs(eq0 - eq1) < n - nivel);
}

bool MasHermanos(int nivel) {
    return s[nivel] < 1;
}

void Retroceder() {
    if (s[nivel] == 0)
        sumA -= pesos[nivel];
    else if (s[nivel] == 1)
        sumB -= pesos[nivel];

    s[nivel] = -1;
    nivel--;
}

void Evaluar() {
    int diff = abs(sumA - sumB);
    if (diff < mejor_dif) {
        mejor_dif = diff;
        mejorA = min(sumA, sumB);
        mejorB = max(sumA, sumB);
    }
}

void Backtracking() {
    nivel = 0;
    s = sINICIAL;
    sumA = sumB = 0;
    mejor_dif = INT_MAX;
    voa = INT_MAX;
    mejorA = mejorB = 0;
    fin = false;

    do {
        Generar(nivel);
        if (Solucion(nivel)) {
            Evaluar();

            // Retroceder si ya no hay más hermanos que probar
            while (!MasHermanos(nivel) && nivel >= 0) {
                Retroceder();
            }

        } else if (Criterio(nivel)) {
            nivel++;
        } else {
            while (!MasHermanos(nivel) && nivel >= 0) {
                Retroceder();
            }
        }
    } while (nivel >= 0);
    
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        pesos.resize(n);
        for (int i = 0; i < n; i++) cin >> pesos[i];

        // ordenar para poda efectiva
        sort(pesos.begin(), pesos.end(), greater<int>());

        s.resize(n, -1);
        sINICIAL = s;

        Backtracking();
        cout << mejorA << " " << mejorB << endl;
    }
    return 0;
}
