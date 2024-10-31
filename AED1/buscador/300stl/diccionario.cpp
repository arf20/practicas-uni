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

std::vector<std::wstring> Pagina::getContenido() const {
    return contenido;
}

// Diccionario
void Diccionario::insertar(const Pagina& p) {
    const auto& pagref = paginas.insert_or_assign(p.getUrl(), p).first;

    // esto es un tipo real que existe, a estas alturas debería hacer typedefs xd
    std::unordered_map<
        std::wstring,
        std::vector<
            std::unordered_map<
                std::wstring,
                Pagina
            >::iterator
        >
    >::iterator it;

    for (const std::wstring& palabra : p.getContenido()) {
        it = palabras.find(palabra);
        if (it == palabras.end()) {
            it = palabras.insert({palabra, std::vector<std::unordered_map<std::wstring, Pagina>::iterator>()}).first;
        }

        it->second.push_back(pagref);
    }
}

std::optional<Pagina>
Diccionario::consultar(const std::wstring& url) const {
    auto it = paginas.find(url);
    if (it == paginas.end()) return {};
    return it->second;
}

size_t Diccionario::size() const {
    return paginas.size();
}

std::vector<std::unordered_map<std::wstring, Pagina>::iterator>
Diccionario::buscarPalabra(const std::wstring& palabra) const {
    const auto& it = palabras.find(palabra);
    if (it == palabras.end())
        return std::vector<std::unordered_map<std::wstring, Pagina>::iterator>();
    else
        return it->second;
}
