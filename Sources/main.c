#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "OutilsCommuns.h"

int main(int argc, char * argv[])
{
    PremierNiveau_t * TeteListe = NULL;
    PremierNiveau_t * Elem1 = NULL;
    PremierNiveau_t * Elem2 = NULL;
    SecondNiveau_t * ActiTete1 = NULL;
    SecondNiveau_t * Acti1 = NULL;
    SecondNiveau_t * Acti2 = NULL;
    int a;

    a = AllouerPremierNiveau(&TeteListe);
    printf("a = %d\n", a);
    a = AllouerSecondNiveau(&ActiTete1);
    printf("a = %d\n", a);
    a = AllouerPremierNiveau(&Elem1);
    printf("a = %d\n", a);
    a = AllouerPremierNiveau(&Elem2);
    printf("a = %d\n", a);
    a = AllouerSecondNiveau(&Acti1);
    printf("a = %d\n", a);
    a = AllouerSecondNiveau(&Acti2);
    printf("a = %d\n", a);

    strcpy((*Elem1).annee, "1999");
    strcpy((*Elem1).semaine, "04");
    (*Elem1).actions = NULL;
    (*Elem1).suivant = NULL;

    strcpy((*Elem2).annee, "2026");
    strcpy((*Elem2).semaine, "03");
    (*Elem2).actions = NULL;
    (*Elem2).suivant = NULL;

    strcpy((*Acti1).jour, "2");
    strcpy((*Acti1).heure, "10");
    strcpy((*Acti1).nom, "Test");
    (*Acti1).suivant = NULL;

    strcpy((*Acti2).jour, "4");
    strcpy((*Acti2).heure, "23");
    strcpy((*Acti2).nom, "Te st 2azdjaudadzubd");
    (*Acti2).suivant = NULL;

    a = AjouterEnTetePremierNiveau(&TeteListe, Elem1);
    printf("a = %d\n", a);
    a = AjouterEnTetePremierNiveau(&TeteListe, Elem2);
    printf("a = %d\n", a);

    a = AjouterEnTeteSecondNiveau(&ActiTete1, Acti1);
    printf("a = %d\n", a);
    a = AjouterEnTeteSecondNiveau(&ActiTete1, Acti2);
    printf("a = %d\n", a);
    
    (*Elem1).actions = ActiTete1;


    //AfficherPremierNiveau(TeteListe);

    //FILE * f = fopen("fi.txt", "r");
    //RemplirPremierNiveau(TeteListe, f);

    AfficherAgenda(TeteListe);

    printf("il y a %d arguments\n", argc);

    a = RemplirAgenda(argv[1], &TeteListe);
    printf("a = %d\n", a);
    
    return 0;
}