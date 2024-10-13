#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main() {
    int N, M, P;
    std::vector<int> V;

    std::cin >> N;

    for (int i = 0; i < N; i++) {
        std::cin >> M;

        for (int j = 0; j < M; j++) {  
            std::cin >> P;
            V.push_back(P);
        }

        INT32_MAX
        std::sort(V.begin(), V.end(), std::greater<>());

        int votos_totales = std::accumulate(V.begin(), V.end(), 0);
        int votos_count = 0;
        for (int j = 0; j < V.size(); j++) {
            votos_count += V[j];
            if (votos_count > (votos_totales / 2)) {
                std::cout << "Case " << i + 1 << ": " << j + 1 << " planets" << std::endl;
                break;
            }
        }

        V.clear();
    }
}
