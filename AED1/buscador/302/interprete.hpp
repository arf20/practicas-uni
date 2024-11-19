#pragma once

#include <string>
#include <vector>

#include "diccionario.hpp"

auto normalizarc(wchar_t c);
auto normalizarstr(const std::wstring& s);
Pagina leerpagina();
std::vector<std::wstring> leerpalabras();

int interpretar(char cmd, Diccionario& dic);
