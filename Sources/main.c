/* -------------------------------------------------------- */
/* main.c : Contient le main du dossier                     */
/* -------------------------------------------------------- */

#include "OutilsCommuns.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* -------------------------------------------------------- */
/* main Fonction principale qui passe en revue toutes les   */
/*      questions du TP1 de Structure de données - langage C*/
/*                                                          */
/* En entrée : argc, Nombre d'arguments passés en ligne de  */
/*             commande                                     */
/*             argv, Liste des arguments passés             */
/* -------------------------------------------------------- */
int main(int argc, char *argv[])
{
    premier_niveau_t *agenda = NULL;
    char liste_dates[1000];
    char *motif = "a";

    printf("Il y a %d argument(s)\n", argc);

    if (argc == 2)
    {
        allouer_premier_niveau(&agenda);
        // question 1
        printf("\nQuestion 1 : remplir l'agenda à partir du fichier 'fi_3.txt'.\n");
        remplir_agenda(argv[1], &agenda);
        afficher_agenda(agenda);
        // question 2.1
        printf("\nQuestion 2.1 : sauvegarder l'agenda.\n");
        printf("Sauvegarde dans le fichier 'fi_save.txt'\n");
        sauvegarder_agenda("fi_save.txt", agenda);
        // question 2.2
        printf("\nQuestion 2.2 : recherche de motif.\n");
        rechercher_motif_premier_niveau(liste_dates, motif, agenda);
        printf("Le motif (%s) a été trouvé ici dans ces jours : %s\n", motif, liste_dates);
        // question 3
        printf("\nQuestion 3 : suppression d'une action.\n");
        supprimer_action(&agenda, "1912", "16", "4", "18");
        afficher_agenda(agenda);
        printf("\nFin du programme principal.\n");
    }
    else
    {
        printf("Pas assez ou trop d'arguments pour un bon fonctionnement.\n");
        printf("Essayez quelque chose comme : ./main [nom d'un fichier].txt\n");
    }
    return 0;
}