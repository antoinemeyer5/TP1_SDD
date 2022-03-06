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
/* remplir_agenda   Fonction qui s'occupe de remplir un     */
/*                  agenda à partir d'un fichier            */
/* -------------------------------------------------------- */
int remplir_agenda(char *, premier_niveau_t **);

/* -------------------------------------------------------- */
/* retourner_semaine_existante_dans_agenda  Test si une     */
/*                                          semaine existe  */
/*                                          déjà            */
premier_niveau_t * retourner_semaine_existante_dans_agenda(premier_niveau_t *, char *, char *);