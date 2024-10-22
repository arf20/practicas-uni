#include "diccionario.hpp"

#include <algorithm>

// Pagina
Pagina::Pagina(const std::wstring& _url, const std::wstring& _titulo, int _rel,
    const std::vector<std::wstring>& _cont)
{
    url = _url;
    titulo = _titulo;
    relevancia = _rel;
    contenido = _cont;
}

const std::wstring& Pagina::getUrl() const {
    return url;
}

const std::wstring& Pagina::getTitulo() const {
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

std::optional<Pagina>
Diccionario::consultar(const std::wstring& url) {
    auto it = paginas.find(url);
    if (it == paginas.end()) return {};
    return it->second;
}

size_t Diccionario::size() {
    return paginas.size();
}
