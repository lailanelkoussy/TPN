//
// Created by Laila ElKoussy on 10/15/21.
//

#ifndef TPN_PARTIE_HPP
#define TPN_PARTIE_HPP

#include <vector>
#include "Joueur.hpp"
using namespace std;

class Partie {
    friend ostream &operator<<(ostream &out, Partie &x);
    enum Symb { b, x, o };
    int nb_de_coups = 0;
    vector<vector<Symb>> grille {{b, b, b},{b, b, b},{b, b, b}};
    void jouer(Symb& , int& , int& );
    bool gagnant(Symb&);
    void joueur_a_gagne(Joueur&);
    bool bon_parametres(int&,int&);
    void clean_up();

public:
    void lance_partie(Joueur&, Joueur&);

};



#endif //TPN_PARTIE_HPP
