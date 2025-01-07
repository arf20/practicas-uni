#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

// root node = 1
// day = 100 slots

constexpr int slotsperday = 100;

struct pair_t {
    int nod1, nod2;
    std::vector<int> meetslots;
};

std::vector<pair_t> read_graph(int& nnodes) {
    int npairs, nmeets, meetslot;
    std::vector<pair_t> pairs;
    std::cin >> nnodes >> npairs;
    for (int i = 0; i < npairs; i++) {
        pair_t pair = { };

        std::cin >> pair.nod1 >> pair.nod2 >> nmeets;

        for (int j = 0; j < nmeets; j++) {
            std::cin >> meetslot;
            pair.meetslots.push_back(meetslot);
        }

        pairs.push_back(pair);
    }

    return pairs;
}

bool checkisolated(const std::vector<pair_t>& pairs, int nnodes) {
    std::set<int> connnodes;
    connnodes.insert(1); // root node
    int p0 = 0, p1 = 1;
    while (p0 != p1) {
        for (int nod = 2; nod <= nnodes; nod++) { // rests of nodes
            if (connnodes.find(nod) != connnodes.end())
                continue;
            for (const auto& pair : pairs) {
                if (connnodes.find(pair.nod1) != connnodes.end() ||
                    connnodes.find(pair.nod2) != connnodes.end())
                {
                    connnodes.insert(pair.nod1);
                    connnodes.insert(pair.nod2);
                }
            }
        }

        p0 = p1;
        p1 = connnodes.size();
    }

    return (int)connnodes.size() != nnodes;
}

bool checkupdate(const std::vector<bool>& nodeupdated) {
    return std::find(nodeupdated.begin(), nodeupdated.end(), false)
        == nodeupdated.end();
}

int sim(std::vector<pair_t>& pairs, int nnodes) {
    int slot = 0;
    std::vector<bool> nodeupdated(nnodes, false);
    nodeupdated[0] = true; // root

    while (!checkupdate(nodeupdated)) {
        if (slot > 10000)           // todo mal, esto mal, lo sé, fatal
            return -1;
        int c = -1;
        while (c != 0) {
            c = 0;
            for (const auto& pair : pairs) {
                if ((nodeupdated[pair.nod1-1] || nodeupdated[pair.nod2-1]
                    && std::find(pair.meetslots.begin(),
                        pair.meetslots.end(), slot % slotsperday)
                    != pair.meetslots.end())
                {
                    if (nodeupdated[pair.nod1-1] !=
                        nodeupdated[pair.nod2-1])
                    {
                        c++;
                        nodeupdated[pair.nod1-1] =
                            nodeupdated[pair.nod2-1] = true;
                    }
                }
            }
        }

#ifdef _DEBUG_
        std::cout << slot << "\t";
        for (const auto& n : nodeupdated)
            std::cout << n << " ";
        std::cout << std::endl;
#endif

        slot++;
    }

    return slot - 1;
}

int main() {
    int cases;
    
    std::cin >> cases;

    for (int i = 0; i < cases; i++) {
        int nnodes;
        auto pairs = read_graph(nnodes);
        /*if (checkisolated(pairs, nnodes)) { // no funciona, no hay tiempo
            std::cout << "-1" << std::endl;
            continue;
        }*/

#ifdef _DEBUG_
        for (const auto& p : pairs)
            std::cout << "<" << p.nod1 << ", " << p.nod2 << ">, ";
        std::cout << std::endl;
#endif

        std::cout << sim(pairs, nnodes) << std::endl;
    }
}

