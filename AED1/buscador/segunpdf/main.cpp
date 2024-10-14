#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

struct pagina_t {
    int relevancia;
    std::string url;
    std::string titulo;
    std::vector<std::string> contenido;
};


auto tolower(std::string s) {
    std::string o;
    for (auto c : s) o += std::tolower(c);
    return o;
}

bool comparar_relevancia(std::vector<pagina_t>::iterator i, 
    std::vector<pagina_t>::iterator d)
{
    return i->relevancia < d->relevancia;
}

void imprimir_resultados(
    std::vector<std::vector<pagina_t>::iterator>& resultados)
{
    std::sort(resultados.begin(), resultados.end(), comparar_relevancia);

    for (size_t i = 0; i < resultados.size(); i++)
        std::cout << i + 1 << ". " << resultados[i]->url << ", "
            << resultados[i]->titulo << ", Rel. "
            << resultados[i]->relevancia << std::endl;
    std::cout << "Total: " << resultados.size() << " resultados"
        << std::endl;
}

int main() {
    std::string l;
    char cmd;

    std::vector<pagina_t> paginas;

    while (std::getline(std::cin, l)) {
        if (l.length() == 0) continue;

        std::stringstream ls(l);
        cmd = 0;
        ls >> cmd;
        switch (cmd) {
            case 'i': {
                pagina_t np;
                ls >> np.relevancia;

                std::getline(std::cin, l);
                np.url = l;

                std::getline(std::cin, l);
                np.titulo = l;

                while (l != "FINDEPAGINA") {
                    std::cin >> l;
                    np.contenido.push_back(l);
                }

                paginas.push_back(np);

                std::cout << paginas.size() << ". " << np.url << ", "
                    << np.titulo << ", Rel. " << np.relevancia << std::endl
                    << np.contenido.size() << " palabras" << std::endl;
            } break;
            case 'u': {
                std::string url;
                std::vector<std::vector<pagina_t>::iterator> resultados;
                ls >> url;
                
                for (auto it = paginas.begin(); it != paginas.end(); it++)
                    if (it->url.compare(0, url.size(), url) == 0)
                        resultados.push_back(it);
                    
                std::cout << "u " << url << std::endl;
                imprimir_resultados(resultados);
            } break;
            case 'b': {
                std::string palabra;
                std::vector<std::vector<pagina_t>::iterator> resultados;
                ls >> palabra;

                for (auto it = paginas.begin(); it != paginas.end(); it++)
                    if (std::find(it->contenido.begin(), it->contenido.end(),
                        palabra) != it->contenido.end())
                    {
                        resultados.push_back(it);
                    }
                
                std::cout << "b " << palabra << std::endl;
                imprimir_resultados(resultados);
            } break;
            case 'a': {
                std::vector<std::string> palabras;
                std::vector<std::vector<pagina_t>::iterator> resultados;
                std::string _p;
                
                while (std::cin >> _p)
                    palabras.push_back(_p);
                
                for (auto it = paginas.begin(); it != paginas.end(); it++) {
                    bool contiene = true;
                    for (auto p : palabras)
                        if (std::find(it->contenido.begin(),
                            it->contenido.end(), p) == it->contenido.end())
                            {
                                contiene = false;
                                break;
                            }
                    if (contiene)
                        resultados.push_back(it);
                }

                std::cout << "a ";
                for (auto p : palabras) std::cout << p;
                std::cout << std::endl;
                imprimir_resultados(resultados);
            } break;
            case 'o': {
                std::vector<std::string> palabras;
                std::vector<std::vector<pagina_t>::iterator> resultados;
                std::string _p;
                
                while (std::cin >> _p)
                    palabras.push_back(_p);
                
                for (auto it = paginas.begin(); it != paginas.end(); it++) {
                    bool contiene = false;
                    for (auto p : palabras)
                        if (std::find(it->contenido.begin(),
                            it->contenido.end(), p) != it->contenido.end())
                        {
                            contiene = true;
                            break;
                        }
                    if (contiene)
                        resultados.push_back(it);
                }

                std::cout << "o ";
                for (auto p : palabras) std::cout << p;
                std::cout << std::endl;
                imprimir_resultados(resultados);
            }
            case 'p': {
                std::string prefijo;
                ls >> prefijo;
                std::vector<std::vector<std::string>::iterator> resultados;


                for (auto it = paginas.begin(); it != paginas.end(); it++) {
                    for (auto it2 = it->contenido.begin();
                        it2 != it->contenido.end(); it2++)
                    {
                        if (tolower(*it2).compare(0, prefijo.length(), tolower(prefijo)) == 0)
                            resultados.push_back(it2);
                    }
                }

                std::cout << "p " << prefijo << std::endl;
                for (size_t i = 0; i < resultados.size(); i++)
                    std::cout << i + 1 << ". " << *resultados[i] << std::endl;
                std::cout << "Total: " << resultados.size() << " resultados"
                    << std::endl;
            } break;
            case 's': {
                return 0;
            } break;
            default: {
                std::cout << "Comando no reconocido" << std::endl;
            }
        }
    }
}
