#include <stdio.h>
#include <mysql/mysql.h>
#include "../header/emprunter.h"
#include "../header/livre.h"
#include "../header/adherent.h"

  
//  Gestion de emprunts

void borrowinginfos(int *ID_ADHERENT, int *NUMERO_LIVRE, char DATE_SORTIE[12], char DATE_RETOUR[12])
{
    printf("\n ENTRER L'IDENTIFIANT DE L'ADHERENT ---->  ");
    scanf("%d", ID_ADHERENT);      

    printf("\n ENTRER LE NUMERO DU LIVRE  ---->  ");
    scanf("%d", NUMERO_LIVRE);         
    
    printf("\n MENTIONNER LA DATE DE SORTIE (Ex : 2012-12-12)---->  ");
    scanf("%s", DATE_SORTIE);

    printf("\n MENTIONNER LA DATE DE RETOUR-(Ex : 2012-12-12) --->  ");
    scanf("%s", DATE_RETOUR);
}

void ADD_emprunt(MYSQL mysql, int ID_ADHERENT, int NUMERO_LIVRE, char DATE_SORTIE[10], char DATE_RETOUR[10])
{
    char requete[300] = "";

    sprintf(requete, "INSERT INTO emprunt (ID_ADHERENT, NUMERO_LIVRE, DATE_SORTIE, DATE_RETOUR) VALUES ('%d', '%d', '%s', '%s')", ID_ADHERENT, NUMERO_LIVRE, DATE_SORTIE, DATE_RETOUR);

    if(mysql_query(&mysql, requete))
    {
        printf("%s",mysql_error(&mysql));
    }
}

void show_emprunt(MYSQL_RES *resultat)
{
    MYSQL_ROW row;
    unsigned int i = 0, j = 0;
    unsigned int num_champs = 0; 
    num_champs = mysql_num_fields(resultat);
    while ((row = mysql_fetch_row(resultat)))
    {
        printf("\n ID ADHERENT  ------->  %s\n", row[0]);
        printf("ID LIVRE     ------->  %s\n", row[1]);
        printf("SORTIE LE    ------->  %s\n", row[2]);
        printf("RENDU LE     ------->  %s\n", row[3]);
    }
  
}

void show_all_emprunts(MYSQL mysql)
{   
    MYSQL_RES *resultat = NULL;
    mysql_query(&mysql, "SELECT * FROM EMPRUNTER");
    resultat = mysql_store_result(&mysql); 
    show_emprunt(resultat);
}

void delete_emprunt(MYSQL mysql, int ID_ADHERENT, int NUMERO_LIVRE)
{
    char requete[120] = "";

    sprintf(requete, "DELETE FROM EMPRUNTER WHERE ID_ADHERENT=%d AND NUMERO_LIVRE=%d", ID_ADHERENT, NUMERO_LIVRE);
    mysql_query(&mysql, requete);
}

void search_emprunts(MYSQL mysql, int ID_ADHERENT) 
{   
    MYSQL_RES *resultat = NULL;    
    char requete[200] = "";

    sprintf(requete, "SELECT * FROM EMPRUNTER WHERE ID_ADHERENT=%d", ID_ADHERENT);
    mysql_query(&mysql, requete);

    resultat = mysql_store_result(&mysql);
    show_emprunt(resultat);
}

void search_emprunt(MYSQL mysql, int ID_ADHERENT, int NUMERO_LIVRE)
{   
    MYSQL_RES *resultat = NULL;    
    char requete[200] = "";

    sprintf(requete, "SELECT * FROM EMPRUNTER WHERE ID_ADHERENT=%d AND NUMERON_LIVRE=%d", ID_ADHERENT, NUMERO_LIVRE);
    mysql_query(&mysql, requete);

    resultat = mysql_store_result(&mysql);
    show_emprunt(resultat);
}

void modify_emprunt(MYSQL mysql, int ID_ADHERENT, int NUMERO_LIVRE, char DATE_SORTIE[10], char DATE_RETOUR[10])
{
    char requete[500] = "";

    sprintf(requete, "UPDATE EMPRUNTER SET DATE_SORTIE='%s', DATE_RETOUR='%s'WHERE ID_ADHERENT='%d' AND NUMERO_LIVRE='%d', ", DATE_SORTIE, DATE_RETOUR, ID_ADHERENT, NUMERO_LIVRE);
    mysql_query(&mysql, requete);

}