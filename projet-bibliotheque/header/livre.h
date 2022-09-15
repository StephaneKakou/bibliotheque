#ifndef _LIVRE_H
#define _LIVRE_H
#include <mysql/mysql.h>

//  Gestion des livres
void Getinfos_livre();
void Getnum_livre();
void ADD_livre(char TITRE[100], char AUTEUR[100], char GENRE_LITTERAIRE[10]);
void delete_livre(MYSQL mysql, int NUMERO_LIVRE);
void show_all_livres(MYSQL mysql);
void search_livre(MYSQL mysql, int NUMERO_LIVRE);
void modify_livre(int NUMERO_LIVRE, char TITRE[100], char AUTEUR[100], char GENRE_LITTERAIRE[10]);


#endif