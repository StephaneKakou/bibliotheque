#include <stdio.h>
#include <mysql/mysql.h>
#include "../header/livre.h"

  
//  Gestion de livres
MYSQL mysql;
void Getnum_livre(int *NUMERO_LIVRE)
{
    printf("\n ENTRER L'IDENTIFIANT DU LIVRE ---->  ");
    scanf("%d",  NUMERO_LIVRE);         
}

void Getinfos_livre(char TITRE[100], char AUTEUR[100], char GENRE_LITTERAIRE[100])
{

    printf("\n ENTRER LE TITRE DU LIVRE ---->  ");
    scanf("%s", TITRE);

    printf("\n ENTRER L'AUTEUR DU LIVRE ---->  ");
    scanf("%s", AUTEUR);
    
    printf("\n ENTRER LE GENRE DU LIVRE (Ex: Adoras)---->  ");
    scanf("%s", GENRE_LITTERAIRE);
    
}

void ADD_livre(char TITRE[100], char AUTEUR[100], char GENRE_LITTERAIRE[100])
{
    char requete[300] = "";

    sprintf(requete, "INSERT INTO LIVRES (TITRE, AUTEUR, GENRE_LITTERAIRE) VALUES ('%s', '%s', '%s')", TITRE, AUTEUR, GENRE_LITTERAIRE);

    if(mysql_query(&mysql, requete))
    {
        printf("%s",mysql_error(&mysql));
    }
    else
    {
        printf("\t\t\t     +---------------------------------------------------+\n");
        printf("\t\t\t     |          INSERTION EFFECTUEE AVEC SUCCES !!       | \n");
        printf("\t\t\t     +---------------------------------------------------+\n");

    }
}

void show_livre(MYSQL_RES *resultat)
{
    MYSQL_ROW row;
    unsigned int i = 0, j = 0;
    unsigned int num_champs = 0; 
    num_champs = mysql_num_fields(resultat);
    while ((row = mysql_fetch_row(resultat)))
    {
        printf("ID         ------->  %s\n", row[0]);
        printf("TITRE      ------->  %s\n", row[1]);
        printf("AUTEUR     ------->  %s\n", row[2]);
        printf("GENRE      ------->  %s\n", row[3]);
        printf("PARU LE    ------->  %s\n\n", row[4]);
    }
  
}

void show_all_livres(MYSQL mysql)
{   
    MYSQL_RES *resultat = NULL;
    mysql_query(&mysql, "SELECT * FROM LIVRES");
    resultat = mysql_store_result(&mysql); 
    show_livre(resultat);
}

void delete_livre(MYSQL mysql, int NUMERO_LIVRE)
{
    char requete[120] = "";

    sprintf(requete, "DELETE FROM LIVRES WHERE numero=%d", NUMERO_LIVRE);
    mysql_query(&mysql, requete);
}

void search_livre(MYSQL mysql, int NUMERO_LIVRE)
{   
    MYSQL_RES *resultat = NULL;    
    char requete[120] = "";

    sprintf(requete, "SELECT * FROM LIVRES WHERE numero=%d", NUMERO_LIVRE);
    mysql_query(&mysql, requete);

    resultat = mysql_store_result(&mysql);
    show_livre(resultat);
}

void modify_livre(int NUMERO_LIVRE, char TITRE[100], char AUTEUR[100], char GENRE_LITTERAIRE[10])
{
    char requete[500] = "";

    sprintf(requete, "UPDATE LIVRES SET TITRE='%s', AUTEUR='%s', GENRE='%s' WHERE numero=%d", TITRE, AUTEUR, GENRE_LITTERAIRE, NUMERO_LIVRE);
    mysql_query(&mysql, requete);

}