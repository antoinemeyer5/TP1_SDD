#include "OutilsCommuns.h"

/* -------------------------------------------------------- */
/* AfficherChaine   Affiche une chaîne de caractères        */
/*                                                          */
/* En entrée :                                              */
/*                                                          */
/* En sortie :                                              */
/*                                                          */
/* -------------------------------------------------------- */
void AfficherChaine(char Mot[], int TailleMot)
{
    for(int i=0; i<TailleMot; i++){
        printf("%c", Mot[i]);
    }
}

/* -------------------------------------------------------- */
/* AfficherAgenda   Affiche l'agenda au complet             */
/*                                                          */
/* En entrée :                                              */
/*                                                          */
/* En sortie :                                              */
/*                                                          */
/* -------------------------------------------------------- */
void AfficherAgenda(PremierNiveau_t * TeteAgenda)
{
    if (TeteAgenda != NULL) {
        while ((*TeteAgenda).suivant != NULL) {
            printf("annee : ");
            AfficherChaine((*TeteAgenda).annee, TAILLE_ANNEE);
            printf(" - semaine : ");
            AfficherChaine((*TeteAgenda).semaine, TAILLE_SEMAINE);
            printf("\n");

            //afficher toutes les actions reliées a cette semaine
            if((*TeteAgenda).actions == NULL){
                printf("    pas d'actions ...\n");
            }else{
                while ((*(*TeteAgenda).actions).suivant != NULL) {
                    printf("    jour : ");
                    AfficherChaine((*(*TeteAgenda).actions).jour, TAILLE_JOUR);
                    printf(" - heure : ");
                    AfficherChaine((*(*TeteAgenda).actions).heure, TAILLE_HEURE);
                    printf(" - nom : ");
                    AfficherChaine((*(*TeteAgenda).actions).nom, TAILLE_NOM_ACTION);
                    printf("\n");

                    //
                    (*TeteAgenda).actions = (*(*TeteAgenda).actions).suivant;
                }
            }
            //
            TeteAgenda = (*TeteAgenda).suivant;
        }
    }
}

int RemplirAgenda(char * FichierLisible, PremierNiveau_t ** Agenda)
{
    int code = 1;
    FILE * LeFichier = NULL;
    LeFichier = fopen(FichierLisible, "r");
    if(LeFichier != NULL){
        //traitementFichierCarac(LeFichier);
        
        fclose(LeFichier);
    }else{
        code = 0;
    }
    return code;
}