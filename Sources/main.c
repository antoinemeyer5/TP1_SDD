#include "OutilsCommuns.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
    premier_niveau_t * agenda = NULL;
    int a;
    
    printf("Il y a %d argument(s)\n", argc);

    a = allouer_premier_niveau(&agenda);
    a = remplir_agenda(argv[1], &agenda);
    printf("\na = %d\n", a);
    afficher_agenda(agenda);

    return 0;
}