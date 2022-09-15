#include <stdio.h>
#include "../header/adherent.h"
#include "../header/livre.h"
#include "../header/emprunter.h"
#include "../header/accueil.h"

void view_general()
{
    system("clear");
    printf("\n\n**********************************************************************************\n");
    printf("**************************   1- GERER LES ADHERENTS   **************************\n");
    printf("**************************   2- GERER LES LIVRES      **************************\n");
    printf("**************************   3- GERER MES EMPRUNTS    **************************\n");
    printf("**************************   0- QUITTER                 **************************\n");
    printf("**********************************************************************************\n\n");
    printf("Entrez votre choix -------->  ");
    
}

void manag_adherent(int choix, MYSQL mysql)
{
    int  ID_ADHERENT = 0;
    char NOM[100] = "";
    char PRENOMS[255] = "";
    char ADRESSE[10] = "";
    char ANNEE_DE_NAISSANCE[12] = "";

    do
    {
        printf("\n\n**********************************************************************************\n");
        printf("**************************   1- AJOUTER UN ADHERENT     **************************\n");
        printf("**************************   2- RECHERCHER UN ADHERENT  **************************\n");
        printf("**************************   3- MODIFIER UN ADHERENT    **************************\n");
        printf("**************************   4- SUPPRIMER UN ADHERENT   **************************\n");
        printf("**************************   5- AFFICHER LES ADHERENTS  **************************\n");
        printf("**************************   0- RETOUR MENU PRINCIPAL   **************************\n");
        printf("**********************************************************************************\n\n");
        printf("Entrez votre choix -------->  ");
        scanf("%d", &choix);

        switch (choix)
        {
            case 1:
                system("clear");
                Getinfo_adherent(&NOM, &PRENOMS, &ANNEE_DE_NAISSANCE , &ADRESSE);
                ADD_adherent(mysql, NOM, PRENOMS, ANNEE_DE_NAISSANCE, ADRESSE);   
                break;
            
            case 2:
                system("clear");
                GetID_adherent(&ID_ADHERENT);
                search_adherent(mysql, ID_ADHERENT);
                break;
            
            case 3:
                GetID_adherent(&ID_ADHERENT);
                GetID_adherent(&NOM, &PRENOMS, &ANNEE_DE_NAISSANCE, &ADRESSE);
                modify_adherent(mysql, ID_ADHERENT, NOM, PRENOMS, ANNEE_DE_NAISSANCE, ADRESSE);            
                break;
            
            case 4:
                 GetID_adherent(&ID_ADHERENT);
                printf("%d", ID_ADHERENT);
                delete_adherent(mysql, ID_ADHERENT);            
                break;
            
            case 5:
               show_all_adherents(mysql);
                break;
        }
        
    } while (choix<6 && choix>0);
}

void manag_livre(int choix, MYSQL mysql)
{
    int  NUMERO_LIVRE = 0;
    char TITRE[100] = "";
    char AUTEUR[50] = "";
    char GENRE_LITTERAIRE[100] = "";

    do
    {
        printf("\n\n**********************************************************************************\n");
        printf("***************************   1- AJOUTER UN LIVRE      ***************************\n");
        printf("***************************   2- RECHERCHER UN LIVRE   ***************************\n");
        printf("***************************   3- MODIFIER UN LIVRE     ***************************\n");
        printf("***************************   4- SUPPRIMER UN LIVRE    ***************************\n");
        printf("***************************   5- AFFICHER LES LIVRES   ***************************\n");
        printf("***************************   0- ALLER MENU PRINCIPAL  ***************************\n");
        printf("**********************************************************************************\n\n");
        printf("Entrez votre choix -------->  ");
        scanf("%d", &choix);

        switch (choix)
        {
            case 1:
                system("clear");
                Getinfos_livre(&TITRE, &AUTEUR, &GENRE_LITTERAIRE);
                ADD_livre( TITRE, AUTEUR, GENRE_LITTERAIRE);   
                break;
            
            case 2:
                system("clear");
                Getnum_livre(&NUMERO_LIVRE);
                search_livre(mysql, NUMERO_LIVRE);
                break;
            
            case 3:
                Getnum_livre(&NUMERO_LIVRE);
                Getinfos_livre(&TITRE, &AUTEUR, &GENRE_LITTERAIRE);
                modify_livre( NUMERO_LIVRE, TITRE, AUTEUR, GENRE_LITTERAIRE);   
                break;
            
            case 4:
                Getnum_livre(&NUMERO_LIVRE);
                delete_livre(mysql, NUMERO_LIVRE);            
                break;
            
            case 5:
                show_all_livres(mysql);
                break;
        }
        
    } while (choix<6 && choix>0);
}

void manag_emprunt(int choix, MYSQL mysql)
{
    int  ID_ADHERENT = 0;
    int  NUMERO_LIVRE = 0;
    char DATE_SORTIE[12] = "";
    char DATE_RETOUR[12] = "";

    do
    {
        printf("\n\n**********************************************************************************\n");
        printf("**************************   1- AJOUTER UN EMPRUNT     ***************************\n");
        printf("**************************   2- RECHERCHER UN EMPRUNT  ***************************\n");
        printf("**************************   3- MODIFIER UN EMPRUNT    ***************************\n");
        printf("**************************   4- SUPPRIMER UN EMPRUNT   ***************************\n");
        printf("**************************   5- AFFICHER LES EMPRUNTS  ***************************\n");
        printf("**************************   0- RETOUR MENU PRINCIPAL  ***************************\n");
        printf("**********************************************************************************\n\n");
        printf("Entrez votre choix -------->  ");
        scanf("%d", &choix);

        switch (choix)
        {
            case 1:
                system("clear");
                borrowinginfos(&ID_ADHERENT, &NUMERO_LIVRE, &DATE_SORTIE, &DATE_RETOUR);
                ADD_emprunt(mysql, ID_ADHERENT, NUMERO_LIVRE, DATE_SORTIE, DATE_RETOUR);   
                break;
            
            case 2:
                system("clear");
                GetID_adherent(&ID_ADHERENT);
                search_emprunts(mysql, ID_ADHERENT);
                break;
            
            case 3:
                borrowinginfos(&ID_ADHERENT, &NUMERO_LIVRE, &DATE_SORTIE);
                modify_emprunt(mysql, ID_ADHERENT, NUMERO_LIVRE, DATE_SORTIE, DATE_RETOUR);      
                break;
            
            case 4:
                GetID_adherent(&ID_ADHERENT);
                Getnum_livre(&NUMERO_LIVRE);
                delete_emprunt(mysql, ID_ADHERENT, NUMERO_LIVRE);            
                break;
            
            case 5:
                show_all_emprunts(mysql);
                break;
        }
        
    } while (choix<6 && choix>0);
}
