//
// Created by Laila ElKoussy on 10/15/21.
//

#ifndef TPN_JOUEUR_HPP
#define TPN_JOUEUR_HPP

#include <iostream>

using namespace std;

class Joueur {

    friend ostream &operator<<(ostream &out, Joueur const &x);
    string identifiant;
    float score_total = 0;
    float score_tournoi = 0;
public:
    Joueur(string);
    void mettre_a_jour_score_tournoi(float);
    void mettre_a_jour_score_total(float);
    string get_identifiant() const;
    void nouveau_tournoi();
    float get_score_tournoi() const;


};





#endif //TPN_JOUEUR_HPP
