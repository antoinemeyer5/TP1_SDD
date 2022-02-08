

typedef struct SecondNiveau{
    char                    jour[1];
    char                    heure[2];
    char                    nom[10];
    struct SecondNiveau   * suivant;
} SecondNiveau_t;