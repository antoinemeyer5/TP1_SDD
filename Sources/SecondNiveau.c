#include "OutilsCommuns.h"
#include <stdlib.h>
#include <stdio.h>

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
    while ((*tete_liste).suivant != NULL) {
        // Affichage des informations d'une action
        printf("=> jour : ");
        afficher_chaine((*tete_liste).jour, TAILLE_JOUR);
        printf(" - heure : ");
        afficher_chaine((*tete_liste).heure, TAILLE_HEURE);
        printf(" - nom : ");
        afficher_chaine((*tete_liste).nom, TAILLE_NOM_ACTION);
        printf("\n");
        // Passage à l'action suivante dans la liste des actions
        tete_liste = (*tete_liste).suivant;
    }
}

/* -------------------------------------------------------- */
/* rechercher_motif_second_niveau    Affiche la liste       */
/*                                   des jours avec         */
/*                                   une action contenant   */
/*                                   un motif donné         */
/*                                                          */
/* En entrée : motif, liste                                 */
/*                                                          */
/* En sortie : liste_jours                                  */
/* -------------------------------------------------------- */
void rechercher_motif_second_niveau(char liste_jours[], char motif[], second_niveau_t * liste) {
    int         i, j;
    int         deb = 0;
    //char        liste_jours[7];

    while (liste != NULL) {
        i = 0;
        j = 0;
        //printf("%c\n", (*liste).jour[0]);
        //printf("%s\n", (*liste).nom);
        while (j<10 && (*liste).nom[j] != motif[0]) {
            j++;
            //printf("j : %d\n", j);
        }

        if ((*liste).nom[j] == motif[0]) {
            //printf("\nOn y est \n");
            while (j<10 && motif[i] != '\0' && (*liste).nom[j] == motif[i]) {
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