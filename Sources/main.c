/* -------------------------------------------------------- */
/* main.c : Contient le main du dossier                     */
/* -------------------------------------------------------- */

#include "OutilsCommuns.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char * argv[])
{
    premier_niveau_t * agenda;
    agenda = NULL;
    /*char *sup_annee = "1912";
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
    afficher_agenda(agenda);*/

    //quand [1]->[2]->[3]
    //supprimer le 3 fonctionne
    //PROBLEME avec 1 ET 2

    //quand [1] seul
    //supprimer action ok 
    //PROBLEME avec suppression de la semaine

    char * fichier_lisible = "fi.txt";
    remplir_agenda(fichier_lisible, &agenda);
    afficher_agenda(agenda);

    char * fichier_a_remplir ="fi_2.txt";
    sauvegarder_agenda(fichier_a_remplir, agenda);

    return 0;
}