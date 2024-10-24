#include "diccionario.hpp"

#include <algorithm>
#include <iostream>

// Pagina
Pagina::Pagina(const std::wstring& _url, const std::wstring& _titulo, int _rel,
    const std::vector<std::wstring>& _cont)
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

void Pagina::setTitulo(const std::wstring& titulo) {
    this->titulo = titulo;
}

int Pagina::getRelevancia() const {
    return relevancia;
}

void Pagina::setRelevancia(int rel) {
    this->relevancia = rel;
}

int Pagina::getContSize() const {
    return contenido.size();
}

// Diccionario

size_t Diccionario::hash(const std::wstring& key) {
    size_t t = 0;
    for (auto c : key)
        t += c;
    return t % N;
}

void Diccionario::insertar(const Pagina& np) {
    auto nhash = hash(np.getUrl());
    std::cout << "hash: " << nhash << std::endl;

    auto& vec = tabla[nhash];
    for (auto it = vec.begin(); it != vec.end(); it++) {
        if (it->getUrl() == np.getUrl()) {
            auto& p = *it;
            p.setTitulo(np.getTitulo());
            p.setRelevancia(np.getRelevancia());
            return;
        }
    }
    tabla[nhash].push_back(np);
    size++;
}

std::vector<Pagina> Diccionario::consultar(const std::wstring& url) {
    std::vector<Pagina> resultado;
    for (const auto& p : tabla[hash(url)])
        if (p.getUrl() == url)
            resultado.push_back(p);
    return resultado;
}

size_t Diccionario::getTam() {
    return size;
}
