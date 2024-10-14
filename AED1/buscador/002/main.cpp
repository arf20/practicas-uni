#include <iostream>

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

int main() {
    std::setlocale(LC_ALL, "es_ES.UTF-8"); // trabajar con UTF-8 y caracteres anchos

    std::wstring p;
    int i = 1;
    while (std::wcin >> p) {
        std::wcout << i << L". " << p << L" -> " << normalizarstr(p) << std::endl;
        i++;
    }
}
