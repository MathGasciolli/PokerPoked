/*
** export.c for PokerPoked in /home/gascio_m/code/PokerPoked/jeu
**
** Made by Mathieu GASCIOLLI
** Login   <gascio_m@epitech.net>
**
** Started on  Sat Mar 12 01:34:44 2016 Mathieu GASCIOLLI
** Last update Mon Mar 14 13:40:48 2016 Mathieu GASCIOLLI
*/

#include "poker.h"

void	export_config()
{
  char	*title;
  char	*path;
  int	fd;
  char	*buf;

  buf = malloc(10 * sizeof(char));
  title = malloc(150 * sizeof(char));
  path = malloc(300 * sizeof(char));
  path = strcat(path,"config/");
  clear();
  refresh();
  echo();
  curs_set(1);
  mvprintw(3, COLS/2 - 7, "%s", jeu.langue.export_conf);
  mvprintw(5, COLS/2 - 39, "%s", jeu.langue.export_desc);
  mvprintw(LINES/2 - 5, COLS/2 - 5, "%s", jeu.langue.filename);
  mvscanw(LINES/2 - 4, COLS/2 - 5, "%[^\n]", title);
  curs_set(0);
  noecho();
  title = strcat(title, ".poker");
  fd = open(strcat(path,title), O_CREAT|O_RDWR, 0666);
  write(fd, "POKERPOKED - CONFIG FILE\n", 25);
  write(fd, title, strlen(title));
  write(fd, "\n", 1);
  write(fd, "|", 1);
  sprintf(buf, "%d", jeu.stack);
  write(fd, buf, strlen(buf));
  write(fd, "|", 1);
  sprintf(buf, "%d", jeu.blind);
  write(fd, buf, strlen(buf));
  write(fd, "|", 1);
  write(fd, jeu.ianame, strlen(jeu.ianame));
  write(fd, "|", 1);
  write(fd, jeu.playername, strlen(jeu.playername));
  write(fd, "|", 1);
  sprintf(buf, "%c", jeu.button_forces);
  write(fd, buf, 1);
  write(fd, "|", 1);
  sprintf(buf, "%c", jeu.button_pause);
  write(fd, buf, 1);
  write(fd, "|", 1);
  sprintf(buf, "%c", jeu.button_exit);
  write(fd, buf, 1);
  write(fd, "|", 1);
  sprintf(buf, "%c", jeu.button_restart);
  write(fd, buf, 1);
  write(fd, "|", 1);
  write(fd, jeu.lang, strlen(jeu.lang));
  write(fd, "|", 1);
  free(buf);
  close(fd);
  clear();
  mvprintw(LINES/2, COLS/2 - (10+strlen(title)), "%s", jeu.langue.config_created);
  refresh();
  sleep(2);
  free(path);
  free(title);
}
