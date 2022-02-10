#include "PremierNiveau.h"

#define TAILLE_ANNEE 4
#define TAILLE_SEMAINE 2
#define TAILLE_JOUR 1
#define TAILLE_HEURE 2
#define TAILLE_NOM_ACTION 10

void AfficherChaine(char[], int);

void AfficherAgenda(PremierNiveau_t *);

int RemplirAgenda(char *, PremierNiveau_t **);