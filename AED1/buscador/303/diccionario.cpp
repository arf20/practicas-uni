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

void Pagina::setContenido(const std::vector<std::wstring>& palabras) {
    contenido = palabras;
}


// Clase referencia a pagina

PagListIt::PagListIt(std::list<Pagina>::const_iterator& it)
    : std::list<Pagina>::const_iterator(it)
{

}

bool PagListIt::operator<(const PagListIt& r) const {
    if ((*this)->getRelevancia() != r->getRelevancia())
        return (*this)->getRelevancia() > r->getRelevancia();
    else return (*this)->getUrl() < r->getUrl();
}

// Diccionario

size_t Diccionario::hash(const std::wstring& key) {
    size_t t = 5381;
    for (auto c : key)
        t = ((t << 5) + t) + c;
    return t % N;
}

void insertar_palabras(const std::vector<std::wstring>& palabras,
    const std::list<Pagina>::iterator& pagref, Arbol& arbol)
{
    for (const std::wstring& p : palabras) {
        arbol.insertar(p, (const PagListIt&)pagref);
    }
}

void Diccionario::insertar(const Pagina& np) {
    auto nhash = hash(np.getUrl());

    std::list<Pagina>::iterator it;

    auto& vec = tabla[nhash];
    for (it = vec.begin(); it != vec.end(); it++) {
        if (it->getUrl() == np.getUrl()) {
            auto& p = *it;
            p.setTitulo(np.getTitulo());
            p.setRelevancia(np.getRelevancia());
            p.setContenido(np.getContenido());
            insertar_palabras(np.getContenido(), it, arbol);
            return;
        }
    }

    it = tabla[nhash].insert(tabla[nhash].end(), Pagina(np));
    insertar_palabras(np.getContenido(), it, arbol);
    size++;
}

std::vector<Pagina> Diccionario::consultar(const std::wstring& url) {
    std::vector<Pagina> resultado;
    for (const auto& p : tabla[hash(url)])
        if (p.getUrl() == url)
            resultado.push_back(p);
    return resultado;
}

std::set<PagListIt>
Diccionario::buscarPalabra(const std::wstring& palabra) {
    return arbol.buscar(palabra);
}

void Diccionario::pseudoDestructor() {
    for (int i = 0; i < N; i++)
        tabla[i].clear();
}

size_t Diccionario::getTam() {
    return size;
}

std::vector<std::pair<std::wstring, int>>
Diccionario::palabrasPrefijo(const std::wstring& palabra) {
    return arbol.palabrasPrefijo(palabra); 
}

// Arbol

bool comparar_pagref(const PagListIt& l,
    const PagListIt& r)
{
    if (l->getRelevancia() != r->getRelevancia())
        return l->getRelevancia() > r->getRelevancia();
    else return l->getUrl() < r->getUrl();
}

void Arbol::insertar(const std::wstring& palabra,
    PagListIt paginaref)
{
    auto subarbol = &raiz; // puntero porque referencia rebindeable
    std::map<wchar_t, nodo_trie_t>::iterator it;

    for (wchar_t c : palabra) {
        auto nuevonodo = nodo_trie_t {};
        // solo inserta si c no existe
        it = subarbol->insert({c, nuevonodo}).first;
        subarbol = &it->second.hijos;
    }
    
    if (std::find(it->second.paginas.begin(),
        it->second.paginas.end(), paginaref) == it->second.paginas.end())
    {
        it->second.paginas.insert(paginaref);
    }
}

// no const ref return porque si no se encuentra resultado,
// retorna nuevo vector vacio
std::set<PagListIt>
Arbol::buscar(const std::wstring& palabra) {
    auto subarbol = &raiz;
    std::map<wchar_t, nodo_trie_t>::iterator it;

    for (wchar_t c : palabra) {
        auto nuevonodo = nodo_trie_t();
        it = subarbol->find(c);
        if (it == subarbol->end())
            // retornar vector vacio si no hay resultados
            return std::set<PagListIt>();
        
        subarbol = &it->second.hijos;
    }

    return it->second.paginas;
}

void palabrasPrefijoRecursar(const std::map<wchar_t, nodo_trie_t>& a, 
    std::wstring p, std::vector<std::pair<std::wstring, int>>& palabras)
{
    for (auto n : a) {
        if (n.second.paginas.size() > 0)
            palabras.push_back({p + n.first, n.second.paginas.size()});
        palabrasPrefijoRecursar(n.second.hijos, p + n.first, palabras);
    }
}

bool comparadorPalabrasPrefijo(const std::pair<std::wstring, int>& l,
    const std::pair<std::wstring, int>& r)
{
    if (l.second != r.second) return l.second > r.second;
    else return l.first < r.first;
}

std::vector<std::pair<std::wstring, int>>
Arbol::palabrasPrefijo(const std::wstring& prefijo) {
    auto subarbol = &raiz;
    std::map<wchar_t, nodo_trie_t>::iterator it;

    for (wchar_t c : prefijo) {
        auto nuevonodo = nodo_trie_t();
        it = subarbol->find(c);
        if (it == subarbol->end())
            return std::vector<std::pair<std::wstring, int>>();
        
        subarbol = &it->second.hijos;
    }

    std::vector<std::pair<std::wstring, int>> palabras;

    if (it->second.paginas.size() > 0)
        palabras.push_back({prefijo, it->second.paginas.size()});
    palabrasPrefijoRecursar(*subarbol, prefijo, palabras);
    std::sort(palabras.begin(), palabras.end(), comparadorPalabrasPrefijo);
    return palabras;
}

