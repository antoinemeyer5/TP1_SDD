#include "OutilsCommuns.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* -------------------------------------------------------- */
/* allouer_second_niveau   Alloue l'espace mémoire pour un  */
/*                         élément de type second_niveau_t  */
/*                                                          */
/* En entrée/sortie : tete_liste, Pointeur de début de      */
/*                    l'espace mémoire alloué               */
/*                                                          */
/* En sortie : code, Entier valant 1 si l'allocation s'est  */
/*             bien passée; 0 sinon                         */
/* -------------------------------------------------------- */
int allouer_second_niveau(second_niveau_t ** tete_liste)
{
    int code = 1;
    *tete_liste = (second_niveau_t *)malloc(sizeof(second_niveau_t));
    if (tete_liste == NULL) {
        code = 0;
    } else {
        strcpy((*(*tete_liste)).heure, "vV");
        strcpy((*(*tete_liste)).jour, "v");
        strcpy((*(*tete_liste)).nom, "vide");
        (*(*tete_liste)).suivant = NULL;
    }
    return code;
}

/* -------------------------------------------------------- */
/* ajouter_en_tete_second_niveau    Ajoute en tête un bloc à*/
/*                                  à la liste en paramètre */
/*                                                          */
/* En entrée : nouveau_bloc, Pointeur à ajouter à la liste  */
/*                                                          */
/* En entrée/sortie : tete_liste, Pointeur de la liste à    */
/*                    laquelle on veut ajouter un bloc      */
/*                                                          */
/* En sortie : code, Entier valant 1 si l'ajout s'est bien  */
/*             passée; 0 sinon                              */
/* -------------------------------------------------------- */
int ajouter_en_tete_second_niveau(second_niveau_t ** tete_liste, second_niveau_t * nouveau_bloc)
{
    int code = 1;
    (*nouveau_bloc).suivant = *tete_liste;
    *tete_liste = nouveau_bloc;
    return code;
}

/* -------------------------------------------------------- */
/* afficher_second_niveau    Affiche les informations de    */
/*                           l'action                       */
/*                                                          */
/* En entrée : tete_liste, Pointeur d'une liste d'action    */
/*                                                          */
/* En sortie : Rien mais écrit dans la sortie standard      */
/* -------------------------------------------------------- */
void afficher_second_niveau(second_niveau_t * tete_liste)
{
    second_niveau_t * courant = tete_liste;
    while (courant != NULL) {
        // Affichage des informations d'une action
        printf("-> Jour ");
        afficher_chaine((*courant).jour, TAILLE_JOUR);
        printf(" à ");
        afficher_chaine((*courant).heure, TAILLE_HEURE);
        printf("h faire : ");
        afficher_chaine((*courant).nom, TAILLE_NOM_ACTION);
        // Passage à l'action suivante dans la liste des actions
        courant = (*courant).suivant;
    }
}

/* -------------------------------------------------------- */
/* rechercher_motif_second_niveau    Affiche la liste       */
/*                                   des jours avec         */
/*                                   une action contenant   */
/*                                   un motif donné         */
/*                                                          */
/* En entrée : motif, Chaine de caractères à chercher       */
/*             liste, Pointeur d'une liste d'actions        */
/*                                                          */
/* En entrée/sortie : liste_jours, Pointeur d'une liste     */
/*                    de jours                              */
/* -------------------------------------------------------- */
void rechercher_motif_second_niveau(char liste_jours[], char motif[], second_niveau_t * liste) 
{
    int         i, j;
    int         deb = 0;
    //char        liste_jours[7];

    while (liste != NULL) {
        i = 0;
        j = 0;
        //printf("%c\n", (*liste).jour[0]);
        //printf("%s\n", (*liste).nom);
        while (j<TAILLE_NOM_ACTION && (*liste).nom[j] != motif[0]) {
            j++;
            //printf("j : %d\n", j);
        }

        if ((*liste).nom[j] == motif[0]) {
            //printf("\nOn y est \n");
            while (j<TAILLE_NOM_ACTION && motif[i] != '\0' && (*liste).nom[j] == motif[i]) {
                i++;
                j++;
                //printf("(j, i) : (%d %d)\n", j, i);
                //printf("%c =? %c\n", (*liste).nom[j], motif[i]);
            }

            if (motif[i] == '\0') {
                liste_jours[deb] = (*liste).jour[0];
                deb++;
                //printf("On a : %s", liste_jours);
            }
        }
        liste = (*liste).suivant;
    }
    liste_jours[deb] = '\0';
    //printf("%s\n", liste_jours);
    //return liste_jours;
}

/* -------------------------------------------------------- */
void remplir_informations_second_niveau(second_niveau_t * tete_liste, char * jour, char * heure, char * nom_action)
{
    strncpy((*tete_liste).jour, jour, TAILLE_JOUR);
    strncpy((*tete_liste).heure, heure, TAILLE_HEURE);
    strncpy((*tete_liste).nom, nom_action, TAILLE_NOM_ACTION);
    (*tete_liste).suivant = NULL;
}

/* -------------------------------------------------------- */
int ajouter_DN_bon_endroit(second_niveau_t ** tete_liste, second_niveau_t * nouveau_bloc)
{
    int code = 1;
    int trouve = 0;
    second_niveau_t ** precedent = tete_liste;
    int resu_coma;
    while (*precedent != NULL && trouve == 0) {
        //comparaison
        resu_coma = comparer_heures_et_jours(*precedent, nouveau_bloc);
        if (resu_coma == 3 || resu_coma == 1) {
            trouve = 1;
        }
        //cas ajout en tete
        if (trouve != 1) {
            precedent = &((*(*precedent)).suivant);
        }
    }
    nouveau_bloc->suivant = *precedent; 
    *precedent = nouveau_bloc;
    return code;
}

int comparer_heures_et_jours(second_niveau_t * courant, second_niveau_t * nouveau_bloc)
{
    // résultat des comparaisons
    char * courant_jour = retourner_debut_chaine((*courant).jour, TAILLE_JOUR);
    char * courant_heure = retourner_debut_chaine((*courant).heure, TAILLE_HEURE);
    char * nouveau_jour = retourner_debut_chaine((*nouveau_bloc).jour, TAILLE_JOUR);
    char * nouveau_heure = retourner_debut_chaine((*nouveau_bloc).heure, TAILLE_HEURE);
    int comparaison_jours = strncmp(nouveau_jour, courant_jour, TAILLE_JOUR);
    int comparaison_heures = strncmp(nouveau_heure, courant_heure, TAILLE_HEURE);
    int resultat = 0;
    //si même jours
    if (comparaison_jours == 0) {
        //si même heure
        if (comparaison_heures == 0) {
            //même date
            resultat = 1;
        } else if (comparaison_heures > 0) {
            //date du courant < date du nouveau bloc
            resultat = 2;
        } else {
            //date du courant > date du nouveau bloc
            resultat = 3;
        }
    } else {
        if (comparaison_jours > 0) {
            //date du courant < date du nouveau bloc
            resultat = 2;
        } else {
            //date du courant > date du nouveau bloc
            resultat = 3;
        }
    }
    return resultat;
}