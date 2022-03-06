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
    //premier_niveau_t * courant = tete_agenda;
    if (tete_agenda != NULL) {
        // Parcours de la liste des semaines
        while ((*tete_agenda).suivant != NULL) {
            printf("Semaine ");
            afficher_chaine((*tete_agenda).semaine, TAILLE_SEMAINE);
            printf(" de ");
            afficher_chaine((*tete_agenda).annee, TAILLE_ANNEE);
            printf("\n");
            // Test de présence d'actions pour une semaine
            if ((*tete_agenda).actions == NULL) {
                printf("    pas d'actions ... NE DEVRAIT PAS EXISTER\n");
            } else {
                // Parcours de la liste des actions
                afficher_second_niveau((*tete_agenda).actions);
            }
            // Passage à la semaine suivante dans la liste de semaines
            tete_agenda = (*tete_agenda).suivant;
            printf("\n");
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
    premier_niveau_t * nouvelle_semaine = NULL, * semaine_existante = NULL;
    char * l_annee, * l_semaine;
    // Variables spécifiques à la création d'une nouvelle action
    //second_niveau_t * tete_nouvelle_action = NULL, * nouvelle_action = NULL;
    second_niveau_t * nouvelle_action = NULL;
    char * l_jour, * l_heure, * l_nom_action;
    // Variable équivalente à un code de bon fonctionnement ou d'erreur
    int a;
    // Ouverture du fichier à lire 
    le_fichier = fopen(fichier_lisible, "r");
    if(le_fichier != NULL){
        //a = allouer_second_niveau(&tete_nouvelle_action);
        while (fgets(ligne_courante, taille_ligne, le_fichier) != NULL) {
            // Récupération des informations contenues dans une ligne du fichier
            l_annee = retourner_milieu_chaine(ligne_courante, 0, 4);
            l_semaine = retourner_milieu_chaine(ligne_courante, 4, 6);
            l_jour = retourner_milieu_chaine(ligne_courante, 6, 7);
            l_heure = retourner_milieu_chaine(ligne_courante, 7, 9);
            l_nom_action = retourner_milieu_chaine(ligne_courante, 9, 9+TAILLE_NOM_ACTION+3);
            // Création d'une nouvelle action
            a = allouer_second_niveau(&nouvelle_action);
            // Remplissage des informations de la nouvelle action
            remplir_informations_second_niveau(nouvelle_action, l_jour, l_heure, l_nom_action);
            // Ajoute de la nouvelle action dans une semaine déjà existante
            semaine_existante = retourner_semaine_existante_dans_agenda(*agenda, l_annee, l_semaine);
            // Test si la potentielle nouvelle action existe déjà dans l'agenda
            // Si on a bien trouvé la semaine existante
            if (semaine_existante != NULL) {   
                // Ajout de la nouvelle action à la liste d'action 
                a = ajouter_DN_bon_endroit(&(*semaine_existante).actions, nouvelle_action);
            } else {
                // Création d'un nouveau premier niveau
                //a = allouer_premier_niveau(&nouvelle_semaine);
                nouvelle_semaine = (premier_niveau_t *)malloc(sizeof(premier_niveau_t));
                // Vérification l'allocation de la semaine s'est bien passée
                if (nouvelle_semaine != NULL) {
                    // Remplissage des informations de la nouvelle semaine
                    remplir_informations_premier_niveau(nouvelle_semaine, l_annee, l_semaine);
                    // Ajout de la nouvelle semaine à l'agenda                    
                    a = ajouter_PN_bon_endroit(agenda, nouvelle_semaine);
                    // Ajout de la nouvelle action à la liste d'action 
                    a = ajouter_DN_bon_endroit(&(nouvelle_semaine->actions), nouvelle_action);
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

/* -------------------------------------------------------- */
/* retourner_semaine_existante_dans_agenda  Test si un      */
/*                                                          */
/* En entrée :                                              */
/*                                                          */
/* En sortie :                                              */
/* -------------------------------------------------------- */
premier_niveau_t * retourner_semaine_existante_dans_agenda(premier_niveau_t * tete_agenda, char * annee, char * semaine)
{
    premier_niveau_t * semaine_retour = NULL;
    if (tete_agenda != NULL) {
        while ((*tete_agenda).suivant != NULL && semaine_retour == NULL) {
            if (exister_dans_premier_niveau(tete_agenda, annee, semaine) == 1) {
                semaine_retour = tete_agenda;
            }
            tete_agenda = (*tete_agenda).suivant;
        }
    }
    return semaine_retour;
}