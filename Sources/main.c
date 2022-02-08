#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "PremierNiveau.h"

int main()
{
    PremierNiveau_t * TeteListe = NULL;
    PremierNiveau_t * Elem1 = NULL;
    PremierNiveau_t * Elem2 = NULL;
    int a;

    a = AllouerPremierNiveau(&TeteListe);
    printf("a = %d\n", a);
    a = AllouerPremierNiveau(&Elem1);
    printf("a = %d\n", a);
    a = AllouerPremierNiveau(&Elem2);
    printf("a = %d\n", a);

    strcpy(Elem1->annee, "1999");
    strcpy((*Elem1).semaine, "04");
    Elem1->actions = NULL;
    Elem1->suivant = NULL;

    strcpy((*Elem2).annee, "2026");
    strcpy((*Elem2).semaine, "03");
    Elem2->actions = NULL;
    Elem2->suivant = NULL;

    a = AjouterEnTetePremierNiveau(&TeteListe, Elem1);
    printf("a = %d\n", a);
    a = AjouterEnTetePremierNiveau(&TeteListe, Elem2);
    printf("a = %d\n", a);
    
    AfficherPremierNiveau(TeteListe);
    
    return 0;
}