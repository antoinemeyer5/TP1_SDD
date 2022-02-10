#include "SecondNiveau.h"
#include <stdio.h>

typedef struct PremierNiveau PremierNiveau_t;
struct PremierNiveau{
    char                annee[4];
    char                semaine[2];
    SecondNiveau_t    * actions;
    PremierNiveau_t   * suivant;
};

int AllouerPremierNiveau(PremierNiveau_t **);

int AjouterEnTetePremierNiveau(PremierNiveau_t **, PremierNiveau_t *);

void AfficherPremierNiveau(PremierNiveau_t *);

void fgets2(char *, int, FILE *);

void RemplirPremierNiveau(PremierNiveau_t *, FILE *);