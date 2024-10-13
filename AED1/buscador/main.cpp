#include <iostream>
#include <string>
#include <sstream>
#include <vector>

struct pagina_t {
    int relevancia;
    std::string url;
    std::string titulo;
    std::vector<std::string> contenido;

};

int main() {
    std::string l;
    char cmd;

    std::vector<pagina_t> paginas;

    while (std::getline(std::cin, l)) {
        
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

                std::cout << paginas.size() << ". " << np.url << ", " <<
                    np.titulo << ", Rel. " << np.relevancia << std::endl <<
                    np.contenido.size() << " palabras" << std::endl;
            } break;
            default: {
                std::cout << "Comando no reconocido" << std::endl;
            }
        }
    }
}
