#include <iostream>

using namespace std;

int numero_chars(string str, char chr) {
    int t = 0; // contador
    for (char c : str)
        if (c == chr) t++;
    return t;
}

int main() {
    int N;
    cin >> N;

    int cantidades[6];

    for (int j = 0; j < N; j++) {
        // primero, leer ingredientes
        string ingredientes;
        cin >> ingredientes;

        // cuantos ingredientes de cada tipo hay
        for (int i = 0; i < 6; i++)
            cantidades[i] = numero_chars(ingredientes, "MARGIT"[i]);

        // cuantas MARGARITA podemos construir con estos ingredientes
        // 1 m, 2 a, 2 r, 1 g, 1 i, 1 t
        cantidades[0] /= 1;
        cantidades[1] /= 3;
        cantidades[2] /= 2;
        cantidades[3] /= 1;
        cantidades[4] /= 1;
        cantidades[5] /= 1;

        // el minimo es la respuesta
        int n_margaritas = INT32_MAX;
        for (int i = 0; i < 6; i++)
            if (cantidades[i] < n_margaritas)
                n_margaritas = cantidades[i];

        cout << n_margaritas << endl;
    }
}
