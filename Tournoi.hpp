//
// Created by Laila ElKoussy on 10/15/21.
//

#ifndef TPN_TOURNOI_HPP
#define TPN_TOURNOI_HPP

#include <iostream>
#include "Joueur.hpp"
#include "Partie.hpp"
#include <vector>

using namespace std;

class Tournoi {

    friend ostream &operator<<(ostream &out, Tournoi &x);
    vector<Joueur> participants;
    bool tournoi_lance;
    float get_max_score();

public:
    Tournoi();
    void inscription(Joueur&);
    void lance_tournoi();
    void vide_participants();
};



#endif //TPN_TOURNOI_HPP
