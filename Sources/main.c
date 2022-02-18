#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "OutilsCommuns.h"

int main(int argc, char * argv[])
{
    /*
    premier_niveau_t * TeteListe = NULL;
    premier_niveau_t * Elem1 = NULL;
    premier_niveau_t * Elem2 = NULL;
    second_niveau_t * ActiTete1 = NULL;
    second_niveau_t * Acti1 = NULL;
    second_niveau_t * Acti2 = NULL;
    int a;

    a = allouer_premier_niveau(&TeteListe);
    printf("a = %d\n", a);
    a = allouer_second_niveau(&ActiTete1);
    printf("a = %d\n", a);
    a = allouer_premier_niveau(&Elem1);
    printf("a = %d\n", a);
    a = allouer_premier_niveau(&Elem2);
    printf("a = %d\n", a);
    a = allouer_second_niveau(&Acti1);
    printf("a = %d\n", a);
    a = allouer_second_niveau(&Acti2);
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

    a = ajouter_en_tete_premier_niveau(&TeteListe, Elem1);
    printf("a = %d\n", a);
    a = ajouter_en_tete_premier_niveau(&TeteListe, Elem2);
    printf("a = %d\n", a);

    a = ajouter_en_tete_second_niveau(&ActiTete1, Acti1);
    printf("a = %d\n", a);
    a = ajouter_en_tete_second_niveau(&ActiTete1, Acti2);
    printf("a = %d\n", a);
    
    (*Elem1).actions = ActiTete1;*/

    premier_niveau_t * agenda = NULL;
    int a;
    a = allouer_premier_niveau(&agenda);
    a = remplir_agenda(argv[1], &agenda);
    printf("\na = %d\n", a);
    afficher_agenda(agenda);

    return 0;
}