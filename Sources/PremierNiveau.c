#include "PremierNiveau.h"
#include <stdlib.h>
#include <stdio.h>


int AllouerPremierNiveau(PremierNiveau_t ** TeteListe)
{
    int code = 1;
    *TeteListe = (PremierNiveau_t *)malloc(sizeof(PremierNiveau_t));
    if (TeteListe == NULL) {
        code = 0;
    } else {
        (*(*TeteListe)).suivant = NULL;
    }
    return code;
}

int AjouterEnTetePremierNiveau(PremierNiveau_t ** TeteListe, PremierNiveau_t * NouvelElement)
{
    int code = 1;
    NouvelElement->suivant = *TeteListe;
    *TeteListe = NouvelElement;
    return code;
}

void AfficherPremierNiveau(PremierNiveau_t * TeteListe)
{
    if (TeteListe != NULL) {
        while (TeteListe->suivant != NULL) {
            printf("annee : %s - semaine : %s\n", TeteListe->annee, TeteListe->semaine);
            TeteListe = TeteListe->suivant;
        }
    }
}