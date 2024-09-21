#include <iostream>
#include <vector>
#include <limits>
#include <sstream>
#include <algorithm>

using namespace std;

vector<string> notas = { "do", "re", "mi", "fa", "sol", "la", "si" };

int modulo7(int x) {
    if (x > 6) return x -= 7;
    if (x < 0) return x += 7;
    return x;
}

int main() {
    int N = 0;

    cin >> N;
    

    // vector es un tipo contenedor, en este caso contiene strings, que es un tipo primitivo
    // vector es una clase generica, es decir tiene un template, que se especifica su tipo con lo que hay entre < >; es como una lista enlazada de TP
    vector<string> casos;

    string linea;
    for (int i = 0; i < N;) {
        getline(cin, linea);
        if (!linea.empty()) {
            casos.push_back(linea);
            i++;
        }
    }


    for (string caso : casos) {
        stringstream stream(caso);

        int escala = 0;
        int nota_count = 0;
        string nota, nota_anterior;
        while (stream >> nota) {
            nota_count++;
            if (nota_anterior.empty()) {
                nota_anterior = nota;
                continue;
            }

            auto it = find(notas.begin(), notas.end(), nota);
            if (it == notas.end()) {
                cout << "nota no reconocida" << endl;
                continue;
            }
            int idx = distance(notas.begin(), it);

            it = find(notas.begin(), notas.end(), nota_anterior);
            if (it == notas.end()) {
                cout << "nota no reconocida" << endl;
                continue;
            }
            int idx_ant = distance(notas.begin(), it);

            if (modulo7(idx_ant + 1) == idx) {
                // ascendiente
                if (escala != 0) {
                    if (escala != 1) {
                        escala = 0;
                        break;
                    }
                } else escala = 1;
            } else if (modulo7(idx_ant - 1) == idx) {
                // descendiente
                if (escala != 0) {
                    if (escala != -1) {
                        escala = 0;
                        break;
                    }
                } else escala = -1;
            } else {
                escala = 0;
                break;
            }

            nota_anterior = nota;

            
        }

        if (nota_count == 1) escala = 1;

        switch (escala) {
            case 0: cout << "no hay escala" << endl; break;
            case 1: cout << "escala ascendente" << endl; break;
            case -1: cout << "escala descendente" << endl; break;
        }
    }
}
