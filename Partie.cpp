//
// Created by Laila ElKoussy on 10/15/21.
//

#include "Partie.hpp"

ostream &operator<<(ostream &out, Partie &x) {
    for (int i = 0; i < x.grille.size(); i++) {
        for (int j = 0; j < x.grille[i].size(); j++) {
            out << x.grille[i][j] << " ";
        }
        out << endl;
    }
    return out;
}


void Partie::lance_partie(Joueur& joueur1, Joueur& joueur2) {
    cout << "Partie entre " << joueur1.get_identifiant() << " et " << joueur2.get_identifiant() << endl;
    Symb joueur;
    int param1, param2;
    cout << *this;
    for (int i = 0; i < 9; i++) {
        //i% 2 = quel joueur
        joueur = (i % 2) ? x : o;
        string joueur_id = (joueur == x)? joueur1.get_identifiant(): joueur2.get_identifiant();
        cout << "C'est le tour de " << joueur_id << endl;
        //verification de l'entree

        do {
            cout << "Entrez une case i j" << endl;
            cin >> param1 >> param2;
        } while (!bon_parametres(param1, param2));
        jouer(joueur, param1, param2);
        cout << *this;
        if (gagnant(joueur)) {
            if( joueur == x){
                joueur_a_gagne(joueur1);
            }
            else{
                joueur_a_gagne(joueur2);
            }
            cout << joueur_id << " a gagné!" << endl;
            cout << joueur1 << endl << joueur2 << endl;
            clean_up();
            return;
        }
    }
    cout << "La partie est terminée sans gagnant." << endl;
    cout << joueur1 << endl << joueur2 << endl;
    clean_up();
}

bool Partie::bon_parametres(int &param1, int &param2) {
    bool mauvaise_valeur = false;
    if (param1 > 2 || param1 < 0 || param2 > 2 || param2 < 0) {
        cout << "Zut! Il y a un problème avec les coordonnés de la case." << endl;
        mauvaise_valeur = true;
    }
    if (grille[param1][param2] != b) {
        cout << "Zut! Cette case est déjà prise." << endl;
        mauvaise_valeur = true;
    }
    return !mauvaise_valeur;

}

// Place le coup du joueur et augumente le nb de coups
void Partie::jouer(Symb&  n , int&  i, int&  j){
    grille[i][j] = n;
    nb_de_coups++;
}

//Check si joueur jouant avec j1 est gagnant
bool Partie::gagnant(Symb& j1) {
    //|..
    for (int i = 0; i < 2; i++)
        if (grille[i][0] == j1 && grille[i][1] == j1 && grille[i][2] == j1)
            return true;
    // ___
    for (int i = 0; i < 2; i++)
        if (grille[0][i] == j1 && grille[1][i] == j1 && grille[2][i] == j1)
            return true;

    if (grille[0][0] == j1 && grille[1][1] == j1 && grille[1][1] == j1)
        return true;
    if (grille[0][2] == j1 && grille[1][1] == j1 && grille[2][0] == j1)
        return true;

    return false;
}


void Partie::joueur_a_gagne(Joueur &joueur) {
    float score = 9.0 / (nb_de_coups + nb_de_coups % 2);
    joueur.mettre_a_jour_score_total(score);
    joueur.mettre_a_jour_score_tournoi(score);

}

void Partie::clean_up() {
    for (int i = 0; i < grille.size(); i++) {
        for (int j = 0; j < grille[i].size(); j++) {
            grille[i][j] = b;
        }

    }

}