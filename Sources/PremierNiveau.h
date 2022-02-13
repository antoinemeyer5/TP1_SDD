#include "SecondNiveau.h"
#include <stdio.h>

#define TAILLE_ANNEE 4
#define TAILLE_SEMAINE 2

/* représente les semaines */
typedef struct premier_niveau premier_niveau_t;
struct premier_niveau{
    char                annee[TAILLE_ANNEE];
    char                semaine[TAILLE_SEMAINE];
    second_niveau_t    * actions;
    premier_niveau_t   * suivant;
};

int allouer_premier_niveau(premier_niveau_t **);

int ajouter_en_tete_premier_niveau(premier_niveau_t **, premier_niveau_t *);

int exister_dans_premier_niveau(premier_niveau_t *, char *, char *);

char * retourner_debut_chaine(char[], int);

char * retourner_milieu_chaine(char[], int, int);



//void Afficherpremier_niveau(premier_niveau_t *);