#include "labyrinthe.hpp"
#include <fstream>
#include <iostream>

Labyrinthe::Labyrinthe(const std::string& fichierCarte, Joueur j) : joueur(j) {
    chargerCarte(fichierCarte);
}

void Labyrinthe::chargerCarte(const std::string& fichierCarte) {
    std::ifstream fichier(fichierCarte);
    std::string ligne;
    int y = 0; // Initialiser un compteur de ligne
    while (getline(fichier, ligne)) {
        int x = ligne.find('S'); // Chercher la sortie dans la ligne
        if (x != std::string::npos) { // Si la sortie est trouvée
            sortieX = x; // Enregistrer les coordonnées de la sortie
            sortieY = y;
        }
        carte.push_back(ligne);
        y++; // Incrémenter le compteur de ligne après chaque ligne lue
    }
}


bool Labyrinthe::deplacementValide(int newX, int newY) const {
    // Vérifier si la nouvelle position est dans les limites de la carte
    if (newY >= 0 && newY < carte.size() && newX >= 0 && newX < carte[newY].length()) {
        // Vérifier si la nouvelle position est une case vide (' ') ou la sortie ('S')
        char caseCible = carte[newY][newX];
        return caseCible == ' ' || caseCible == 'S';
    }
    return false; // Si en dehors des limites, le déplacement n'est pas valide
}


void Labyrinthe::afficher() const {
    // Créer une copie temporaire de la carte pour y placer le joueur
    auto carteAvecJoueur = carte;

    // Assurez-vous que la position du joueur est valide avant de modifier la carte
    if (joueur.y < carteAvecJoueur.size() && joueur.x < carteAvecJoueur[joueur.y].length()) {
        // Placer le symbole du joueur sur la carte temporaire
        carteAvecJoueur[joueur.y][joueur.x] = 'P'; // 'P' pour "Player"
    }

    // Afficher la carte avec le joueur
    for (const auto& ligne : carteAvecJoueur) {
        std::cout << ligne << std::endl;
    }
}

bool Labyrinthe::estSurLaSortie() const {
    return joueur.x == sortieX && joueur.y == sortieY;
}


bool Labyrinthe::deplacerJoueur(Direction dir) {
    int newX = joueur.x, newY = joueur.y;
    switch (dir) {
        case Direction::HAUT: newY--; break;
        case Direction::BAS: newY++; break;
        case Direction::DROITE: newX++; break;
        case Direction::GAUCHE: newX--; break;
    }

    if (deplacementValide(newX, newY)) {
        joueur.x = newX;
        joueur.y = newY;

        if (estSurLaSortie()) {
            std::wcout << L"Felicitations ! Vous avez trouve la sortie." << std::endl;
            return true; // Le joueur a trouvé la sortie
        }
        return false; // Le joueur n'a pas trouvé la sortie, mais le déplacement était valide
    }
    return false; // Le déplacement n'était pas valide
}



