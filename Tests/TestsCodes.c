#include "../Sources/PremierNiveau.h"
#include "teZZt.h"

BEGIN_TEST_GROUP(tests_code)

/* -------------------------------------------------------- */
/* TESTS ALLOCATIONS PREMIER ET SECOND NIVEAU               */
/* -------------------------------------------------------- */
TEST(ALLOUER_SECOND_NIVEAU, "")
{
    second_niveau_t * sn = NULL;
    int code_allouer_second_niveau;
    code_allouer_second_niveau = allouer_second_niveau(&sn);
    CHECK(1 == code_allouer_second_niveau);
}
TEST(ALLOUER_PREMIER_NIVEAU, "")
{
    premier_niveau_t * pn = NULL;
    int code_allouer_premier_niveau;
    code_allouer_premier_niveau = allouer_premier_niveau(&pn);
    CHECK(1 == code_allouer_premier_niveau);
}

/* -------------------------------------------------------- */
/* TESTS AJOUTS PREMIER ET SECOND NIVEAU                    */
/* -------------------------------------------------------- */
//int ajouter_en_tete_premier_niveau(premier_niveau_t ** tete_liste, premier_niveau_t * nouvel_element)
//int ajouter_en_tete_second_niveau(second_niveau_t ** tete_liste, second_niveau_t * nouveau_bloc)



/* -------------------------------------------------------- */
/* TESTS COMPARAISONS SEMAINES, JOURS, ETC                  */
/* -------------------------------------------------------- */
//int comparer_semaines_et_annees(premier_niveau_t * courant, premier_niveau_t * nouveau_bloc)
//int comparer_heures_et_jours(second_niveau_t * courant, second_niveau_t * nouveau_bloc)


/* -------------------------------------------------------- */
/* TESTS GESTIONS DES CHAINES                               */
/* -------------------------------------------------------- */
//char * retourner_debut_chaine(char mot[], int taille_mot)
//char * retourner_milieu_chaine(char mot[], int debut, int fin)
//void afficher_chaine(char mot[], int taille)
//void afficher_second_niveau(second_niveau_t * tete_liste)



/* -------------------------------------------------------- */
/* TESTS EXISTANCES ELEMENTS PREMIER ET SECOND NIVEAU       */
/* -------------------------------------------------------- */
//int exister_dans_premier_niveau(premier_niveau_t * bloc, char * annee, char * semaine)
//premier_niveau_t * retourner_semaine_existante_dans_agenda(premier_niveau_t * tete_agenda, char * annee, char * semaine)



/* -------------------------------------------------------- */
/* TODO TROUVER UNE CATEGORIE       */
/* -------------------------------------------------------- */
//PremierNiveau => void remplir_informations_premier_niveau(premier_niveau_t * tete_liste, char * annee, char * semaine)
//PremierNiveau => int ajouter_PN_bon_endroit(premier_niveau_t ** tete_liste, premier_niveau_t * nouvel_element)  
//OutilsCommuns => void afficher_agenda(premier_niveau_t * tete_agenda)
//OutilsCommuns => int remplir_agenda(char * fichier_lisible, premier_niveau_t ** agenda)
//SecondNiveau => void remplir_informations_second_niveau(second_niveau_t * tete_liste, char * jour, char * heure, char * nom_action)
//SecondNiveau => int ajouter_DN_bon_endroit(second_niveau_t ** tete_liste, second_niveau_t * nouveau_bloc)


END_TEST_GROUP(tests_code)

int main()
{
    RUN_TEST_GROUP(tests_code);  
    return 0;
}


/*
char * s = sms("texte.txt");

   char resultat[] = "333 444 66\n7 777 33 6 444 33 777\n33 99 33 777 222 444 222 33";

   REQUIRE(NULL != s);
   CHECK(0 == strcmp(s, resultat));

   free(s);
*/






/*
printf("%s\n", RetournerDebutChaine("ABCDEFG", TAILLE_ANNEE));
printf("%s\n", RetournerMilieuChaine("ABCDEFG", 0, 3));
printf("%s\n", RetournerMilieuChaine("ABCDEFG", 3, 18));
*/

/*
202841202Dentiste
202841201Dent iste
197805712SportCopai
202215109Rendre SDD
202215105Finir SDD
202215106Finir SDD
202215107Finir SDD
202215108a
202215108Finir SDD
202215108A B C D
*/