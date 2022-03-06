#include "OutilsCommuns.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
    premier_niveau_t * agenda;
    agenda = NULL;
    int a;
    printf("Il y a %d argument(s)\n", argc);
    a = allouer_premier_niveau(&agenda);
    printf("a = %d : allouer premier niveau\n", a);
    a = remplir_agenda(argv[1], &agenda);
    printf("a = %d : remplir l'agenda\n", a);
    afficher_agenda(agenda);
    return 0;
}