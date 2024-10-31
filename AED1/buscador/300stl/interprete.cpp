#include "interprete.hpp"

#include <iostream>
#include <limits>
#include <sstream>

#include "diccionario.hpp"

auto normalizarc(wchar_t c) {
    c = std::tolower(c); // convierte solo ASCII-7
    
    if (c == L'Ñ') c = L'ñ';

    if (c == L'Á') c = 'a';
    if (c == L'É') c = 'e';
    if (c == L'Í') c = 'i';
    if (c == L'Ó') c = 'o';
    if (c == L'Ú') c = 'u';
    if (c == L'Ü') c = 'u';

    if (c == L'á') c = 'a';
    if (c == L'é') c = 'e';
    if (c == L'í') c = 'i';
    if (c == L'ó') c = 'o';
    if (c == L'ú') c = 'u';
    if (c == L'ü') c = 'u';
    return c;
}

auto normalizarstr(const std::wstring& s) {
    std::wstring o;
    for (auto c : s)
        o += normalizarc(c);
    return o;
}

Pagina leerpagina() {
    int rel;
    std::wstring url, titulo;
    std::vector<std::wstring> contenido;

    std::wcin >> rel;
    std::wcin >> url;
    std::wcin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::wcin, titulo);

    std::wstring in;
    while ((std::wcin >> in) && (normalizarstr(in) != L"findepagina"))
        contenido.push_back(normalizarstr(in));

    return Pagina(url, titulo, rel, contenido);
}

std::vector<std::wstring> leerpalabras() {
    std::vector<std::wstring> palabras;
    std::wstring palabrasstr;
    std::getline(std::wcin, palabrasstr);

    palabrasstr = normalizarstr(palabrasstr);

    auto ss = std::wstringstream(palabrasstr);
    std::wstring palabra;
    
    while (ss >> palabra)
        palabras.push_back(palabra);

    return palabras;
}

int interpretar(char cmd, Diccionario& dic) {
    switch (cmd) {
        case 'i': {
            Pagina np = leerpagina();
            dic.insertar(np);
            std::wcout << dic.size() << ". " << np.getUrl() << ", "
                << np.getTitulo() << ", Rel. " << np.getRelevancia()
                << std::endl << np.getContSize() << " palabras" << std::endl;
        } break;
        case 'u': {
            std::wstring url;
            std::wcin >> url;

            auto p = dic.consultar(url);
            
            if (p.has_value()) {
                std::wcout << "u " << url << std::endl;
                    std::wcout << "1. " << p.value().getUrl() << ", "
                        << p.value().getTitulo() << ", Rel. "
                        << p.value().getRelevancia() << std::endl;
                std::wcout << "Total: 1 resultados" << std::endl;
            } else {
                std::wcout << "u " << url << std::endl 
                    << "Total: 0 resultados" << std::endl;
            }
            
        } break;
        case 'b': {
            std::wstring palabra;
            std::wcin >> palabra;
            palabra = normalizarstr(palabra);

            const auto& paginas = dic.buscarPalabra(palabra);

            std::wcout << "b " << palabra << std::endl;
            for (size_t i = 0; i < paginas.size(); i++) {
                std::wcout << i + 1 << ". " <<  paginas[i]->second.getUrl() << ", "
                    << paginas[i]->second.getTitulo() << ", Rel. "
                    << paginas[i]->second.getRelevancia() << std::endl;
            }
            std::wcout << "Total: " << paginas.size() << " resultados"
                << std::endl;
        } break;
        case 'a': {
            std::vector<std::wstring> palabras = leerpalabras();

            std::wcout << "a";
            for (auto p : palabras)
                std::wcout << " " << p;
            std::wcout << std::endl << "Total: 0 resultados" << std::endl;
        } break;
        case 'o': {
            std::vector<std::wstring> palabras = leerpalabras();

            std::wcout << "o";
            for (auto p : palabras)
                std::wcout << " " << p;
            std::wcout << std::endl << "Total: 0 resultados" << std::endl;
        } break;
        case 'p': {
            std::wstring prefijo;
            std::wcin >> prefijo;

            std::wcout << "p " << normalizarstr(prefijo) << std::endl
                    << "Total: 0 resultados" << std::endl;
        } break;
        case 's': {
            std::wcout << "Saliendo..." << std::endl;
            return -1;
        } break;
        default: return 1;
    }
    return 0;
}
