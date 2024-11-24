#pragma once

#include <string>
#include <vector>
#include <set>
#include <list>
#include <map>
#include <memory>

constexpr int N = 20000;

class Pagina {
    private:
    std::wstring url, titulo;
    int relevancia;
    std::vector<std::wstring> contenido;

    public:
    Pagina(const std::wstring& _url, const std::wstring& _titulo, int _rel,
        const std::vector<std::wstring>& _cont);
    const std::wstring& getUrl() const;
    const std::wstring& getTitulo() const;
    void setTitulo(const std::wstring& titulo);
    int getRelevancia() const;
    void setRelevancia(int rel);
    int getContSize() const;
    const std::vector<std::wstring>& getContenido() const;
    void setContenido(const std::vector<std::wstring>& palabras);
};

//bool comparar_pagref(const std::list<Pagina>::iterator& l,
//    const std::list<Pagina>::iterator& r);

class PagListIt : public std::list<Pagina>::iterator {
public:
    PagListIt(std::list<Pagina>::iterator& it);
    bool operator<(const PagListIt& right) const;
};

struct nodo_trie_t {
    std::set<PagListIt> paginas;
    std::map<wchar_t, nodo_trie_t> hijos;
};

class Arbol {
    private:
    std::map<wchar_t, nodo_trie_t> raiz;

    public:
    void insertar(const std::wstring& palabra,
        PagListIt paginaref);
    std::set<PagListIt> buscar(const std::wstring& palabra);
    std::vector<std::pair<std::wstring, int>>
        palabrasPrefijo(const std::wstring& palabra);
};

class Diccionario {
    private:
    std::list<Pagina> tabla[N];
    Arbol arbol;
    size_t hash(const std::wstring& key);
    int size = 0;

    public:
    void insertar(const Pagina& p);
    std::vector<Pagina> consultar(const std::wstring& url);
    std::set<PagListIt> buscarPalabra(const std::wstring& palabra);
    size_t getTam();
    std::vector<std::pair<std::wstring, int>>
        palabrasPrefijo(const std::wstring& palabra);
};

