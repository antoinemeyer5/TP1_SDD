#include "SecondNiveau.h"
#include <stdlib.h>
#include <stdio.h>


int AllouerSecondNiveau(SecondNiveau_t ** TeteListe)
{
    int code = 1;
    *TeteListe = (SecondNiveau_t *)malloc(sizeof(SecondNiveau_t));
    if (TeteListe == NULL) {
        code = 0;
    } 
    else 
    {
        (*(*TeteListe)).suivant = NULL;
    }
    return code;
}

int AjouterEnTeteSecondNiveau(SecondNiveau_t ** TeteListe, SecondNiveau_t * NouvelElement)
{
    int code = 1;
    (*NouvelElement).suivant = *TeteListe;
    *TeteListe = NouvelElement;
    return code;
}

void AfficherSecondNiveau(SecondNiveau_t * TeteListe)
{
    if (TeteListe != NULL) 
    {
        while ((*TeteListe).suivant != NULL)
        {
            printf("jour : %c - heure : %c%c - action : %s\n ", (*TeteListe).jour[0], (*TeteListe).heure[0], (*TeteListe).heure[1], (*TeteListe).nom);
            TeteListe = (*TeteListe).suivant;
        }
    }
}