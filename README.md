# Jeu de Labyrinthe en C++
## Description
Ce projet est un jeu de labyrinthe simple implémenté en C++. Le joueur navigue dans différents labyrinthes "niveau par niveau" à la recherche de la sortie. Chaque labyrinthe est représenté par une grille où le joueur peut se déplacer vers le haut, le bas, la gauche ou la droite. Le jeu se joue entièrement dans la console.

## Fonctionnalités
Navigation dans le labyrinthe en utilisant les commandes clavier.
Plusieurs niveaux de difficulté croissante.
Affichage en temps réel de la position du joueur dans le labyrinthe.
Détection automatique de la sortie pour passer au niveau suivant.

## Règles du Jeu
1. Déplacements : Le joueur peut se déplacer dans quatre directions : haut (h), bas (b), gauche (g), et droite (d).
2. Objectif : L'objectif est de trouver la sortie du labyrinthe, marquée par le symbole S sur la grille.
3. Murs : Les murs du labyrinthe sont indiqués par le symbole #. Le joueur ne peut pas traverser les murs et doit trouver un chemin autour d'eux pour atteindre la sortie.
4. Niveaux : Après avoir atteint la sortie, le joueur passe au niveau suivant. Le jeu se termine lorsque tous les niveaux ont été complétés.

## Comment Jouer
1. Compilez le projet en utilisant votre compilateur C++ favori.
2. Exécutez le fichier binaire généré depuis votre terminal ou invite de commande.
3. Utilisez les commandes de déplacement pour naviguer dans le labyrinthe.
4. Atteignez la sortie pour passer au niveau suivant.

## Compilation et Exécution
Pour compiler ce projet, assurez-vous d'avoir un environnement de développement C++ configuré. Utilisez la commande de compilation appropriée pour votre compilateur. Par exemple, avec g++, vous pouvez utiliser :

```bash
g++ src/main.cpp src/labyrinthe.cpp src/joueur.cpp -o start -Iinclude
```

Pour exécuter le jeu, lancez le binaire créé :

```bash
./start
```
## Contribution
Les contributions au projet sont bienvenues. Si vous souhaitez améliorer le jeu ou signaler des bugs, n'hésitez pas à créer une issue ou une pull request.