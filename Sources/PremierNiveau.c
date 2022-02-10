#include "PremierNiveau.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int AllouerPremierNiveau(PremierNiveau_t ** TeteListe)
{
    int code = 1;
    *TeteListe = (PremierNiveau_t *)malloc(sizeof(PremierNiveau_t));
    if (TeteListe == NULL) 
    {
        code = 0;
    } 
    else 
    {
        (*(*TeteListe)).suivant = NULL;
    }
    return code;
}

int AjouterEnTetePremierNiveau(PremierNiveau_t ** TeteListe, PremierNiveau_t * NouvelElement)
{
    int code = 1;
    (*NouvelElement).suivant = *TeteListe;
    *TeteListe = NouvelElement;
    return code;
}

void AfficherPremierNiveau(PremierNiveau_t * TeteListe)
{
    if (TeteListe != NULL) 
    {
        while ((*TeteListe).suivant != NULL)
        {
            printf("annee : %c%c%c%c - semaine : %c%c\n", (*TeteListe).annee[0], (*TeteListe).annee[1], (*TeteListe).annee[2], (*TeteListe).annee[3], (*TeteListe).semaine[0], (*TeteListe).semaine[1]);
            TeteListe = (*TeteListe).suivant;
        }
    }
}

void RemplirPremierNiveau(PremierNiveau_t * TeteListe, FILE * fichier)
{
    char * c;

    fgets(c, 4, fichier);
    //strcpy((*TeteListe).annee, c);

    //fgets(c, 2, fichier);
    //strcpy((*TeteListe).semaine, c);
}