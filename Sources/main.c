#include "OutilsCommuns.h"
#include <stdio.h>
#include <stdlib.h>

/*int main(int argc, char * argv[])
{
    premier_niveau_t * agenda;
    agenda = NULL;
    char *sup_annee = "1912";
    char *sup_semaine = "16";
    char *sup_jour = "4";
    char *sup_heure = "18";
    int a;
    printf("Il y a %d argument(s)\n", argc);
    a = allouer_premier_niveau(&agenda);
    printf("a = %d : allouer premier niveau\n", a);
    a = remplir_agenda(argv[1], &agenda);
    printf("a = %d : remplir l'agenda\n", a);
    afficher_agenda(agenda);
    a = supprimer_action(&agenda, sup_annee, sup_semaine, sup_jour, sup_heure);
    printf("a = %d : état suppresion\n", a);
    afficher_agenda(agenda);

    //quand [1]->[2]->[3]
    //supprimer le 3 fonctionne
    //PROBLEME avec 1 ET 2

    //quand [1] seul
    //supprimer action ok 
    //PROBLEME avec suppression de la semaine

    return 0;
}*/

int main(int argc, char * argv[])
{

    
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
    strcpy((*Acti2).nom, "Te st 2azd");
    (*Acti2).suivant = NULL;
    a = ajouter_en_tete_premier_niveau(&TeteListe, Elem1);
    printf("a = %d\n", a);
    a = ajouter_en_tete_premier_niveau(&TeteListe, Elem2);
    printf("a = %d\n", a);
    a = ajouter_en_tete_second_niveau(&ActiTete1, Acti1);
    printf("a = %d\n", a);
    a = ajouter_en_tete_second_niveau(&ActiTete1, Acti2);
    printf("a = %d\n", a);
    
    (*Elem1).actions = ActiTete1;

    afficher_agenda(TeteListe);

    char * fichier = "fi_2.txt";
    sauvegarder_agenda(fichier, TeteListe);

    return 0;
}