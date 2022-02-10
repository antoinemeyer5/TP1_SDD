

typedef struct SecondNiveau{
    char                    jour[1];
    char                    heure[2];
    char                    nom[10];
    struct SecondNiveau   * suivant;
} SecondNiveau_t;

int AllouerSecondNiveau(SecondNiveau_t **);

int AjouterEnTeteSecondNiveau(SecondNiveau_t **, SecondNiveau_t *);

void AfficherSecondNiveau(SecondNiveau_t *);