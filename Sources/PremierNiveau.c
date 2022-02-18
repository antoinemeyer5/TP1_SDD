#include "PremierNiveau.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//fonction qui prend un string et un nombre de caractère à afficher et les affichent
// sera utile pour annee et semaine mais surtout pour le nom qui ne doit pas avoir de \0 à la fin

int allouer_premier_niveau(premier_niveau_t ** TeteListe)
{
    int code = 1;
    *TeteListe = (premier_niveau_t *)malloc(sizeof(premier_niveau_t));
    if (TeteListe == NULL) {
        code = 0;
    } else {
        (*(*TeteListe)).suivant = NULL;
    }
    return code;
}

int ajouter_en_tete_premier_niveau(premier_niveau_t ** TeteListe, premier_niveau_t * NouvelElement)
{
    int code = 1;
    (*NouvelElement).suivant = *TeteListe;
    *TeteListe = NouvelElement;
    return code;
}


//
char * retourner_debut_chaine(char mot[], int TailleMot)
{
    char * Resultat = malloc(TailleMot * sizeof(char));
    for(int i=0; i<TailleMot; i++){
        Resultat[i] = mot[i];
    }
    return Resultat;
}

//le premier caractere est a la place 0
char * retourner_milieu_chaine(char Mot[], int Debut, int Fin)
{
    char * Resultat = malloc((Fin-Debut+1) * sizeof(char));
    for(int i=Debut; i<Fin; i++){
        Resultat[i-Debut] = Mot[i];
    }
    return Resultat;
}

int exister_dans_premier_niveau(premier_niveau_t * Bloc, char * Annee, char * Semaine)
{
    int Existe = 0;
    // regarde dans un bloc n1 si son annee et sa semaine sont egales
    // aux parametres 
    if (strcmp(retourner_debut_chaine((*Bloc).annee, TAILLE_ANNEE), Annee) == 0 ) {
        if (strcmp((*Bloc).semaine, Semaine) == 0) {
            Existe = 1;
        }
    }
    // retourne 0 si pas egale
    // retourne 1 si egale
    return Existe;
}

/* -------------------------------------------------------- */
/* rechercher_motif_premier_niveau   Affiche la liste       */
/*                                   des jours avec         */
/*                                   une action contenant   */
/*                                   un motif donné         */
/*                                                          */
/* En entrée : motif, liste                                 */
/*                                                          */
/* En entrée/sortie : liste_jours                           */
/* -------------------------------------------------------- */
void rechercher_motif_premier_niveau(char liste_dates[], char motif[], premier_niveau_t * liste) {
    int         i, j;
    int         k = 0;
    int         deb = 0;
    char        liste_jours[8];

    while (liste != NULL) {
        rechercher_motif_second_niveau(liste_jours, motif, (*liste).actions);
        k = 0; 
        while (liste_jours[0] != '\0') {
            for (i=0; i<TAILLE_ANNEE; i++) {
                liste_dates[deb+i] = (*liste).annee[i];
            }
            deb += TAILLE_ANNEE;
            for (j=0; j<TAILLE_SEMAINE; j++) {
                liste_dates[deb+j] = (*liste).semaine[j];
            }
            deb += TAILLE_SEMAINE;
            liste_dates[deb] = liste_jours[0];
            liste_jours[0] = liste_jours[k];
            k++;
            deb++;
        }
        liste = (*liste).suivant;
    }
    liste_dates[deb] = '\0';
}