//
// Created by Laila ElKoussy on 10/15/21.
//

#include "Joueur.hpp"

ostream &operator<<(ostream &out, Joueur const &x) {
    out<<"Scores du joueur "<<x.identifiant<< ": tournoi " << x.score_tournoi<< " , total "<<x.score_total;
    return out;
}

Joueur::Joueur(string id) : identifiant{id} {}

void Joueur::mettre_a_jour_score_total(float const ajout) {
    score_total += ajout;
}

void Joueur::mettre_a_jour_score_tournoi(float const ajout) {
    score_tournoi += ajout;
}

string  Joueur::get_identifiant() const{
    return identifiant;
}

void Joueur::nouveau_tournoi(){
    score_tournoi = 0;
}

float Joueur::get_score_tournoi() const{
    return score_tournoi;
}
