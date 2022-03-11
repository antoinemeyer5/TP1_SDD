/* -------------------------------------------------------- */
/* main.c : Contient le main du dossier                     */
/* -------------------------------------------------------- */

#include "OutilsCommuns.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* -------------------------------------------------------- */
/* rechercher_motif_premier_niveau   Affiche la liste       */
/*                                   des dates avec         */
/*                                   une action contenant   */
/*                                   un motif donné         */
/*                                                          */
/* En entrée : motif, Chaine de caractères à chercher       */
/*             liste, Pointeur d'une liste d'actions        */
/*                                                          */
/* En entrée/sortie : liste_dates, Pointeur d'une liste     */
/*                    de dates                              */
/* -------------------------------------------------------- */
int main(int argc, char * argv[])
{
    premier_niveau_t * agenda;
    char liste_dates[100];
    //char * fichier_a_remplir = "fi_2.txt";
    agenda = NULL;

    int a;
    printf("Il y a %d argument(s)\n", argc);
    a = allouer_premier_niveau(&agenda);
    printf("a = %d : allouer premier niveau\n", a);
    a = remplir_agenda(argv[1], &agenda);
    printf("a = %d : remplir l'agenda\n", a);
    afficher_agenda(agenda);


    rechercher_motif_premier_niveau(liste_dates, "e", agenda);
    printf("=> %s\n", liste_dates);


    //a = supprimer_action(&agenda, "1912", "16", "4", "18");
    //printf("a = %d : état suppresion\n", a);
    //afficher_agenda(agenda);
    //sauvegarder_agenda(fichier_a_remplir, agenda);


    return 0;
}