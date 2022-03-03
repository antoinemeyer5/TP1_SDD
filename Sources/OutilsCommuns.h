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
/* exister_dans_premier_niveau_agenda   Test si une semaine */
/*                                      existe déjà ou non  */
/* -------------------------------------------------------- */
int exister_dans_premier_niveau_agenda(premier_niveau_t *, char *, char *);

/* -------------------------------------------------------- */
/* remplir_agenda                                           */
/*                          WORK IN PROGRESS                */
/* -------------------------------------------------------- */
int remplir_agenda(char *, premier_niveau_t **);

/* -------------------------------------------------------- */
/* retourner_semaine_existante_dans_agenda                  */
/*                          WORK IN PROGRESS                */
/* -------------------------------------------------------- */
premier_niveau_t * retourner_semaine_existante_dans_agenda(premier_niveau_t *, char *, char *);

/* -------------------------------------------------------- */
/* ajouter_tri_croissant    Ajoute dans la liste au bon     */
/*                          endroit en gardant le tri       */
/*                          croissant                       */
/* -------------------------------------------------------- */
int ajouter_tri_croissant(premier_niveau_t **, premier_niveau_t *, second_niveau_t **, second_niveau_t *);