/*
** init.c for PokerPoked in /home/gascio_m/code/PokerPoked/jeu/mysql
**
** Made by Mathieu GASCIOLLI
** Login   <gascio_m@epitech.net>
**
** Started on  Mon Mar 14 17:07:44 2016 Mathieu GASCIOLLI
** Last update Mon Mar 14 17:56:32 2016 Mathieu GASCIOLLI
*/

#include "poker.h"

int mysql_connection(void)
{
  //Déclaration du pointeur de structure de type MYSQL
  MYSQL mysql;
  //Initialisation de MySQL
  mysql_init(&mysql);
  //Options de connexion
  mysql_options(&mysql,MYSQL_READ_DEFAULT_GROUP,"option");

  //Si la connexion réussie...
  if(mysql_real_connect(&mysql,"freehost-f.fr","c5_CB","bawarebel","bawa_CB",0,NULL,0))
    {
      //Requête qui sélectionne tout dans ma table scores
      mysql_query(&mysql, "SELECT * FROM compte_email");
      //Déclaration des objets
      MYSQL_RES *result = NULL;
      MYSQL_ROW row;
      int i = 1;

      //On met le jeu de résultat dans le pointeur result
      result = mysql_use_result(&mysql);
      //Tant qu'il y a encore un résultat ...
      while ((row = mysql_fetch_row(result)))
	{
	  printf("Resultat %s\n", i);
	  i++;
	}
      //Libération du jeu de résultat
      mysql_free_result(result);

      //Fermeture de MySQL
      mysql_close(&mysql);
    }
  else  //Sinon ...
    {
      printf("Une erreur s'est produite lors de la connexion à la BDD!");
    }

  return 0;
}
