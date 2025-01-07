#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <algorithm>

struct edge_t {
    int v1, v2, dist;
};

std::vector<edge_t> read_graph(std::vector<std::string>& cities) {
    int ncities;
    std::vector<edge_t> edges;
    std::string line;

    std::cin >> ncities;

    std::cin.ignore(1024, '\n');
    for (int i = 0; i < ncities; i++) {
        std::getline(std::cin, line);
        cities.push_back(line);
    }

    while (true) {
        edge_t edge = { };

        std::cin >> edge.v1 >> edge.v2 >> edge.dist;
        if (!edge.v1 && !edge.v2 && !edge.dist)
            break;

        edges.push_back(edge);
    }

    return edges;
}

int isneigh(int u, const edge_t& e, int& dist) {
    if (e.v1 == u) {
        dist = e.dist;
        return e.v2;
    } else if (e.v2 == u) {
        dist = e.dist;
        return e.v1;
    } else return -1;
}

int mindistinq(const std::set<int>& Q, const std::vector<int> dist) {
    int mind = 999999, minu;
    for (auto u : Q) {
        if (dist[u] <= mind) {
            mind = dist[u];
            minu = u;
        }
    }
    return minu;
}

std::list<int> dijkstra(const std::vector<edge_t>& edges,
    int ncities, int src, int tgt)
{
    std::vector<int> dist(ncities, 999999), prev(ncities, -1);
    std::list<int> S;
    std::set<int> Q;
    for (int i = 0; i < ncities; i++)
        Q.insert(i);
    dist[src] = 0;

    while (!Q.empty()) {
        int u = mindistinq(Q, dist);

        if (u == tgt)
            break;

        Q.erase(u);

        for (const auto& e : edges) {
            int v, edist;
            if ((v = isneigh(u, e, edist) > 0) && (Q.find(v) != Q.end())) {
                int alt = dist[u] + edist;
                if (alt < dist[v]) {
                    dist[v] = alt;
                    prev[v] = u;
                }
            }
        }
    }

    int u = tgt;
    if (prev[u] > 0 || u == src) {
        while (u > 0) {
            S.push_front(u);
            u = prev[u];
        }
    }

    return S;
}

int main() {
    int cases;
    
    std::cin >> cases;

    for (int i = 0; i < cases; i++) {
        std::vector<std::string> cities;
        auto graph = read_graph(cities);

        auto path = dijkstra(graph, cities.size(), 0, cities.size() - 1);

    }


}

