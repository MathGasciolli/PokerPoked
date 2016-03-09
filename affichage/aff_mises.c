/*
** aff_mises.c for PokerPoked in /home/gascio_m/code/PokerPoked/affichage
**
** Made by Mathieu GASCIOLLI
** Login   <gascio_m@epitech.net>
**
** Started on  Tue Mar  8 16:45:11 2016 Mathieu GASCIOLLI
** Last update Tue Mar  8 21:11:23 2016 Mathieu GASCIOLLI
*/

#include "poker.h"

void	aff_sous_mise()
{
  attron(COLOR_PAIR(5));
  if (ia.mise == 0)
      mvprintw(14, 20, "    ");
  else
    mvprintw(14, 20, "%d", ia.mise);
  if (player.mise == 0)
    mvprintw(LINES-15, COLS/2 - 1, "    ");
  else
    mvprintw(LINES-15, COLS/2 - 1, "%d", player.mise);
  attroff(COLOR_PAIR(5));
}
