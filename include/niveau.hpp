#include <string>

class Niveau {
public:
    std::string fichierCarte;
    Niveau(const std::string& fichier) : fichierCarte(fichier) {}
};
