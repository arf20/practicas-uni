#include <iostream>
#include <vector>
#include <stack>
#include <sstream>
#include <utility>

constexpr int MAX_NOD = 26;

std::vector<std::pair<std::vector<int>, bool>> read_graph() {
    int n, a;
    std::string line;
    auto al = std::vector<std::pair<std::vector<int>, bool>>();
    std::cin >> n;
    std::cin.ignore(1024, '\n'); 
    for (int i = 0; i < n; i++) {
        std::pair<std::vector<int>, bool> as;
        as.second = false;
        std::getline(std::cin, line);
        std::stringstream ss(line);
        while (ss >> a)
            as.first.push_back(a - 1);
        al.push_back(as);
    }

    return al;
}

bool bpp(std::vector<std::pair<std::vector<int>, bool>>& al,
    std::vector<int>& path, int v)
{
    al[v].second = true;
    path.push_back(v);
    if (v == (int)al.size() - 1)
        return false;
    for (auto& a : al[v].first) {
        if (!al[a].second) {
            if (!bpp(al, path, a))
                return false;
            path.push_back(v);
        }
    }
    return true;
}

std::vector<int> search(std::vector<std::pair<std::vector<int>, bool>>& al) {
    std::vector<int> path;
    bpp(al, path, 0);
    return path;
}

int main() {
    int T;
    
    std::cin >> T;

    /* leer grafo */
    for (int i = 0; i < T; i++) {
        auto al = read_graph();

        auto path = search(al);

        std::cout << "Caso " << i + 1 << std::endl;

        if (!al.back().second)
            std::cout << "INFINITO" << std::endl;
        else {
            std::cout << path.size() << std::endl;
            for (int p : path)
                std::cout << p + 1 << std::endl;
        }
        
    }


}

