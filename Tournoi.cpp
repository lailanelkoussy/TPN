//
// Created by Laila ElKoussy on 10/15/21.
//

#include "Tournoi.hpp"


//TODO: don't forget to declare operator
ostream &operator<<(ostream &out, Tournoi &x) {
    out << "Score totaux des participants: " << endl;
    for (int i = 0; i < x.participants.size(); i++) {
        out << x.participants[i] << endl;
    }

    return out;
}

void Tournoi::inscription(Joueur &joueur) {
    if (!tournoi_lance) {
        participants.push_back(joueur);
    } else { cout << "Desolé " << joueur.get_identifiant() << "! La partie a déjà commencé!"; }

}

Tournoi::Tournoi() {
    tournoi_lance = false;
}

void Tournoi::lance_tournoi() {
    float max_score;
    tournoi_lance = true;
    Partie partie;

    for (int i = 0; i < participants.size(); i++) {
        for (int j = i + 1; j < participants.size(); j++) {
            partie.lance_partie(participants[i], participants[j]);
        }
    }

    max_score = get_max_score();
    cout << "Le(s) gagnants du tournoi sont : "<<endl;
    for (int i = 0; i < participants.size(); i++) {
        if (participants[i].get_score_tournoi() == max_score)
            cout << participants[i].get_identifiant() << endl;
    }
    cout<<*this;


}

float Tournoi::get_max_score() {
    float max_score = participants[0].get_score_tournoi();
    for (int i = 1; i < participants.size(); i++) {
        if (participants[i].get_score_tournoi() > max_score)
            max_score = participants[i].get_score_tournoi();
    }
    return max_score;
}

void Tournoi::vide_participants() {
    tournoi_lance = false;
    for (int i = 0; i < participants.size(); i++) {
        participants[i].nouveau_tournoi();
    }
    participants.clear();
}



