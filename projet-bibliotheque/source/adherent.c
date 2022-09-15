#include <stdio.h>
#include <mysql/mysql.h>
#include "../header/adherent.h"


  
//MEMBERS MANAGEMENT 

void GetID_adherent(int *ID_ADHERENT)
{
    printf("\n VEUILLEZ ENTRER l'IDENTIFIANT DE L'ADHERENT ---->  ");
    scanf("%d", ID_ADHERENT);         
}

// GeTinfos

void Getinfo_adherent(char NOM[100], char PRENOMS[255], char ANNEE_DE_NAISSANCE[10], char ADRESSE[50])
{
    printf("\n VEUILLEZ ENTRER LE NOM DE L'ADHERENT ---->  ");
    scanf("%s", NOM);         

    printf("\n VEUILLEZ ENTRER LE(S) PRENOM(S) DE L'ADHERENT  ---->  ");
    scanf("%s", PRENOMS);

    printf("\n ENTRER LA DATE DE NAISSANCE DE L'ADHERENT Ex : Annee/Mois/jour ---->  "); // FORMAT ANNEE/MOIS/JOUR
    scanf("%s", ANNEE_DE_NAISSANCE);

    printf("\n VEUILLEZ ENTRER L'ADRESSE DE L'ADHERENT (Exemple : cocody deux-plateaux) ---->  ");
    scanf("%s", ADRESSE);
    
}


void ADD_adherent(MYSQL mysql, char NOM[100], char PRENOMS[255], char ANNEE_DE_NAISSANCE[10], char ADRESSE[50])
{
    char requete[300] = "";
    sprintf(requete, "INSERT INTO ADHERENTS (NOM, PRENOMS, ANNEE_DE_NAISSANCE, ADRESSE) VALUES ('%s', '%s', '%s', '%s')", NOM, PRENOMS, ANNEE_DE_NAISSANCE, ADRESSE);

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

// SHOWED BORROWDS

void show_adherent(MYSQL_RES *resultat)
{
    MYSQL_ROW row;
    unsigned int i = 0, j = 0;
    unsigned int num_champs = 0; 
    num_champs = mysql_num_fields(resultat);
    while ((row = mysql_fetch_row(resultat)))
    {
        printf("IDENTIFIANT        ------->  %s\n", row[0]);
        printf("NOM       ------->  %s\n", row[1]);
        printf("PRENOMS    ------->  %s\n", row[2]);
        printf("NEE LE    ------->  %s\n", row[3]);
        printf("ADRESSE   ------->  %s\n\n", row[5]);
    }
  
}

void show_all_adherents(MYSQL mysql)
{   
    MYSQL_RES *resultat = NULL;
    mysql_query(&mysql, "SELECT * FROM ADHERENTS");
    resultat = mysql_store_result(&mysql); 
    show_adherent(resultat);
}

void delete_adherent(MYSQL mysql, int ID_ADHERENT)
{
    char requete[120] = "";

    sprintf(requete, "DELETE FROM ADHERENTS WHERE numero=%d", ID_ADHERENT);
    mysql_query(&mysql, requete);
}

void search_adherent(MYSQL mysql, int ID_ADHERENT)
{   
    MYSQL_RES *resultat = NULL;    
    char requete[120] = "";

    sprintf(requete, "SELECT * FROM ADHERENTS WHERE numero=%d", ID_ADHERENT);
    mysql_query(&mysql, requete);

    resultat = mysql_store_result(&mysql);
    show_adherent(resultat);
}

void modify_adherent(MYSQL mysql, int ID_ADHERENT, char NOM[100], char PRENOMS[255], char ANNEE_DE_NAISSANCE[10], char ADRESSE[50])
{
    char requete[500] = "";

    sprintf(requete, "UPDATE ADHERENTS SET NOM='%s', PRENOMS='%s', ANNEE_DE_NAISSANCE='%s', ADRESSE='%s' WHERE numero=%d", NOM, PRENOMS, ANNEE_DE_NAISSANCE, ADRESSE, ID_ADHERENT);
    mysql_query(&mysql, requete);

}