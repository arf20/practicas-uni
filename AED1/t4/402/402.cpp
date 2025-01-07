#include <iostream>
#include <queue>

constexpr int MAX_NOD = 26;

bool ma[MAX_NOD][MAX_NOD] = { };
bool checked[MAX_NOD] = { };

void clear_ma() {
    for (int y = 0; y < MAX_NOD; y++)
        for (int x = 0; x < MAX_NOD; x++)
            ma[x][y] = false;
}

void read_graph(int A) {
    clear_ma();

    char X, Y;
    for (int j = 0; j < A; j++) {
        std::cin >> X >> Y;
        ma[X - 'A'][Y - 'A'] = true;
    }
}

bool exists(int v) {
    for (int i = 0; i < MAX_NOD; i++)
        if (ma[v][i] || ma[i][v]) return true;
    return false;
}

void bpa(int N, int v) {
    std::queue<int> C;
    checked[v] = true;

    std::cout << char(v + 'A');

    C.push(v);

    while (!C.empty()) {
        int x = C.front();
        C.pop();
        for (int y = 0; y < N; y++) {
            if (ma[x][y] && !checked[y]) {
                checked[y] = true;
                C.push(y);
                std::cout << char(y + 'A');
            }
        }
    }
}

void wide_search(int N) {
    for (int i = 0; i < MAX_NOD; i++)
        checked[i] = false;
    
    for (int i = 0; i < N; i++)
        if (!checked[i])
            ws(N, i);
    std::cout << std::endl;
}

int main() {
    int T, N, A;
    
    std::cin >> T;

    for (int i = 0; i < T; i++) {
        std::cin >> N >> A;
        read_graph(A);
        wide_search(N);
    }
}



