#include <iostream>

using namespace std;

int factorial(int n) {
    int f = 1;
    for (int i = 2; i <= n; i++) {
        f *= i;
    }
    return f;
}

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int n;
        cin >> n;
        

        int total = factorial(n);

        cout << total / n << "/" << total << endl;
    }
}

// hay 8
// 7*6*5*4*3*2*1

// 
