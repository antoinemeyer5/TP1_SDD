#include "../Sources/OutilsCommuns.h"
#include "teZZt.h"
#include <string.h>

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
/*TEST(AJOUTER_EN_TETE_PREMIER_NIVEAU, "")
{
    premier_niveau_t * agenda = NULL;
    premier_niveau_t * nouvel_element;
    remplir_informations_premier_niveau(nouvel_element, "2000", "14");
    allouer_premier_niveau(&agenda);
    ajouter_en_tete_premier_niveau(&agenda, nouvel_element);
    CHECK(1 == code_ajouter_en_tete_premier_niveau);
    afficher_agenda(agenda);
}*/
//int ajouter_en_tete_premier_niveau(premier_niveau_t ** tete_liste, premier_niveau_t * nouvel_element)
//int ajouter_en_tete_second_niveau(second_niveau_t ** tete_liste, second_niveau_t * nouveau_bloc)



/* -------------------------------------------------------- */
/* TESTS COMPARAISONS SEMAINES, JOURS, ETC                  */
/* -------------------------------------------------------- */
TEST(COMPARER_SEMAINES_ET_ANNEES, "")
{
    premier_niveau_t * semaine_1 = NULL, * semaine_2 = NULL;
    int code_comparer_semaines_et_annees = 0;
    allouer_premier_niveau(&semaine_1);
    allouer_premier_niveau(&semaine_2);
    //même semaine et même année
    remplir_informations_premier_niveau(semaine_1, "2010", "05");
    remplir_informations_premier_niveau(semaine_2, "2010", "05");
    code_comparer_semaines_et_annees = comparer_semaines_et_annees(semaine_1, semaine_2);
    CHECK(1 == code_comparer_semaines_et_annees);

    //même semaine et pas même année (date semaine_1 < date semaine_2)
    remplir_informations_premier_niveau(semaine_1, "2010", "05");
    remplir_informations_premier_niveau(semaine_2, "2020", "05");
    code_comparer_semaines_et_annees = comparer_semaines_et_annees(semaine_1, semaine_2);
    CHECK(2 == code_comparer_semaines_et_annees);

    //même semaine et pas même année (date de semaine_1 > date de semaine_2)
    remplir_informations_premier_niveau(semaine_1, "2220", "12");
    remplir_informations_premier_niveau(semaine_2, "2020", "12");
    code_comparer_semaines_et_annees = comparer_semaines_et_annees(semaine_1, semaine_2);
    CHECK(3 == code_comparer_semaines_et_annees);

    //pas même semaine et même année (date de semaine_1 < date de semaine_2)
    remplir_informations_premier_niveau(semaine_1, "2020", "01");
    remplir_informations_premier_niveau(semaine_2, "2020", "15");
    code_comparer_semaines_et_annees = comparer_semaines_et_annees(semaine_1, semaine_2);
    CHECK(2 == code_comparer_semaines_et_annees);

    //pas même semaine et même année (date de semaine_1 > date de semaine_2)
    remplir_informations_premier_niveau(semaine_1, "2020", "21");
    remplir_informations_premier_niveau(semaine_2, "2020", "12");
    code_comparer_semaines_et_annees = comparer_semaines_et_annees(semaine_1, semaine_2);
    CHECK(3 == code_comparer_semaines_et_annees);

    //pas même semaine et pas même année (date de semaine_1 < date de semaine_2)
    remplir_informations_premier_niveau(semaine_1, "2010", "23");
    remplir_informations_premier_niveau(semaine_2, "2011", "05");
    code_comparer_semaines_et_annees = comparer_semaines_et_annees(semaine_1, semaine_2);
    CHECK(2 == code_comparer_semaines_et_annees);

    //pas même semaine et pas même année (date de semaine_1 > date de semaine_2)
    remplir_informations_premier_niveau(semaine_1, "2050", "23");
    remplir_informations_premier_niveau(semaine_2, "2011", "05");
    code_comparer_semaines_et_annees = comparer_semaines_et_annees(semaine_1, semaine_2);
    CHECK(3 == code_comparer_semaines_et_annees);
}
TEST(COMPARER_HEURES_ET_JOURS, "")
{
    second_niveau_t * action_1 = NULL, * action_2 = NULL;
    int code_comparer_heures_et_jours = 0;
    allouer_second_niveau(&action_1);
    allouer_second_niveau(&action_2);
    //même heure et même jour
    remplir_informations_second_niveau(action_1, "2", "05", "Exposé");
    remplir_informations_second_niveau(action_2, "2", "05", "Travail");
    code_comparer_heures_et_jours = comparer_heures_et_jours(action_1, action_2);
    CHECK(1 == code_comparer_heures_et_jours);

    //pas même heure et même jour (heure action_1 < heure action_2)
    remplir_informations_second_niveau(action_1, "2", "05", "Exposé");
    remplir_informations_second_niveau(action_2, "2", "06", "Travail");
    code_comparer_heures_et_jours = comparer_heures_et_jours(action_1, action_2);
    CHECK(2 == code_comparer_heures_et_jours);

    //pas même heure et même jour (heure action_1 > heure action_2)
    remplir_informations_second_niveau(action_1, "2", "15", "Exposé");
    remplir_informations_second_niveau(action_2, "2", "05", "Travail");
    code_comparer_heures_et_jours = comparer_heures_et_jours(action_1, action_2);
    CHECK(3 == code_comparer_heures_et_jours);

    //même heure et pas même jour (jour action_1 < jour action_2)
    remplir_informations_second_niveau(action_1, "2", "05", "Exposé");
    remplir_informations_second_niveau(action_2, "6", "05", "Travail");
    code_comparer_heures_et_jours = comparer_heures_et_jours(action_1, action_2);
    CHECK(2 == code_comparer_heures_et_jours);

    //même heure et pas même jour (jour action_1 > jour action_2)
    remplir_informations_second_niveau(action_1, "3", "05", "Exposé");
    remplir_informations_second_niveau(action_2, "1", "05", "Travail");
    code_comparer_heures_et_jours = comparer_heures_et_jours(action_1, action_2);
    CHECK(3 == code_comparer_heures_et_jours);

    //même heure et pas même jour (date action_1 < date action_2)
    remplir_informations_second_niveau(action_1, "2", "15", "Exposé");
    remplir_informations_second_niveau(action_2, "6", "05", "Travail");
    code_comparer_heures_et_jours = comparer_heures_et_jours(action_1, action_2);
    CHECK(2 == code_comparer_heures_et_jours);

    //pas même heure et pas même jour (date action_1 > date action_2)
    remplir_informations_second_niveau(action_1, "3", "25", "Exposé");
    remplir_informations_second_niveau(action_2, "1", "19", "Travail");
    code_comparer_heures_et_jours = comparer_heures_et_jours(action_1, action_2);
    CHECK(3 == code_comparer_heures_et_jours);
}

/* -------------------------------------------------------- */
/* TESTS GESTIONS DES CHAINES                               */
/* -------------------------------------------------------- */
TEST(RETOURNER_DEBUT_CHAINE, "")
{
    char * resultat = NULL;
    char * mot = "Cequidoitêtrecopiédanslanouvellechaînedecaractères";
    int taille_mot;
    int comp;
    //copie de la chaîne entière
    taille_mot = strlen(mot);
    resultat = retourner_debut_chaine(mot, taille_mot);
    comp = strcmp(resultat, mot);
    CHECK(0 == comp);

    //copie de quelques caractères
    taille_mot = 6;
    resultat = retourner_debut_chaine(mot, taille_mot);
    comp = strcmp(resultat, "Cequid");
    CHECK(0 == comp);


}
TEST(RETOURNER_MILIEU_CHAINE, "")
{
    char * resultat = NULL;
    char * mot = "Cequidoitêtrecopiédanslanouvellechaînedecaractères";
    int debut, fin, comp;
    //copie de la chaîne entière
    debut = 0;
    fin = strlen(mot);
    resultat = retourner_milieu_chaine(mot, debut, fin);
    comp = strcmp(resultat, mot);
    CHECK(0 == comp);

    //copie au milieu de la chaîne
    debut = 6;
    fin = 21;
    resultat = retourner_milieu_chaine(mot, debut, fin);
    comp = strcmp(resultat, "oitêtrecopiéd");
    CHECK(0 == comp);

    //copie en début de chaîne
    debut = 0;
    fin = 6;
    resultat = retourner_milieu_chaine(mot, debut, fin);
    comp = strcmp(resultat, "Cequid");
    CHECK(0 == comp);

    //copie en fin de chaîne
    debut = 6;
    fin = strlen(mot);
    resultat = retourner_milieu_chaine(mot, debut, fin);
    comp = strcmp(resultat, "oitêtrecopiédanslanouvellechaînedecaractères");
    CHECK(0 == comp);
}
//void afficher_chaine(char mot[], int taille)
//void afficher_second_niveau(second_niveau_t * tete_liste)



/* -------------------------------------------------------- */
/* TESTS EXISTENCE ELEMENTS PREMIER ET SECOND NIVEAU       */
/* -------------------------------------------------------- */
TEST(EXISTER_DANS_PREMIER_NIVEAU)
{
    premier_niveau_t * bloc = NULL;
    int code_existence;
    allouer_premier_niveau(&bloc);
    remplir_informations_premier_niveau (bloc, "2010", "05");
    //semaine absente
    code_existence = exister_dans_premier_niveau(bloc, "2010", "25");
    CHECK(0 == code_existence);

    //année absente
    code_existence = exister_dans_premier_niveau(bloc, "2019", "05");
    CHECK(0 == code_existence);

    //semaine et année existent
    code_existence = exister_dans_premier_niveau(bloc, "2010", "05");
    CHECK(1 == code_existence);
}
TEST(RETOURNER_SEMAINE_EXISTANTE_DANS_AGENDA)
{
    premier_niveau_t * agenda = NULL;
    premier_niveau_t * semaine = NULL;
    int code_remplir_agenda;
    allouer_premier_niveau(&agenda);
    code_remplir_agenda = remplir_agenda("fi.txt", &agenda);
    semaine = retourner_semaine_existante_dans_agenda(agenda, "1978", "02");
    CHECK((*agenda).suivant = semaine);

}
//int exister_dans_premier_niveau(premier_niveau_t * bloc, char * annee, char * semaine)
//premier_niveau_t * retourner_semaine_existante_dans_agenda(premier_niveau_t * tete_agenda, char * annee, char * semaine)



/* -------------------------------------------------------- */
/* TEST REMPLIR LISTE A PARTIR DE FICHIER OU STRUCT         */
/* -------------------------------------------------------- */
TEST(REMPLIR_AGENDA)
{
    premier_niveau_t * agenda = NULL;
    int code_remplir_agenda;
    allouer_premier_niveau(&agenda);
    code_remplir_agenda = remplir_agenda("fi.txt", &agenda);
    CHECK(1 == code_remplir_agenda);
}
TEST(REMPLIR_INFORMATIONS_PREMIER_NIVEAU)
{
    premier_niveau_t * liste = NULL;
    char * annee;
    int comp_annee, comp_semaine;
    allouer_premier_niveau(&liste);
    remplir_informations_premier_niveau(liste, "2010", "05");
    annee = retourner_milieu_chaine((*liste).annee,0 , TAILLE_ANNEE);
    annee[TAILLE_ANNEE] = '\0';
    comp_annee = strcmp(annee, "2010");
    comp_semaine = strcmp((*liste).semaine, "05");
    CHECK(0 == comp_annee);
    CHECK(0 == comp_semaine);
}
TEST(AJOUTER_PN_BON_ENDROIT)
{
    premier_niveau_t * agenda = NULL;
    premier_niveau_t * semaine_1 = NULL;
    int code_ajout_PN_bon_endroit, code_remplir_agenda;
    allouer_premier_niveau(&agenda);
    allouer_premier_niveau(&semaine_1);
    remplir_informations_premier_niveau(semaine_1, "1975", "25");
    code_remplir_agenda = remplir_agenda("fi.txt", &agenda);
    code_ajout_PN_bon_endroit = ajouter_PN_bon_endroit(&agenda, semaine_1);
    CHECK(semaine_1 = (*agenda).suivant);

}
TEST(REMPLIR_INFORMATIONS_SECOND_NIVEAU)
{
    second_niveau_t * liste = NULL;
    char * heure;
    int comp_heure, comp_nom;
    allouer_second_niveau(&liste);
    remplir_informations_second_niveau(liste, "2", "05", "Partir");
    heure = retourner_milieu_chaine((*liste).heure,0 , TAILLE_HEURE);
    heure[TAILLE_HEURE] = '\0';
    comp_heure = strcmp(heure, "05");
    comp_nom = strcmp((*liste).nom, "Partir");
    CHECK('2' == (*liste).jour[0]);
    CHECK(0 == comp_heure);
    CHECK(0 == comp_nom);
}
TEST(AJOUTER_SN_BON_ENDROIT)
{
    second_niveau_t * liste = NULL;
    second_niveau_t * action_1 = NULL;
    second_niveau_t * action_2 = NULL;
    second_niveau_t * action_3 = NULL;
    int code_ajout_SN_bon_endroit, code_ajout;
    allouer_second_niveau(&liste);
    allouer_second_niveau(&action_1);
    allouer_second_niveau(&action_2);
    allouer_second_niveau(&action_3);
    remplir_informations_second_niveau(action_1, "3", "22", "Poubelles");
    remplir_informations_second_niveau(action_2, "5", "16", "Vacances");
    remplir_informations_second_niveau(action_3, "3", "23", "RDV B103");
    code_ajout = ajouter_en_tete_second_niveau(&liste, action_2);
    code_ajout = ajouter_en_tete_second_niveau(&liste, action_1);
    code_ajout_SN_bon_endroit = ajouter_SN_bon_endroit(&liste, action_3);
    CHECK(action_3 = (*liste).suivant);

}
//OutilsCommuns => void afficher_agenda(premier_niveau_t * tete_agenda)

/* -------------------------------------------------------- */
/* TESTS SUPPRESSION ELEMENTS PREMIER ET SECOND NIVEAU      */
/* -------------------------------------------------------- */
TEST(SUPPRIMER_SN)
{
    second_niveau_t * liste = NULL;
    second_niveau_t * action_1 = NULL;
    second_niveau_t * action_2 = NULL;
    second_niveau_t * resultat = NULL;
    int code_ajout;
    allouer_second_niveau(&liste);
    allouer_second_niveau(&action_1);
    allouer_second_niveau(&action_2);
    remplir_informations_second_niveau(action_1, "3", "22", "Poubelles");
    remplir_informations_second_niveau(action_2, "5", "16", "Vacances");
    code_ajout = ajouter_en_tete_second_niveau(&liste, action_2);
    code_ajout = ajouter_en_tete_second_niveau(&liste, action_1);
    resultat = supprimer_SN(liste, "3", "22");
    CHECK(action_2 == (*liste).suivant);
}
TEST(SUPPRIMER_ACTION)
{
    premier_niveau_t * agenda = NULL;
    premier_niveau_t * semaine = NULL;
    int code_remplir_agenda, comp_annee, comp_semaine, comp_heure;
    char * annee, * heure;
    allouer_premier_niveau(&agenda);
    code_remplir_agenda = remplir_agenda("fi.txt", &agenda);
    supprimer_action(&agenda, "1973","02", "7", "12");
    annee = retourner_milieu_chaine((*(*agenda).suivant).annee,0 , TAILLE_ANNEE);
    annee[TAILLE_ANNEE] = '\0';
    comp_annee = strcmp(annee, "2010");
    comp_semaine = strcmp((*(*agenda).suivant).semaine, "05");
    CHECK(0 != comp_annee);
    CHECK(0 != comp_semaine);
    
    heure = retourner_milieu_chaine((*(*(*agenda).suivant).actions).heure,0 , TAILLE_HEURE);
    heure[TAILLE_HEURE] = '\0';
    comp_heure = strcmp(heure, "12");
    CHECK('7' == (*(*(*agenda).suivant).actions).jour[0]);
    CHECK(0 == comp_heure);

}

/* -------------------------------------------------------- */
/* TESTS RECHERCHE ELEMENTS PREMIER ET SECOND NIVEAU        */
/* -------------------------------------------------------- */
TEST(RECHERCHER_MOTIF_SECOND_NIVEAU)
{
    second_niveau_t * liste = NULL;
    second_niveau_t * action_1 = NULL;
    second_niveau_t * action_2 = NULL;
    second_niveau_t * resultat = NULL;
    int code_ajout, comp;
    char * liste_jours;
    char * reponse = "5";
    allouer_second_niveau(&liste);
    allouer_second_niveau(&action_1);
    allouer_second_niveau(&action_2);
    remplir_informations_second_niveau(action_1, "3", "22", "Poubelles");
    remplir_informations_second_niveau(action_2, "5", "16", "Vacances");
    code_ajout = ajouter_en_tete_second_niveau(&liste, action_2);
    code_ajout = ajouter_en_tete_second_niveau(&liste, action_1);
    rechercher_motif_second_niveau(liste_jours, "Vac", liste);
    comp = strcmp(liste_jours, reponse);
    printf("%s", liste_jours);
    CHECK(0 == comp);
}
/*TEST(RECHERCHER_MOTIF_PREMIER_NIVEAU)
{
    premier_niveau_t * agenda = NULL;
    int code_remplir_agenda, comp;
    char liste_dates[100];
    char * reponse = "2022151 2022151 2022151 2022151 2022151 2022161 ";
    allouer_premier_niveau(&agenda);
    code_remplir_agenda = remplir_agenda("fi.txt", &agenda);
    rechercher_motif_premier_niveau(liste_dates, "SDD", agenda);
    comp = strcmp(liste_dates, reponse);
    CHECK(0 == comp);

}*/

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