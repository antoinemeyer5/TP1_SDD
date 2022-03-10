/* -------------------------------------------------------- */
/* SecondNiveau.c : Contient l'ensemble des fonctions       */
/*                  liées au second niveau                  */
/* -------------------------------------------------------- */

#include "OutilsCommuns.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* -------------------------------------------------------- */
/* allouer_second_niveau   Alloue l'espace mémoire pour un  */
/*                         élément de type second_niveau_t  */
/*                                                          */
/* En entrée/sortie : tete_liste, Pointeur indirect de      */
/*                    début de l'espace mémoire alloué      */
/*                                                          */
/* En sortie : code, Entier valant 1 si l'allocation s'est  */
/*             bien passée; 0 sinon                         */
/* -------------------------------------------------------- */
int allouer_second_niveau(second_niveau_t ** tete_liste)
{
    int code = 1;
    *tete_liste = (second_niveau_t *)malloc(sizeof(second_niveau_t));
    if (tete_liste == NULL) {
        code = 0;
    } else {
        strcpy((*(*tete_liste)).heure, "vV");
        strcpy((*(*tete_liste)).jour, "v");
        strcpy((*(*tete_liste)).nom, "vide");
        (*(*tete_liste)).suivant = NULL;
    }
    return code;
}

/* -------------------------------------------------------- */
/* ajouter_en_tete_second_niveau    Ajoute en tête un bloc à*/
/*                                  à la liste en paramètre */
/*                                                          */
/* En entrée : nouveau_bloc, Pointeur sur le bloc à ajouter */
/*                           à la liste                     */
/*                                                          */
/* En entrée/sortie : tete_liste, Pointeur indirect de      */ 
/*                                la liste à laquelle       */
/*                                on veut ajouter un bloc   */
/*                                                          */
/* En sortie : code, Entier valant 1 si l'ajout s'est bien  */
/*             passée; 0 sinon                              */
/* -------------------------------------------------------- */
int ajouter_en_tete_second_niveau(second_niveau_t ** tete_liste, second_niveau_t * nouveau_bloc)
{
    int code = 1;
    (*nouveau_bloc).suivant = *tete_liste;
    *tete_liste = nouveau_bloc;
    return code;
}

/* -------------------------------------------------------- */
/* afficher_second_niveau    Affiche les informations de    */
/*                           l'action                       */
/*                                                          */
/* En entrée : tete_liste, Pointeur d'une liste d'action    */
/*                                                          */
/* En sortie : Rien mais écrit dans la sortie standard      */
/* -------------------------------------------------------- */
void afficher_second_niveau(second_niveau_t * tete_liste)
{
    second_niveau_t * courant = tete_liste;
    while (courant != NULL) {
        printf(" -> Jour ");
        afficher_chaine((*courant).jour, TAILLE_JOUR);
        printf(" à ");
        afficher_chaine((*courant).heure, TAILLE_HEURE);
        printf("h faire : ");
        afficher_chaine((*courant).nom, TAILLE_NOM_ACTION);
        //if (strlen((*courant).nom) == TAILLE_NOM_ACTION && strcmp(&(*courant).nom[TAILLE_NOM_ACTION-1], "\n")) {
        // Passage à l'action suivante dans la liste des actions
        courant = (*courant).suivant;
    }
}

/* -------------------------------------------------------- */
/* rechercher_motif_second_niveau    Affiche la liste       */
/*                                   des jours avec         */
/*                                   une action contenant   */
/*                                   un motif donné         */
/*                                                          */
/* En entrée : motif, Chaine de caractères à chercher       */
/*             liste, Pointeur d'une liste d'actions        */
/*                                                          */
/* En entrée/sortie : liste_jours, Pointeur d'une liste     */
/*                    de jours                              */
/* -------------------------------------------------------- */
void rechercher_motif_second_niveau(char liste_jours[], char motif[], second_niveau_t * liste) 
{
    int         i, j;
    int         deb = 0;

    while (liste != NULL) {
        i = 0;
        j = 0;

        //recherche du premier caractère du motif
        while (j<TAILLE_NOM_ACTION && (*liste).nom[j] != motif[0]) {
            j++;
        }

        if ((*liste).nom[j] == motif[0]) {
            //recherche du motif
            while (j<TAILLE_NOM_ACTION && motif[i] != '\0' && (*liste).nom[j] == motif[i]) {
                i++;
                j++;
            }

            //si le motif et le nom de l'action est le même, on ajoute le jour à la liste
            if (motif[i] == '\0') {
                liste_jours[deb] = (*liste).jour[0];
                deb++;
            }
        }
        liste = (*liste).suivant;
    }
    liste_jours[deb] = '\0';
}

/* -------------------------------------------------------- */
/* remplir_informations_second_niveau   Remplie la liste    */
/*                                      avec les éléments   */
/*                                      entrés              */
/*                                                          */
/* Entrée : jour, Chaine de caractères représentant         */
/*                le jour qu'il faut écrire                 */
/*          heure, Chaine de caractères représentant        */
/*                 l'heure qu'il faut écrire                */
/*          nom_action, Chaine de caractères représentant   */
/*                      le nom de l'action qu'il faut       */
/*                      écrire                              */
/*                                                          */
/* Entrée/Sortie : tete_liste, Pointeur sur la structure à  */
/*                             remplir                      */                                                       
/* -------------------------------------------------------- */
void remplir_informations_second_niveau(second_niveau_t * tete_liste, char * jour, char * heure, char * nom_action)
{
    strncpy((*tete_liste).jour, jour, TAILLE_JOUR);
    strncpy((*tete_liste).heure, heure, TAILLE_HEURE);
    strncpy((*tete_liste).nom, nom_action, TAILLE_NOM_ACTION);
    (*tete_liste).suivant = NULL;
}

/* -------------------------------------------------------- */
/* TODO                                                     */
/* -------------------------------------------------------- */
void remplir_nom_action(second_niveau_t * tete_liste, char * ligne_courante)
{
    for (int i = 9; i < 19; i++) {
        (*tete_liste).nom[i-9] = ligne_courante[i];
    }
}

/* -------------------------------------------------------- */
/* ajouter_SN_bon_endroit   Ajoute un bloc à l'emplacement  */
/*                          demandé                         */
/*                                                          */
/* En entrée : nouveau_bloc, Pointeur de tête du bloc à     */
/*                           placer                         */
/*                                                          */ 
/* En entrée/sortie : tete_liste, Pointeur indirect         */
/*                                de l'emplacement demandé  */
/*                                                          */
/* En sortie : code, Entier valant 1 si l'ajout s'est bien  */
/*             passée; 0 sinon                              */
/* -------------------------------------------------------- */
int ajouter_SN_bon_endroit(second_niveau_t ** tete_liste, second_niveau_t * nouveau_bloc)
{
    int code = 1;
    int trouve = 0;
    second_niveau_t ** precedent = tete_liste;
    int resu_coma;
    while (*precedent != NULL && trouve == 0) {
        //comparaison
        resu_coma = comparer_heures_et_jours(*precedent, nouveau_bloc);
        if (resu_coma == 3 || resu_coma == 1) {
            trouve = 1;
        }
        //cas ajout en tete
        if (trouve != 1) {
            precedent = &((*(*precedent)).suivant);
        }
    }
    nouveau_bloc->suivant = *precedent; 
    *precedent = nouveau_bloc;
    return code;
}

/* -------------------------------------------------------- */
/* comparer_heures_et_jours    Compare l'heure et le jour   */
/*                             de deux blocs                */
/*                                                          */
/* En entrée : courant, Pointeur de tête d'un bloc à        */
/*                      comparer                            */
/*             nouveau_bloc, Pointeur de tête de l'autre    */
/*                           bloc à comparer                */
/*                                                          */
/* En sortie : resultat, Entier valant 1 si le jour et      */
/*                       l'heure sont identiques;           */
/*                       2 si le jour est identique mais    */
/*                       l'heure du courant est inférieur à */
/*                       l'autre ou si le jour du courant   */
/*                       est inférieur à l'autre; 3 sinon   */
/* -------------------------------------------------------- */
int comparer_heures_et_jours(second_niveau_t * courant, second_niveau_t * nouveau_bloc)
{
    // résultat des comparaisons
    char * courant_jour = retourner_debut_chaine((*courant).jour, TAILLE_JOUR);
    char * courant_heure = retourner_debut_chaine((*courant).heure, TAILLE_HEURE);
    char * nouveau_jour = retourner_debut_chaine((*nouveau_bloc).jour, TAILLE_JOUR);
    char * nouveau_heure = retourner_debut_chaine((*nouveau_bloc).heure, TAILLE_HEURE);
    int comparaison_jours = strncmp(nouveau_jour, courant_jour, TAILLE_JOUR);
    int comparaison_heures = strncmp(nouveau_heure, courant_heure, TAILLE_HEURE);
    int resultat = 0;
    //si même jours
    if (comparaison_jours == 0) {
        //si même heure
        if (comparaison_heures == 0) {
            //même date
            resultat = 1;
        } else if (comparaison_heures > 0) {
            //date du courant < date du nouveau bloc
            resultat = 2;
        } else {
            //date du courant > date du nouveau bloc
            resultat = 3;
        }
    } else {
        if (comparaison_jours > 0) {
            //date du courant < date du nouveau bloc
            resultat = 2;
        } else {
            //date du courant > date du nouveau bloc
            resultat = 3;
        }
    }
    return resultat;
}

/* -------------------------------------------------------- */
/* supprimer_SN       Supprime une action donnée dans       */
/*                    une liste d'actions                   */
/*                                                          */
/* En entrée : jour, Chaîne de caractères représentant      */
/*                   le jour de l'action à supprimer        */
/*             heure, Chaîne de caractères représentant     */
/*                    l'heure de l'action à supprimer       */
/*                                                          */
/* En entrée/sortie : tete_liste, Pointeur d'une liste      */
/*                                d'actions                 */
/* -------------------------------------------------------- */
second_niveau_t * supprimer_SN(second_niveau_t * tete_liste, char * jour, char * heure)
{
    second_niveau_t ** action_precedente = &tete_liste;
    second_niveau_t  * nouvelle_action = NULL;
    second_niveau_t  * tmp;
    int a;
    a = allouer_second_niveau(&nouvelle_action);
    remplir_informations_second_niveau(nouvelle_action, jour, heure, "vide");
    while (*action_precedente != NULL && comparer_heures_et_jours(*action_precedente, nouvelle_action) != 1) {
        action_precedente = &(*action_precedente)->suivant;
    }
    if (action_precedente) {
        //on change le suivant
        tmp = *action_precedente;
        *action_precedente = (*action_precedente)->suivant;
        free(tmp);
        //on déalloue l'action qu'on cherche
        free(nouvelle_action); 
    }
    return tete_liste;
}