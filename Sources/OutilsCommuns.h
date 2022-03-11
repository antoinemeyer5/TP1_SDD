/* -------------------------------------------------------- */
/* OutilsCommuns.h : Déclaration des types, constantes et   */
/*                   prototypes                             */
/* -------------------------------------------------------- */

#include "PremierNiveau.h"

/* -------------------------------------------------------- */
/* afficher_chaine   Affiche une chaîne de caractères       */
/* -------------------------------------------------------- */
void afficher_chaine(char[], int);

/* -------------------------------------------------------- */
/* afficher_agenda   Affiche l'agenda au complet            */
/* -------------------------------------------------------- */
void afficher_agenda(premier_niveau_t *);

/* -------------------------------------------------------- */
/* remplir_agenda   Remplir un agenda à partir d'un fichier */
/* -------------------------------------------------------- */
int remplir_agenda(char *, premier_niveau_t **);

/* -------------------------------------------------------- */
/* retourner_semaine_existante_dans_agenda  Test si une     */
/*                                          semaine existe  */
/*                                          déjà            */
/* -------------------------------------------------------- */
premier_niveau_t *retourner_semaine_existante_dans_agenda(premier_niveau_t *, char *, char *);

/* -------------------------------------------------------- */
/* supprimer_action Supprime une action donnée dans         */
/*                  l'agenda                                */
/* -------------------------------------------------------- */
void supprimer_action(premier_niveau_t **, char *, char *, char *, char *);

/* -------------------------------------------------------- */
/* sauvegarder_agenda   Sauvegarde un agenda dans un fichier*/
/* -------------------------------------------------------- */
void sauvegarder_agenda(char *, premier_niveau_t *);

/* -------------------------------------------------------- */
/* ecrire_ligne Ecrit une chaine d'une certaine taille dans */
/*              un fichier                                  */
/* -------------------------------------------------------- */
void ecrire_ligne(FILE *, char *, int);