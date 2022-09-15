#include <stdio.h>
#include <stdlib.h>
#include "MYSQL/mysql.h"
#include "header/accueil.h"

int main() {
    int choix = 0;
    MYSQL mysql;
    mysql_init(&mysql);
    mysql_options(&mysql, MYSQL_READ_DEFAULT_GROUP, "option");
    
    if (mysql_real_connect(&mysql, "localhost", "root", "", "LIBRARY_MANAGEMENT", 0, NULL, 0))
    {
        do
        {
            view_general();
            scanf("%d", &choix);

            while(!(choix > -1 && choix < 4))
            {
                printf("REESSAYEZ !! ENTREZ UN NOMBRE ENTRE 0 et 3");
                printf("\n------->  ");
                scanf("%d", &choix);    
            }
            
            switch (choix)
            {
                case 0:
                    system("exit");
                    break;
                case 1:
                    manag_adherent(choix, mysql);
                    break;

                case 2:
                    manag_livre(choix, mysql);
                    break;

                case 3:
                    manag_emprunt(choix, mysql);
                    break;
                case 4:
                    printf("\t\t\t============ *** STATISTIQUES DE LA BIBLIOTHEQUE *** =============\n\n");

            }
        } while (choix != 0);
        
    }
    else
    {
        printf("Une erreur s'est produite lors de la connexion à la base de données");   
    }
    
    
    return 0;
}