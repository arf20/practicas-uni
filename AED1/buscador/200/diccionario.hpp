#pragma once

#include <string>
#include <vector>
#include <map>

constexpr int N = 20000;

class Pagina {
    private:
    std::wstring url, titulo;
    int relevancia;
    std::vector<std::wstring> contenido;

    public:
    Pagina(const std::wstring& _url, const std::wstring& _titulo, int _rel,
        const std::vector<std::wstring>& _cont);
    std::wstring getUrl() const;
    std::wstring getTitulo() const;
    void setTitulo(const std::wstring& titulo);
    int getRelevancia() const;
    void setRelevancia(int rel);
    int getContSize() const;
};

class Diccionario {
    private:
    std::vector<Pagina> tabla[N];
    size_t hash(const std::wstring& key);
    int size = 0;

    public:
    void insertar(const Pagina& p);
    std::vector<Pagina> consultar(const std::wstring& url);
    size_t getTam();
};
