#include "OutilsCommuns.h"
#include <stdlib.h>
#include <string.h>

/* -------------------------------------------------------- */
/* afficher_chaine   Affiche une chaîne de caractères       */
/*                                                          */
/* En entrée :  mot, Une chaîne de caractères               */
/*              taille, Un entier                           */
/*                                                          */
/* En sortie : Rien mais écrit la chaîne dans la sortie     */
/*             standard                                     */
/* -------------------------------------------------------- */
void afficher_chaine(char mot[], int taille)
{
    for (int i = 0; i < taille; i++) {
        printf("%c", mot[i]);
    }
}

/* -------------------------------------------------------- */
/* afficher_agenda   Affiche l'agenda au complet            */
/*                                                          */
/* En entrée : tete_agenda, Pointeur sur le premier         */
/*             élement de la liste chaînée                  */
/*                                                          */
/* En sortie : Rien mais écrit dans la sortie standard      */
/* -------------------------------------------------------- */
void afficher_agenda(premier_niveau_t * tete_agenda)
{
    if (tete_agenda != NULL) {
        // Parcours de la liste des semaines
        while ((*tete_agenda).suivant != NULL) {
            printf("annee : ");
            afficher_chaine((*tete_agenda).annee, TAILLE_ANNEE);
            printf(" - semaine : ");
            afficher_chaine((*tete_agenda).semaine, TAILLE_SEMAINE);
            printf("\n");
            // Test de présence d'actions pour une semaine
            if ((*tete_agenda).actions == NULL) {
                printf("    pas d'actions ...\n");
            } else {
                // Parcours de la liste des actions
                while ((*(*tete_agenda).actions).suivant != NULL) {
                    printf("    jour : ");
                    afficher_chaine((*(*tete_agenda).actions).jour, TAILLE_JOUR);
                    printf(" - heure : ");
                    afficher_chaine((*(*tete_agenda).actions).heure, TAILLE_HEURE);
                    printf(" - nom : ");
                    afficher_chaine((*(*tete_agenda).actions).nom, TAILLE_NOM_ACTION);
                    printf("\n");
                    // Passage à l'action suivante dans la liste d'actions
                    (*tete_agenda).actions = (*(*tete_agenda).actions).suivant;
                }
            }
            // Passage à la semaine suivante dans la liste de semaines
            tete_agenda = (*tete_agenda).suivant;
        }
    }
}

/* -------------------------------------------------------- */
/* exister_dans_premier_niveau_agenda   Test si une semaine */
/*                                      existe déjà ou non  */
/*                                                          */
/* En entrée : premier_niveau_t, Pointeur de tête de        */
/*             l'agenda que l'on étudie                     */
/*             annee, chaîne représentant l'année           */
/*             semaine, chaîne représentant la semaine      */
/*                                                          */
/* En sortie : La valeur entière retournée est 1 si un bloc */
/*             possède déjà l'année et la semaine passées;  */
/*             0 sinon.                                     */
/* -------------------------------------------------------- */
int exister_dans_premier_niveau_agenda(premier_niveau_t * tete_agenda, char * annee, char * semaine)
{
    int existe = 0;
    if (tete_agenda != NULL) {
        while ((*tete_agenda).suivant != NULL && existe == 0) {
            if (exister_dans_premier_niveau(tete_agenda, annee, semaine) == 1) {
                existe = 1;
            }
            tete_agenda = (*tete_agenda).suivant;
        }
    }
    return existe;
}

/* -------------------------------------------------------- */
/* remplir_agenda WIP                                       */
/*                          WORK IN PROGRESS                */
/*                          WORK IN PROGRESS                */
/*                          WORK IN PROGRESS                */
/*                          WORK IN PROGRESS                */
/* -------------------------------------------------------- */
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