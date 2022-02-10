#include "SecondNiveau.h"
#include <stdio.h>

/* représente les semaines */
typedef struct PremierNiveau PremierNiveau_t;
struct PremierNiveau{
    char                annee[4];
    char                semaine[2];
    SecondNiveau_t    * actions;
    PremierNiveau_t   * suivant;
};

int AllouerPremierNiveau(PremierNiveau_t **);

int AjouterEnTetePremierNiveau(PremierNiveau_t **, PremierNiveau_t *);

//void AfficherPremierNiveau(PremierNiveau_t *);