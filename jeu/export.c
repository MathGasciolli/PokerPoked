/*
** export.c for PokerPoked in /home/gascio_m/code/PokerPoked/jeu
**
** Made by Mathieu GASCIOLLI
** Login   <gascio_m@epitech.net>
**
** Started on  Sat Mar 12 01:34:44 2016 Mathieu GASCIOLLI
** Last update Sat Mar 12 02:42:06 2016 Mathieu GASCIOLLI
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
  mvprintw(3, COLS/2 - 7, "EXPORT CONFIG");
  mvprintw(5, COLS/2 - 39, "Export your config to a file in order to load it easily for the next games !");
  mvprintw(6, COLS/2 - 45, "If you want to load a config file, just use './poker [filename.poker]' when u start the game !");
  mvprintw(LINES/2 - 5, COLS/2 - 5, "File name:");
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
  free(buf);
  close(fd);
  clear();
  refresh();
  mvprintw(LINES/2, COLS/2 - (16+strlen(title)), "Config %s successfully created !", title);
  sleep(2);
  free(path);
  free(title);
}
