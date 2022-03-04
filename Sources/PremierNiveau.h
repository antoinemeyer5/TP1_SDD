#include "SecondNiveau.h"
#include <stdio.h>

/* -------------------------------------------------------- */
/* Constantes pour la taille des différents éléments de la  */
/* structure                                                */
/* -------------------------------------------------------- */
#define TAILLE_ANNEE    4
#define TAILLE_SEMAINE  2

/* -------------------------------------------------------- */
/* second_niveau_t  Structure représentant une semaine      */
/* -------------------------------------------------------- */
typedef struct premier_niveau premier_niveau_t;
struct premier_niveau {
    char                annee[TAILLE_ANNEE];
    char                semaine[TAILLE_SEMAINE];
    second_niveau_t   * actions;
    premier_niveau_t  * suivant;
};

/* -------------------------------------------------------- */
/* allouer_premier_niveau  Alloue l'espace mémoire pour un  */
/*                         élément de type second_niveau_t  */
/* -------------------------------------------------------- */
int allouer_premier_niveau(premier_niveau_t **);

/* -------------------------------------------------------- */
/* ajouter_en_tete_premier_niveau   Ajoute en tête un bloc à*/
/*                                  à la liste en paramètre */
/* -------------------------------------------------------- */
int ajouter_en_tete_premier_niveau(premier_niveau_t **, premier_niveau_t *);

/* -------------------------------------------------------- */
/* retourner_debut_chaine    Copie un mot dans une          */
/*                           nouvelle chaine de             */
/*                           caractères                     */
/* -------------------------------------------------------- */
int exister_dans_premier_niveau(premier_niveau_t *, char *, char *);

/* -------------------------------------------------------- */
/* retourner_milieu_chaine    Copie les éléments d'une      */
/*                            chaine de caractères de début */
/*                            à fin dans une nouvelle       */
/*                            chaine de caractères          */
/* -------------------------------------------------------- */
char * retourner_debut_chaine(char[], int);

/* -------------------------------------------------------- */
/* exister_dans_premier_niveau   Retourne 1 si l'année      */
/*                               et la semaine demandées    */
/*                               existent                   */
/* -------------------------------------------------------- */
char * retourner_milieu_chaine(char[], int, int);

/* -------------------------------------------------------- */
/* rechercher_motif_premier_niveau   Affiche la liste       */
/*                                   des dates avec         */
/*                                   une action contenant   */
/*                                   un motif donné         */
/* -------------------------------------------------------- */
void rechercher_motif_premier_niveau(char[], char[], premier_niveau_t *);

/* -------------------------------------------------------- */
/* afficher_premier_niveau  Affiche les informations de     */
/*                          la semaine                      */
/* -------------------------------------------------------- */
//void afficher_premier_niveau(premier_niveau_t *);

//
void remplir_informations_premier_niveau(premier_niveau_t *, char *, char *);

/* -------------------------------------------------------- */
/* ajouter_tri_croissant    Ajoute dans la liste au bon     */
/*                          endroit en gardant le tri       */
/*                          croissant                       */
/* -------------------------------------------------------- */
int ajouter_PN_bon_endroit(premier_niveau_t **, premier_niveau_t *);