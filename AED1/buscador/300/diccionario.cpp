#include "diccionario.hpp"

#include <algorithm>
#include <iostream>
#include <memory>

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

const std::vector<std::wstring>& Pagina::getContenido() const {
    return contenido;
}

// Diccionario

size_t Diccionario::hash(const std::wstring& key) {
    size_t t = 5381;
    for (auto c : key)
        t = ((t << 5) + t) + c;
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
    tabla[nhash].push_back(Pagina(np));
    size++;

    // insertar palabras
    for (const std::wstring& p : np.getContenido()) {
        arbol.insertar(p, tabla[nhash].end()-1);
    }
}

std::vector<Pagina> Diccionario::consultar(const std::wstring& url) {
    std::vector<Pagina> resultado;
    for (const auto& p : tabla[hash(url)])
        if (p.getUrl() == url)
            resultado.push_back(p);
    return resultado;
}

std::vector<std::vector<Pagina>::iterator>
Diccionario::buscarPalabra(const std::wstring& palabra) {
    return arbol.buscar(palabra);
}

size_t Diccionario::getTam() {
    return size;
}

// Arbol

void Arbol::insertar(const std::wstring& palabra,
    std::vector<Pagina>::iterator paginaref)
{
    auto subarbol = &raiz; // puntero porque referencia rebindeable
    std::map<char, nodo_trie_t>::iterator it;

    // extensa
    /*
    for (wchar_t c : palabra) {
        it = subarbol.find(c);
        if (it != subarbol.end())
            subarbol = it->second.hijos;
        else {
            auto nuevonodo = nodo_trie_t();
            it = subarbol.insert({c, nuevonodo}).first;
            subarbol = nuevonodo.hijos;
        }
    }
    */

    // concisa
    for (wchar_t c : palabra) {
        auto nuevonodo = nodo_trie_t();
        // solo inserta si c no existe
        it = subarbol->insert({c, nuevonodo}).first;
        subarbol = &it->second.hijos;
    }
    
    it->second.paginas.push_back(paginaref);
}

// no const ref return porque si no se encuentra resultado,
// retorna nuevo vector vacio
std::vector<std::vector<Pagina>::iterator>
Arbol::buscar(const std::wstring& palabra) {
    auto subarbol = &raiz;
    std::map<char, nodo_trie_t>::iterator it;

    for (wchar_t c : palabra) {
        auto nuevonodo = nodo_trie_t();
        it = subarbol->find(c);
        if (it == subarbol->end())
            // retornar vector vacio si no hay resultados
            return std::vector<std::vector<Pagina>::iterator>();
        
        subarbol = &it->second.hijos;
    }

    return it->second.paginas;
}
