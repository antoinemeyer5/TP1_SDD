#include "../Sources/PremierNiveau.h"
#include "teZZt.h"

BEGIN_TEST_GROUP(tests_code)

/*                      */
TEST(ALLOUER_SECOND_NIVEAU, "")
{
    second_niveau_t * sn = NULL;
    int code;
    code = allouer_second_niveau(&sn);
    CHECK(1 == code);
}

/*                      */
TEST(ALLOUER_Premier_NIVEAU, "")
{
    premier_niveau_t * pn = NULL;
    int code;
    code = allouer_premier_niveau(&pn);
    CHECK(1 == code);
}

END_TEST_GROUP(tests_code)

int main()
{
    RUN_TEST_GROUP(tests_code);  
    return 0;
}



/*
a = ExisterPremierNiveau(Elem1, "1999", "04");
printf("\na = %d\n", a);
a = ExisterPremierNiveau(Elem1, "2999", "04");
printf("\na = %d\n", a);
a = ExisterPremierNiveau(Elem1, "1999", "05");
printf("\na = %d\n", a);
a = ExisterPremierNiveau(Elem1, "1399", "09");
printf("\na = %d\n", a);
*/


/*
a = ExisterPremierNiveauAgenda(TeteListe, "1993", "04");
printf("a = %d\n", a);
a = ExisterPremierNiveauAgenda(TeteListe, "2026", "03");
printf("a = %d\n", a);
a = ExisterPremierNiveauAgenda(TeteListe, "2016", "00");
printf("a = %d\n", a);
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