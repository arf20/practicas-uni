#include <iostream>
#include <math.h>
using namespace std;

int main(){
    while(true){
        int A;
        cin >> A;
        if (A==0){
            return 0;
        }
        int cont = 0;
        for(int i=1; i<=A; i++){
            double raiz = sqrt(i);
            if(trunc(raiz) == raiz){
                cont++;
            }
        }
        int orden = log10(cont);
        cont = (cont / (int)pow(10, orden)) * (int)pow(10, orden);
        cout << cont << endl;
    }
    return 0;
}
