/* -------------------------------------------------------- */
/* OutilsCommuns.c : Contient l'ensemble des fonctions      */
/*                   liées à l'agenda                       */
/* -------------------------------------------------------- */

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
/* remplir_agenda   Fonction qui s'occupe de remplir un     */
/*                  agenda à partir d'un fichier            */
/*                                                          */
/* En entrée : fichier_lisible, Nom d'un fichier que l'on va*/
/*             lire afin de remplir l'agenda                */
/*                                                          */
/* En entrée/sortie : agenda, Pointeur de pointeur de tête  */
/*                    afin de remplir l'agenda qui est une  */
/*                    structure de premier niveau           */
/*                                                          */
/* En sortie : Code qui permet de savoir si le fichier a    */
/*             bien été lu et bien remplie                  */
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
    second_niveau_t * nouvelle_action = NULL;
    char * l_jour, * l_heure, * l_nom_action;
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
            a = allouer_second_niveau(&nouvelle_action);
            // Remplissage des informations de la nouvelle action
            remplir_informations_second_niveau(nouvelle_action, l_jour, l_heure, l_nom_action);
            // Ajoute de la nouvelle action dans une semaine déjà existante
            semaine_existante = retourner_semaine_existante_dans_agenda(*agenda, l_annee, l_semaine);
            // Test si la potentielle nouvelle action existe déjà dans l'agenda
            if (semaine_existante != NULL) {   
                a = ajouter_SN_bon_endroit(&(*semaine_existante).actions, nouvelle_action);
            } else {
                a = allouer_premier_niveau(&nouvelle_semaine);
                if (a == 1) {
                    // Remplissage des informations de la nouvelle semaine
                    remplir_informations_premier_niveau(nouvelle_semaine, l_annee, l_semaine);
                    // Ajout de la nouvelle semaine à l'agenda                    
                    a = ajouter_PN_bon_endroit(agenda, nouvelle_semaine);
                    a = ajouter_SN_bon_endroit(&(nouvelle_semaine->actions), nouvelle_action);
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
/* retourner_semaine_existante_dans_agenda  Test si une     */
/*                                          semaine existe  */
/*                                          déjà            */
/*                                                          */
/* En entrée : tete_agenda, Pointeur de tête de l'agenda    */
/*             étudié                                       */
/*             annee, Chaîne représentant l'année           */
/*             semaine, Chaîne représentant la semaine      */
/*                                                          */
/* En sortie : La semaine trouvée ou null                   */
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

/* -------------------------------------------------------- */
/* supprimer_action   Supprime une action donnée dans       */
/*                    l'agenda                              */
/* En entrée : agenda, Pointeur indirect de tête de         */
/*                     l'agenda étudié                      */
/*             annee, Chaîne représentant l'année de        */
/*                    l'action à supprimer                  */
/*             semaine, Chaîne représentant la semaine de   */
/*                      l'action à supprimer                */
/*             jour, Chaîne représentant le jour de         */
/*                   l'action à supprimer                   */
/*             heure, Chaîne représentant l'heure de        */
/*                    l'action à supprimer                  */ 
/* En sortie : 0                                            */
/* -------------------------------------------------------- */
int supprimer_action(premier_niveau_t ** agenda, char * annee, char * semaine, char * jour, char * heure)
{
    premier_niveau_t ** semaine_precedente = agenda;
    //premier_niveau_t ** semaine_courante = &(*agenda)->suivant;
    //faire un pointeur simple pour le courant
    premier_niveau_t * nouveau_bloc = NULL;
    premier_niveau_t * tmp2;

    

    int a;
    printf("début suppresion ...\n");
    a = allouer_premier_niveau(&nouveau_bloc);
    printf("a = %d\n", a);
    remplir_informations_premier_niveau(nouveau_bloc, annee, semaine);
    //tant qu'on n'a pas trouvé la semaine (premier niveau) à supprimer on avance
    while (*semaine_precedente != NULL && comparer_semaines_et_annees(*semaine_precedente, nouveau_bloc) != 1) {
        semaine_precedente = &(*semaine_precedente)->suivant;
        //semaine_courante = &(*semaine_courante)->suivant;
    }
    //si on trouve le premier niveau
    if (*semaine_precedente) {
        printf("[X] semaine trouvée\n");
        printf("semaine trouvee :%s; :%s\n", (*semaine_precedente)->annee, (*semaine_precedente)->semaine);
        (*semaine_precedente)->actions = supprimer_SN((*semaine_precedente)->actions, jour, heure);
        printf("allez la\n");
        //si le premier niveau est vide
        if ((*semaine_precedente)->actions == NULL ) {
            //on change le suivant et
            tmp2 = *semaine_precedente;
            *semaine_precedente = (*semaine_precedente)->suivant;
            //on supprime le 1er niveau
            free(tmp2);
            //on déalloue la semaine qu'on cherche
            free(nouveau_bloc);
        }     
    }
    

    printf("suppresion finie.\n");
    //return 0 si mal passée
    //return 1 si on a supprime quelque chose
    //return -1 si on n'a rien supprimé
    return 0;
}

/* -------------------------------------------------------- */
/* sauvegarder_agenda         Sauvegarde un agenda          */
/*                            dans un fichier               */
/* En entrée : fichier_a_remplir, Fichier à remplir         */
/*             agenda, Pointeur de tête de l'agenda        */
/* En sortie : Rien                                         */
/* -------------------------------------------------------- */
void sauvegarder_agenda(char * fichier_a_remplir, premier_niveau_t * agenda)
{
    int deb;
    char tache[TAILLE_ANNEE+TAILLE_SEMAINE+TAILLE_JOUR+TAILLE_HEURE+TAILLE_NOM_ACTION+2];
    second_niveau_t * action;
    FILE * fichier = NULL;
    fichier = fopen(fichier_a_remplir, "w");

    while (agenda != NULL) {
        action = (*agenda).actions;

        while (action != NULL) {
            deb = 0;

            for (int i=0; i<TAILLE_ANNEE; i++) {
                tache[deb] = (*agenda).annee[i];
                deb++;
            }

            for (int i=0; i<TAILLE_SEMAINE; i++) {
                tache[deb] = (*agenda).semaine[i];
                deb++;
            }

            for (int i=0; i<TAILLE_JOUR; i++) {
                tache[deb] = (*action).jour[i];
                deb++;
            }

            for (int i=0; i<TAILLE_HEURE; i++) {
                tache[deb] = (*action).heure[i];
                deb++;
            }

            for (int i=0; i<TAILLE_NOM_ACTION; i++) {
                tache[deb] = (*action).nom[i];
                deb++;
            }

            tache[deb] = '\n';
            tache[deb+1] = '\0';

            fprintf(fichier, "%s", tache);

            action = (*action).suivant;
        }
        agenda = (*agenda).suivant;
    }
    fclose(fichier);
}