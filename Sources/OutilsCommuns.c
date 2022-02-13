#include "OutilsCommuns.h"
#include <stdlib.h>
#include <string.h>

/* -------------------------------------------------------- */
/* AfficherChaine   Affiche une chaîne de caractères        */
/*                                                          */
/* En entrée :                                              */
/*                                                          */
/* En sortie :                                              */
/*                                                          */
/* -------------------------------------------------------- */
void afficher_chaine(char mot[], int taille)
{
    for(int i=0; i<taille; i++){
        printf("%c", mot[i]);
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
void afficher_agenda(premier_niveau_t * TeteAgenda)
{
    if (TeteAgenda != NULL) {
        while ((*TeteAgenda).suivant != NULL) {
            printf("annee : ");
            afficher_chaine((*TeteAgenda).annee, TAILLE_ANNEE);
            printf(" - semaine : ");
            afficher_chaine((*TeteAgenda).semaine, TAILLE_SEMAINE);
            printf("\n");

            //afficher toutes les actions reliées a cette semaine
            if((*TeteAgenda).actions == NULL){
                printf("    pas d'actions ...\n");
            }else{
                while ((*(*TeteAgenda).actions).suivant != NULL) {
                    printf("    jour : ");
                    afficher_chaine((*(*TeteAgenda).actions).jour, TAILLE_JOUR);
                    printf(" - heure : ");
                    afficher_chaine((*(*TeteAgenda).actions).heure, TAILLE_HEURE);
                    printf(" - nom : ");
                    afficher_chaine((*(*TeteAgenda).actions).nom, TAILLE_NOM_ACTION);
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

int exister_dans_premier_niveau_agenda(premier_niveau_t * TeteAgenda, char * Annee, char * Semaine)
{
    int Existe = 0;
    if (TeteAgenda != NULL) {
        while ((*TeteAgenda).suivant != NULL && Existe == 0) {
            if (exister_dans_premier_niveau(TeteAgenda, Annee, Semaine) == 1) {
                Existe = 1;
            }
            TeteAgenda = (*TeteAgenda).suivant;
        }
    }
    return Existe;
}

int remplir_agenda(char * FichierLisible, premier_niveau_t ** Agenda)
{
    int code = 1;
    FILE * LeFichier = NULL;
    int TailleLigne = TAILLE_ANNEE + TAILLE_SEMAINE + TAILLE_JOUR
        + TAILLE_HEURE + TAILLE_NOM_ACTION + 3;
    char ligne[TailleLigne];
    char * LocalAnnee;
    char * LocalSemaine;
    char * LocalJour;
    char * LocalHeure;
    char * LocalNomAction;
    //
    LeFichier = fopen(FichierLisible, "r");
    if(LeFichier != NULL){
        while (fgets(ligne, TailleLigne, LeFichier) != NULL) {
            //printf("%s", ligne);
            LocalAnnee = retourner_milieu_chaine(ligne, 0, 4);
            LocalSemaine = retourner_milieu_chaine(ligne, 4, 6);
            LocalJour = retourner_milieu_chaine(ligne, 6, 7);
            LocalHeure = retourner_milieu_chaine(ligne, 7, 9);
            LocalNomAction = retourner_milieu_chaine(ligne, 9, 9+TAILLE_NOM_ACTION+3);

            printf("a=%s, s=%s, j=%s, h=%s, nom=%s", LocalAnnee, LocalSemaine, LocalJour, LocalHeure, LocalNomAction);
            //on regarde si newN1 existe deja dans Agenda
            if (exister_dans_premier_niveau_agenda(*Agenda, LocalAnnee, LocalSemaine)) {   
                //VRAI on ajoute une action
                printf(" => VRAI\n");
                //on crée l'action
                //on l'ajoute au bon endroit 
            } else {
                //FAUX on le cree
                printf(" => FAUX\n");
                premier_niveau_t * TeteNouveauBloc = NULL;
                second_niveau_t * Action = NULL;
                int a;
                a = allouer_second_niveau(&Action);
                a = allouer_premier_niveau(&TeteNouveauBloc);

                //on crée l'action
                strcpy((*Action).jour, LocalJour);
                strcpy((*Action).heure, LocalHeure);
                strcpy((*Action).nom, LocalNomAction);
                (*Action).suivant = NULL;

                strcpy((*TeteNouveauBloc).annee, LocalAnnee);
                strcpy((*TeteNouveauBloc).semaine, LocalSemaine);
                //on ajoute l'action 1er action
                (*TeteNouveauBloc).actions = Action;
                (*TeteNouveauBloc).suivant = NULL;
                
                //on ajoute le n1 au bon endroit
                ajouter_en_tete_premier_niveau(Agenda, TeteNouveauBloc);            
            }
            //on passe à la ligne suivante
            //lign2 = fgets(ligne, TailleLigne, LeFichier);
            
        }
        //
        fclose(LeFichier);
    }else{
        code = 0;
    }
    return code;
}