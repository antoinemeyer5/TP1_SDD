#ifndef CODE_SECONDNIVEAU
#define CODE_SECONDNIVEAU

#define TAILLE_JOUR 1
#define TAILLE_HEURE 2
#define TAILLE_NOM_ACTION 10

/* représente les actions */
typedef struct second_niveau second_niveau_t;
struct second_niveau{
    char               jour[TAILLE_JOUR];
    char               heure[TAILLE_HEURE];
    char               nom[TAILLE_NOM_ACTION];
    second_niveau_t   * suivant;
};

int allouer_second_niveau(second_niveau_t **);

int ajouter_en_tete_second_niveau(second_niveau_t **, second_niveau_t *);

void afficher_second_niveau(second_niveau_t *);

#endif