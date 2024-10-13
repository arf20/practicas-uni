#include <iostream>

using namespace std;

string tipos[] = {"naranjas", "pistachos"};

int main() {
    int N;
    cin >> N;

    string tipo;
    int distancia;
    for (int i = 0; i < N; i++) {
        cin >> tipo;
        cin >> distancia;

        bool terminamosennaranjas = (((distancia / 3) % 2) == 0) == (tipo == "naranjas");
        cout << tipos[!terminamosennaranjas] << endl;
    }
}
