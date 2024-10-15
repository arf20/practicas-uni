#pragma once

#include <string>
#include <vector>
#include <map>

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
    int getRelevancia() const;
    int getContSize() const;
};


struct comparador_paginas_url {
    bool operator() (const std::wstring& i, const std::wstring& d) const;
};

class Diccionario {
    private:
    std::map<std::wstring, Pagina, comparador_paginas_url> paginas;

    public:
    void insertar(const Pagina& p);
    std::vector<Pagina> consultar(const std::wstring& url);
    size_t size();
};
