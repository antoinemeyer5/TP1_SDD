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
int remplir_agenda(char * fichier_lisible, premier_niveau_t ** agenda)
{
    int code = 1;
    FILE * le_fichier = NULL;
    // Fixation de la taille d'une ligne d'un fichier à lire
    int taille_ligne = TAILLE_ANNEE + TAILLE_SEMAINE + TAILLE_JOUR + TAILLE_HEURE + TAILLE_NOM_ACTION + 3;
    char ligne_courante[taille_ligne];
    // Variables spécifiques à la création d'une nouvelle semaine
    premier_niveau_t * nouvelle_semaine = NULL;
    char * l_annee;
    char * l_semaine;
    // Variables spécifiques à la création d'une nouvelle action
    second_niveau_t * tete_nouvelle_action = NULL;
    second_niveau_t * nouvelle_action = NULL;
    char * l_jour;
    char * l_heure;
    char * l_nom_action;
    // Variable équivalente à un code de bon fonctionnement ou d'erreur
    int a;
    // Ouverture du fichier à lire 
    le_fichier = fopen(fichier_lisible, "r");
    if(le_fichier != NULL){
        while (fgets(ligne_courante, taille_ligne, le_fichier) != NULL) {
            // Récupération des informations contenues dans une ligne du fichier
            l_annee = retourner_milieu_chaine(ligne_courante, 0, 4);
            l_semaine = retourner_milieu_chaine(ligne_courante, 4, 6);
            l_jour = retourner_milieu_chaine(ligne_courante, 6, 7);
            l_heure = retourner_milieu_chaine(ligne_courante, 7, 9);
            l_nom_action = retourner_milieu_chaine(ligne_courante, 9, 9+TAILLE_NOM_ACTION+3);
            // Création d'une nouvelle action
            a = allouer_second_niveau(&tete_nouvelle_action);
            a = allouer_second_niveau(&nouvelle_action);
                        // CHECK A SI VAUT 1

            // Remplissage des informations de la nouvelle action
            strcpy((*nouvelle_action).jour, l_jour);
            strcpy((*nouvelle_action).heure, l_heure);
            strcpy((*nouvelle_action).nom, l_nom_action);
            (*nouvelle_action).suivant = NULL;
            // Affichage aide au debug
            //printf("a=%s, s=%s, j=%s, h=%s, nom=%s\n", l_annee, l_semaine, l_jour, l_heure, l_nom_action);
            // Test si la potentielle nouvelle action existe déjà dans l'agenda
            if (exister_dans_premier_niveau_agenda(*agenda, l_annee, l_semaine)) {   
                // Ajoute de la nouvelle action dans une semaine déjà existante
                printf(" => VRAI\n");
                //on l'ajoute au bon endroit 
                
                //a = ajouter_en_tete_second_niveau(&tete_nouvelle_action, nouvelle_action);

                //blalblalalal
            } else {
                // Création d'une nouvelle semaine
                a = allouer_premier_niveau(&nouvelle_semaine);
                // Vérification l'allocation de la semaine s'est bien passée
                if (a == 1) {
                    // Remplissage des informations de la nouvelle semaine
                    strcpy((*nouvelle_semaine).annee, l_annee);
                    strcpy((*nouvelle_semaine).semaine, l_semaine);
                    (*nouvelle_semaine).actions = NULL;
                    (*nouvelle_semaine).suivant = NULL;
                    // Ajout de la nouvelle semaine à l'agenda
                    a = ajouter_en_tete_premier_niveau(agenda, nouvelle_semaine);
                    // Ajout de la nouvelle action à la liste d'action 
                    a = ajouter_en_tete_second_niveau(&tete_nouvelle_action, nouvelle_action);
                    // Branchement entre l'action et la semaine
                    (*nouvelle_semaine).actions = tete_nouvelle_action;
                }
            }
        }
        // Fermeture du fichier une fois lu entièrement
        fclose(le_fichier);
    }else{
        code = 0;
    }
    return code;
}
