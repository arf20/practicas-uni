#pragma once

#include <string>
#include <vector>
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
};

struct nodo_trie_t {
    std::vector<std::vector<Pagina>::iterator> paginas;
    std::map<char, nodo_trie_t> hijos;
};

class Arbol {
    private:
    std::map<char, nodo_trie_t> raiz;

    public:
    void insertar(const std::wstring& palabra,
        std::vector<Pagina>::iterator paginaref);
    std::vector<std::vector<Pagina>::iterator>
        buscar(const std::wstring& palabra);
};

class Diccionario {
    private:
    std::vector<Pagina> tabla[N];
    Arbol arbol;
    size_t hash(const std::wstring& key);
    int size = 0;

    public:
    void insertar(const Pagina& p);
    std::vector<Pagina> consultar(const std::wstring& url);
    std::vector<std::vector<Pagina>::iterator>
        buscarPalabra(const std::wstring& palabra);
    size_t getTam();
};
