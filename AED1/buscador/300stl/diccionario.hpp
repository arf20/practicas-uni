#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include <optional>

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
    int getRelevancia() const;
    int getContSize() const;
    std::vector<std::wstring> getContenido() const;
};

class Diccionario {
    private:
    std::unordered_map<std::wstring, Pagina> paginas;
    std::unordered_map<
        std::wstring,
        std::vector<std::unordered_map<std::wstring, Pagina>::iterator>
    > palabras;

    public:
    void insertar(const Pagina& p);
    std::optional<Pagina> consultar(const std::wstring& url) const;
    std::vector<std::unordered_map<std::wstring, Pagina>::iterator>
        buscarPalabra(const std::wstring& palabra) const;
    size_t size() const;
};
