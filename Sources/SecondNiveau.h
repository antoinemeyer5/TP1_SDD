/* -------------------------------------------------------- */
/* Constantes pour la taille des différents éléments de la  */
/* structure                                                */
/* -------------------------------------------------------- */
#define TAILLE_JOUR         1
#define TAILLE_HEURE        2
#define TAILLE_NOM_ACTION   10

/* -------------------------------------------------------- */
/* second_niveau_t  Structure représentant une action       */
/* -------------------------------------------------------- */
typedef struct second_niveau second_niveau_t;
struct second_niveau {
    char               jour[TAILLE_JOUR];
    char               heure[TAILLE_HEURE];
    char               nom[TAILLE_NOM_ACTION];
    second_niveau_t  * suivant;
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
int ajouter_en_tete_second_niveau(second_niveau_t **, second_niveau_t *);

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
void rechercher_motif_second_niveau(char [], char [], second_niveau_t *);

//
void remplir_informations_second_niveau(second_niveau_t *, char *, char *, char *);

//
int ajouter_DN_bon_endroit(second_niveau_t **, second_niveau_t *);

int comparer_heures_et_jours(second_niveau_t *, second_niveau_t *);