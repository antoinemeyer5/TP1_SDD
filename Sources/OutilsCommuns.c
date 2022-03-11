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
    for (int i = 0; i < taille; i++)
    {
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
void afficher_agenda(premier_niveau_t *tete_agenda)
{
    if (tete_agenda != NULL)
    {
        while ((*tete_agenda).suivant != NULL)
        {
            printf("Semaine ");
            afficher_chaine((*tete_agenda).semaine, TAILLE_SEMAINE);
            printf(" de ");
            afficher_chaine((*tete_agenda).annee, TAILLE_ANNEE);
            printf("\n");
            if ((*tete_agenda).actions == NULL)
            {
                printf("    pas d'actions ... NE DEVRAIT PAS EXISTER\n");
            }
            else
            {
                afficher_second_niveau((*tete_agenda).actions);
            }
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
int remplir_agenda(char *fichier_lisible, premier_niveau_t **agenda)
{
    int code = 1;
    int a = -1;
    FILE *le_fichier = fopen(fichier_lisible, "r");
    int taille_ligne = TAILLE_ANNEE + TAILLE_SEMAINE + TAILLE_JOUR + TAILLE_HEURE + TAILLE_NOM_ACTION + 3;
    char ligne_courante[taille_ligne];

    premier_niveau_t *nouvelle_semaine = NULL, *semaine_existante = NULL;
    char *l_annee, *l_semaine;

    second_niveau_t *nouvelle_action = NULL;
    char *l_jour, *l_heure, *l_nom_action;

    if (le_fichier)
    {
        while (!feof(le_fichier) && fgets(ligne_courante, taille_ligne, le_fichier) != NULL)
        {
            l_annee = retourner_milieu_chaine(ligne_courante, 0, 4);
            l_semaine = retourner_milieu_chaine(ligne_courante, 4, 6);
            l_jour = retourner_milieu_chaine(ligne_courante, 6, 7);
            l_heure = retourner_milieu_chaine(ligne_courante, 7, 9);
            l_nom_action = retourner_milieu_chaine(ligne_courante, 9, 9 + TAILLE_NOM_ACTION + 3);

            allouer_second_niveau(&nouvelle_action);
            remplir_informations_second_niveau(nouvelle_action, l_jour, l_heure, l_nom_action);
            semaine_existante = retourner_semaine_existante_dans_agenda(*agenda, l_annee, l_semaine);

            if (semaine_existante != NULL)
            {
                ajouter_SN_bon_endroit(&(*semaine_existante).actions, nouvelle_action);
            }
            else
            {
                a = allouer_premier_niveau(&nouvelle_semaine);
                if (a == 1)
                {
                    remplir_informations_premier_niveau(nouvelle_semaine, l_annee, l_semaine);
                    ajouter_PN_bon_endroit(agenda, nouvelle_semaine);
                    ajouter_SN_bon_endroit(&(nouvelle_semaine->actions), nouvelle_action);
                }
            }
        }
        fclose(le_fichier);
    }
    else
    {
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
premier_niveau_t *retourner_semaine_existante_dans_agenda(premier_niveau_t *tete_agenda, char *annee, char *semaine)
{
    premier_niveau_t *semaine_retour = NULL;
    if (tete_agenda != NULL)
    {
        while ((*tete_agenda).suivant != NULL && semaine_retour == NULL)
        {
            if (exister_dans_premier_niveau(tete_agenda, annee, semaine) == 1)
            {
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
/*                                                          */
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
/* -------------------------------------------------------- */
void supprimer_action(premier_niveau_t **agenda, char *annee, char *semaine, char *jour, char *heure)
{
    premier_niveau_t **semaine_precedente = agenda;
    premier_niveau_t *nouveau_bloc = NULL;
    premier_niveau_t *tmp2;

    allouer_premier_niveau(&nouveau_bloc);
    remplir_informations_premier_niveau(nouveau_bloc, annee, semaine);

    while (*semaine_precedente != NULL && comparer_semaines_et_annees(*semaine_precedente, nouveau_bloc) != 1)
    {
        semaine_precedente = &(*(*semaine_precedente)).suivant;
    }

    if (*semaine_precedente)
    {
        (*(*semaine_precedente)).actions = supprimer_SN((*(*semaine_precedente)).actions, jour, heure);
        if ((*(*semaine_precedente)).actions == NULL)
        {
            tmp2 = *semaine_precedente;
            *semaine_precedente = (*(*semaine_precedente)).suivant;
            free(tmp2);
            free(nouveau_bloc);
        }
    }
}

/* -------------------------------------------------------- */
/* ecrire_ligne Ecrit une chaine d'une certaine taille dans */
/*              un fichier                                  */
/*                                                          */
/* En entrée : fichier, Pointeur de tête d'un fichier       */
/*             chaine, Chaîne à écrire                      */
/*             taille, Taille de la chaine à écrire         */
/* -------------------------------------------------------- */
void ecrire_ligne(FILE *fichier, char *chaine, int taille)
{
    for (int i = 0; i < taille; i++)
    {
        if (chaine[i] != NULL && chaine[i] != '\n')
        {
            fprintf(fichier, "%c", chaine[i]);
        }
    }
}

/* -------------------------------------------------------- */
/* sauvegarder_agenda   Sauvegarde un agenda dans un fichier*/
/*                                                          */
/* En entrée : fichier_a_remplir, Fichier à remplir         */
/*             agenda, Pointeur de tête de l'agenda         */
/*                                                          */
/* En sortie : Rien                                         */
/* -------------------------------------------------------- */
void sauvegarder_agenda(char *fichier_a_remplir, premier_niveau_t *agenda)
{
    FILE *fichier = fopen(fichier_a_remplir, "w");
    premier_niveau_t *semaine_courante = agenda;
    second_niveau_t *action_courante = NULL;
    if (fichier)
    {
        while (semaine_courante != NULL)
        {
            action_courante = (*semaine_courante).actions;
            while (action_courante != NULL)
            {
                ecrire_ligne(fichier, (*semaine_courante).annee, TAILLE_ANNEE);
                ecrire_ligne(fichier, (*semaine_courante).semaine, TAILLE_SEMAINE);
                ecrire_ligne(fichier, (*action_courante).jour, TAILLE_JOUR);
                ecrire_ligne(fichier, (*action_courante).heure, TAILLE_HEURE);
                ecrire_ligne(fichier, (*action_courante).nom, TAILLE_NOM_ACTION);
                fprintf(fichier, "\n");
                action_courante = (*action_courante).suivant;
            }
            semaine_courante = (*semaine_courante).suivant;
        }
    }
    fclose(fichier);
}