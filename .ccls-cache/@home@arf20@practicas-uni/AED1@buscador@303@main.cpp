#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <limits>

#include "diccionario.hpp"
#include "interprete.hpp"

int main() {
    // trabajar con UTF-8 y caracteres anchos
    std::setlocale(LC_ALL, "es_ES.UTF-8"); 

    Diccionario dic;

    std::wstring in;
    while (std::wcin >> in) {
        if (in.length() != 1) continue;
        int r = interpretar(in[0], dic);
        if (r < 0) return 1;
    }
}

