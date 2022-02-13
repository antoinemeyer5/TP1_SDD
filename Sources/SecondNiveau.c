#include "SecondNiveau.h"
#include <stdlib.h>
#include <stdio.h>


int allouer_second_niveau(second_niveau_t ** TeteListe)
{
    int code = 1;
    *TeteListe = (second_niveau_t *)malloc(sizeof(second_niveau_t));
    if (TeteListe == NULL) {
        code = 0;
    } else {
        (*(*TeteListe)).suivant = NULL;
    }
    return code;
}

int ajouter_en_tete_second_niveau(second_niveau_t ** TeteListe, second_niveau_t * NouvelElement)
{
    int code = 1;
    (*NouvelElement).suivant = *TeteListe;
    *TeteListe = NouvelElement;
    return code;
}

void afficher_second_niveau(second_niveau_t * TeteListe)
{
    if (TeteListe != NULL) {
        while ((*TeteListe).suivant != NULL) {
            printf("jour : %c - heure : %c%c - action : %s\n ", (*TeteListe).jour[0], (*TeteListe).heure[0], (*TeteListe).heure[1], (*TeteListe).nom);
            TeteListe = (*TeteListe).suivant;
        }
    }
}