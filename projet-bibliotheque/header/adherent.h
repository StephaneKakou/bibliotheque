#ifndef _ADHERENT_H
#define _ADHERENT_H
#include <mysql/mysql.h>


//MEMBERS MANAGEMENT 
void Getinfo_adherent();
void GetID_adherent();
void ADD_adherent(MYSQL mysql, char NOM[100], char PRENOMS[255], char ANNEE_DE_NAISSANCE[10], char ADRESSE[50]);
void delete_adherent(MYSQL mysql, int ID_ADEHRENT);
void show_all_adherents(MYSQL mysql);
void search_adherent(MYSQL mysql, int ID_ADHERENT);
void modify_adherent(MYSQL mysql, int ID_ADHERENT, char NOM[100], char PRENOMS[255], char ANNEE_DE_NAISSANCE[10], char ADRESSE[50]);


#endif