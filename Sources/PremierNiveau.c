#include "PremierNiveau.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//fonction qui prend un string et un nombre de caractère à afficher et les affichent
// sera utile pour annee et semaine mais surtout pour le nom qui ne doit pas avoir de \0 à la fin

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
    (*NouvelElement).suivant = *TeteListe;
    *TeteListe = NouvelElement;
    return code;
}