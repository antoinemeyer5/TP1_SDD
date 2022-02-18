#include "PremierNiveau.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//fonction qui prend un string et un nombre de caractère à afficher et les affichent
// sera utile pour annee et semaine mais surtout pour le nom qui ne doit pas avoir de \0 à la fin

/* -------------------------------------------------------- */
/* allouer_premier_niveau  Alloue l'espace mémoire pour un  */
/*                         élément de type second_niveau_t  */
/*                                                          */
/* En entrée/sortie : tete_liste, Pointeur de début de      */
/*                    l'espace mémoire alloué               */
/*                                                          */
/* En sortie : code, Entier valant 1 si l'allocation s'est  */
/*             bien passée; 0 sinon                         */
/* -------------------------------------------------------- */
int allouer_premier_niveau(premier_niveau_t ** tete_liste)
{
    int code = 1;
    *tete_liste = (premier_niveau_t *)malloc(sizeof(premier_niveau_t));
    if (tete_liste == NULL) {
        code = 0;
    } else {
        (*(*tete_liste)).suivant = NULL;
    }
    return code;
}

/* -------------------------------------------------------- */
/* ajouter_en_tete_premier_niveau   Ajoute en tête un bloc à*/
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
int ajouter_en_tete_premier_niveau(premier_niveau_t ** tete_liste, premier_niveau_t * nouvel_element)
{
    int code = 1;
    (*nouvel_element).suivant = *tete_liste;
    *tete_liste = nouvel_element;
    return code;
}


/* -------------------------------------------------------- */
/* retourner_debut_chaine    Copie un mot dans une          */
/*                           nouvelle chaine de             */
/*                           caractères                     */
/*                                                          */
/* En entrée : mot, Chaine de caractère à copier            */
/*            taille_mot, Taille de la chaine de caractères */
/*                                                          */
/* En sortie : resultat, Copie du mot                       */
/* -------------------------------------------------------- */
char * retourner_debut_chaine(char mot[], int taille_mot)
{
    char * resultat = malloc(taille_mot * sizeof(char));
    for (int i=0; i<taille_mot; i++) {
        resultat[i] = mot[i];
    }
    return resultat;
}

//le premier caractere est a la place 0

/* -------------------------------------------------------- */
/* retourner_milieu_chaine    Copie les éléments d'une      */
/*                            chaine de caractères de début */
/*                            à fin dans une nouvelle       */
/*                            chaine de caractères          */
/*                                                          */
/* En entrée : mot, Chaine de caractères à copier           */
/*             debut, Debut de la chaine à copier           */
/*             fin, Fin de la chaine à copier               */
/*                                                          */
/* En sortie : resultat, Copie des éléments                 */
/* -------------------------------------------------------- */
char * retourner_milieu_chaine(char mot[], int debut, int fin)
{
    char * resultat = malloc((fin-debut+1) * sizeof(char));
    for(int i=debut; i<fin; i++){
        resultat[i-debut] = mot[i];
    }
    return resultat;
}

/* -------------------------------------------------------- */
/* exister_dans_premier_niveau   Retourne 1 si l'année      */
/*                               et la semaine demandées    */
/*                               existent                   */
/*                                                          */
/* En entrée : bloc, Pointeur d'un premier niveau           */
/*             annee, Chaine de caractères recherchée       */
/*             semaine, Chaine de caractères recherchée     */                     
/*                                                          */
/* En sortie : existe,Entier valant 1 si la semaine existe  */
/*             déjà; 0 sinon                                */                                      */
/* -------------------------------------------------------- */
int exister_dans_premier_niveau(premier_niveau_t * bloc, char * annee, char * semaine)
{
    int existe = 0;
    // regarde dans un bloc n1 si son annee et sa semaine sont egales
    // aux parametres 
    if (strcmp(retourner_debut_chaine((*bloc).annee, TAILLE_ANNEE), annee) == 0 ) {
        if (strcmp((*bloc).semaine, semaine) == 0) {
            existe = 1;
        }
    }
    // retourne 0 si pas egale
    // retourne 1 si egale
    return existe;
}

/* -------------------------------------------------------- */
/* rechercher_motif_premier_niveau   Affiche la liste       */
/*                                   des dates avec         */
/*                                   une action contenant   */
/*                                   un motif donné         */
/*                                                          */
/*                                                          */
/* En entrée : motif, Chaine de caractères à chercher       */
/*             liste, Pointeur d'une liste d'actions        */
/*                                                          */
/* En entrée/sortie : liste_dates, Pointeur d'une liste     */
/*                    de dates                              */
/* -------------------------------------------------------- */
void rechercher_motif_premier_niveau(char liste_dates[], char motif[], premier_niveau_t * liste) 
{
    int         k = 0;
    int         deb = 0;
    char        liste_jours[8];

    while (liste != NULL) {
        rechercher_motif_second_niveau(liste_jours, motif, (*liste).actions);
        k = 0;

        while (liste_jours[0] != '\0') {
            for (int i=0; i<TAILLE_ANNEE; i++) {
                liste_dates[deb+i] = (*liste).annee[i];
            }

            deb += TAILLE_ANNEE;

            for (int j=0; j<TAILLE_SEMAINE; j++) {
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