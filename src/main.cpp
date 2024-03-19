#include "labyrinthe.hpp"
#include "joueur.hpp"
#include "niveau.hpp" // Inclure votre nouvelle classe/structure Niveau
#include <iostream>
#include <vector>

int main() {
    Joueur joueur(1, 1); // Position initiale du joueur pourrait être ajustée par niveau

    // Créer les niveaux
    std::vector<Niveau> niveaux = {
        Niveau("res/niveau1.txt"),
        Niveau("res/niveau2.txt"),
        Niveau("res/niveau3.txt"),
        Niveau("res/niveau4.txt"),
        Niveau("res/niveau5.txt"),
        // Ajoutez plus de niveaux ici
    };

    for(auto& niveau : niveaux) {
        Labyrinthe labyrinthe(niveau.fichierCarte, joueur);
        labyrinthe.afficher();
        
        std::cout << "Commandes : 'h' haut, 'b' bas, 'g' gauche, 'd' droite" << std::endl;
        
        char commande;
        while (true) {
            std::cout << "Votre choix : ";
            std::cin >> commande;
            Direction dir;
            switch (commande) {
                case 'h': dir = Direction::HAUT; break;
                case 'b': dir = Direction::BAS; break;
                case 'd': dir = Direction::DROITE; break;
                case 'g': dir = Direction::GAUCHE; break;
                default: continue;
            }
            labyrinthe.deplacerJoueur(dir);
            labyrinthe.afficher();
            if (labyrinthe.estSurLaSortie()) {
                std::cout << "Niveau termine !" << std::endl;
                break; // Sortir de la boucle pour passer au niveau suivant
            }
        }
    }
    std::cout << "Tous les niveaux sont termines, felicitations !" << std::endl;
    return 0;
}
