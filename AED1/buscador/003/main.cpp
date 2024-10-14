#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <limits>


struct pagina_t {
    int relevancia;
    std::wstring url;
    std::wstring titulo;
    std::vector<std::wstring> contenido;
};




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

pagina_t leerpagina() {
    pagina_t np;
    std::wcin >> np.relevancia;
    std::wcin >> np.url;
    std::wcin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::wcin, np.titulo);

    std::wstring in;
    while ((std::wcin >> in) && (normalizarstr(in) != L"findepagina"))
        np.contenido.push_back(normalizarstr(in));

    return np;
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

int main() {
    std::setlocale(LC_ALL, "es_ES.UTF-8"); // trabajar con UTF-8 y caracteres anchos

    std::vector<pagina_t> paginas;

    std::wstring in;
    while (std::wcin >> in) {
        if (in.length() != 1) continue;
        switch (in[0]) {
            case 'i': {
                pagina_t np = leerpagina();
                paginas.push_back(np);
                std::wcout << paginas.size() << ". " << np.url << ", "
                    << np.titulo << ", Rel. " << np.relevancia << std::endl
                    << np.contenido.size() << " palabras" << std::endl;
            } break;
            case 'u': {
                std::wstring url;
                std::wcin >> url;

                std::wcout << "u " << url << std::endl
                    << "Total: 0 resultados" << std::endl;
            } break;
            case 'b': {
                std::wstring palabra;
                std::wcin >> palabra;

                std::wcout << "b " << normalizarstr(palabra) << std::endl
                     << "Total: 0 resultados" << std::endl;
            } break;
            case 'a': {
                std::vector<std::wstring> palabras = leerpalabras();

                std::wcout << "a ";
                for (auto p : palabras)
                    std::wcout << " " << p;
                std::wcout << std::endl << "Total: 0 resultados" << std::endl;
            } break;
            case 'o': {
                std::vector<std::wstring> palabras = leerpalabras();

                std::wcout << "o ";
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
                return 0;
            } break;
        }
    }
}
