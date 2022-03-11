/* -------------------------------------------------------- */
/* SecondNiveau.h : Déclaration des types, constantes et    */
/*                  prototypes                              */
/* -------------------------------------------------------- */

/* -------------------------------------------------------- */
/* Constantes pour la taille des différents éléments de la  */
/* structure                                                */
/* -------------------------------------------------------- */
#define TAILLE_JOUR 1
#define TAILLE_HEURE 2
#define TAILLE_NOM_ACTION 10

/* -------------------------------------------------------- */
/* second_niveau_t  Structure représentant une action       */
/* -------------------------------------------------------- */
typedef struct second_niveau second_niveau_t;
struct second_niveau
{
    char jour[TAILLE_JOUR];
    char heure[TAILLE_HEURE];
    char nom[TAILLE_NOM_ACTION];
    second_niveau_t *suivant;
};

/* -------------------------------------------------------- */
/* allouer_second_niveau   Alloue l'espace mémoire pour un  */
/*                         élément de type second_niveau_t  */
/* -------------------------------------------------------- */
int allouer_second_niveau(second_niveau_t **);

/* -------------------------------------------------------- */
/* ajouter_en_tete_second_niveau    Ajoute en tête un bloc à*/
/*                                  à la liste en paramètre */
/* -------------------------------------------------------- */
void ajouter_en_tete_second_niveau(second_niveau_t **, second_niveau_t *);

/* -------------------------------------------------------- */
/* afficher_second_niveau    Affiche les informations de    */
/*                           l'action                       */
/* -------------------------------------------------------- */
void afficher_second_niveau(second_niveau_t *);

/* -------------------------------------------------------- */
/* rechercher_motif_second_niveau    Affiche la liste       */
/*                                   des jours avec         */
/*                                   une action contenant   */
/*                                   un motif donné         */
/* -------------------------------------------------------- */
void rechercher_motif_second_niveau(char[], char[], second_niveau_t *);

/* -------------------------------------------------------- */
/* remplir_informations_second_niveau   Remplie la liste    */
/*                                      avec les éléments   */
/*                                      entrés              */
/* -------------------------------------------------------- */
void remplir_informations_second_niveau(second_niveau_t *, char *, char *, char *);

/* -------------------------------------------------------- */
/* ajouter_SN_bon_endroit   Ajoute un bloc à l'emplacement  */
/*                          demandé                         */
/* -------------------------------------------------------- */
int ajouter_SN_bon_endroit(second_niveau_t **, second_niveau_t *);

/* -------------------------------------------------------- */
/* comparer_heures_et_jours    Compare l'heure et le jour   */
/*                             de deux blocs                */
/* -------------------------------------------------------- */
int comparer_heures_et_jours(second_niveau_t *, second_niveau_t *);

/* -------------------------------------------------------- */
/* supprimer_SN       Supprime une action donnée dans       */
/*                    une liste d'actions                   */
/* -------------------------------------------------------- */
second_niveau_t *supprimer_SN(second_niveau_t *, char *, char *);

/* -------------------------------------------------------- */
/* remplir_nom_action   Remplie le champ du nom de l'action */
/* -------------------------------------------------------- */
void remplir_nom_action(second_niveau_t *, char *);