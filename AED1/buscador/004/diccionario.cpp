#include "diccionario.hpp"

#include <algorithm>

// Pagina
Pagina::Pagina(std::wstring _url, std::wstring _titulo, int _rel,
    std::vector<std::wstring> _cont)
{
    url = _url;
    titulo = _titulo;
    relevancia = _rel;
    contenido = _cont;
}

std::wstring Pagina::getUrl() const {
    return url;
}

std::wstring Pagina::getTitulo() const {
    return titulo;
}

int Pagina::getRelevancia() const {
    return relevancia;
}

int Pagina::getContSize() const {
    return contenido.size();
}


// Comparador
bool comparador_paginas_url::operator()(const std::wstring& i,
    const std::wstring& d) const
{
    return i.compare(d) < 0;
}


// Diccionario
void Diccionario::insertar(const Pagina& p) {
    paginas.insert_or_assign(p.getUrl(), p);
}

std::vector<Pagina> Diccionario::consultar(const std::wstring& url) {
    std::vector<Pagina> resultado;
    for (const auto& p : paginas)
        if (p.first == url)
            resultado.push_back(p.second);
    return resultado;
}

size_t Diccionario::size() {
    return paginas.size();
}
