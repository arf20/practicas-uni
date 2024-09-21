#include <iostream>

using namespace std;

string meses[] = {"Aug", "Sep", "Oct", "Nov", "Dec"};

int main() {
    while (true) {
        int dia;
        cin >> dia;
        if (dia == 0) return 0;

        string mes;
        cin >> mes;

        int mes_num;
        for (int i = 0; i < 5; i++)
            if (mes == meses[i])
                mes_num = i + 8;

        int meses_restantes = 12 - mes_num;

        int dias_restantes = 0;
        switch (meses_restantes) {
            case 0: dias_restantes = 21 - dia; break;
            case 1: dias_restantes = 30 + 21 - dia; break;
            case 2: dias_restantes = 31 + 30 + 21 - dia; break;
            case 3: dias_restantes = 30 + 31 + 30 + 21 - dia; break;
            case 4: dias_restantes = 31 + 30 + 31 + 30 + 21 - dia; break;
        }

        if (dias_restantes <= 0) {
            cout << "Winter is here" << endl;
        } else {
            cout << dias_restantes << " days to winter" << endl;
        }
    }
}
