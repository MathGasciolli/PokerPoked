/*
** init.c for PokerPoked in /home/gascio_m/code/PokerPoked/jeu/mysql
**
** Made by Mathieu GASCIOLLI
** Login   <gascio_m@epitech.net>
**
** Started on  Mon Mar 14 17:07:44 2016 Mathieu GASCIOLLI
** Last update Mon Mar 14 22:15:09 2016 Mathieu GASCIOLLI
*/

#include "poker.h"

int main(int ac, char **av, char **env)
{
    MYSQL *conn;
    MYSQL_RES *res;
    MYSQL_ROW row;
    char *server = "sql7.freesqldatabase.com";
    char *user = "sql7110715";
    char *password = "kLDR8NWLqR"; /* set me first */
    char *database = "sql7110715";
    conn = mysql_init(NULL);
    /* Connect to database */
    if (!mysql_real_connect(conn, server,
			    user, password, database, 0, NULL, 0)) {
      fprintf(stderr, "%s\n", mysql_error(conn));
      exit(1);
    }
    /* send SQL query */
    if (mysql_query(conn, "show tables")) {
      fprintf(stderr, "%s\n", mysql_error(conn));
      exit(1);
    }
    res = mysql_use_result(conn);
    /* output table name */
    printf("MySQL Tables in mysql database:\n");
    while ((row = mysql_fetch_row(res)) != NULL)
      printf("%s \n", row[0]);
    /* close connection */
    mysql_free_result(res);
    mysql_close(conn);
  return 0;
}
