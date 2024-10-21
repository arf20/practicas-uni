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

int Diccionario::hash(const std::wstring& key) {
    int t = 0;
    for (auto c : key)
        t += c;
    return t % N;
}

void Diccionario::insertar(const Pagina& np) {
    auto& vec = tabla[hash(np.getUrl())];
    for (auto it = vec.begin(); it != vec.end(); it++) {
        if (it->getUrl() == np.getUrl()) {
            auto& p = *it;
            p.setTitulo(np.getTitulo());
            p.setRelevancia(np.getRelevancia());
            return;
        }
    }
    tabla[hash(np.getUrl())].push_back(np);
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
