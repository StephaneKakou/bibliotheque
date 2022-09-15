#ifndef _EMPRUNT_H
#define _EMPRUNT_H
#include <mysql/mysql.h>

//  Gestion de emprunts
void borrowinginfos();
void ADD_emprunt(MYSQL mysql, int ID_ADHERENT, int NUMERO_LIVRE, char DATE_SORTIE[10], char DATE_RETOUR[10]);
void delete_emprunt(MYSQL mysql, int ID_ADHERENT, int  NUMERO_LIVRE);
void show_all_emprunts(MYSQL mysql);
void search_emprunts(MYSQL mysql, int ID_ADHERENT) ;
void search_emprunt(MYSQL mysql, int ID_ADHERENT, int NUMERO_LIVRE);
void modify_emprunt(MYSQL mysql, int ID_ADHERENT, int NUMERO_LIVRE, char DATE_SORTIE[10], char DATE_RETOUR[10]);


#endif