
/* représente les actions */
typedef struct SecondNiveau SecondNiveau_t;
struct SecondNiveau{
    char               jour[1];
    char               heure[2];
    char               nom[10];
    SecondNiveau_t   * suivant;
};

int AllouerSecondNiveau(SecondNiveau_t **);

int AjouterEnTeteSecondNiveau(SecondNiveau_t **, SecondNiveau_t *);

void AfficherSecondNiveau(SecondNiveau_t *);