/*
** aff_noms.c for PokerPoked in /home/gascio_m/code/PokerPoked/affichage
**
** Made by Mathieu GASCIOLLI
** Login   <gascio_m@epitech.net>
**
** Started on  Fri Mar  4 17:05:34 2016 Mathieu GASCIOLLI
** Last update Mon Mar 14 14:44:30 2016 Mathieu GASCIOLLI
*/

#include "poker.h"

void	aff_dealer()
{
  if (dealer == 0)
    mvprintw(11, 26, "(D)");
  else if (dealer == 1)
    mvprintw(LINES - 2, COLS/2 - 15, "(D)");
}

void	aff_pot()
{
  mvprintw(LINES/2 - 10, COLS/2 - 4, "%s%d", jeu.langue.pot, pot);
}

void	aff_noms()
{
  attron(COLOR_PAIR(4) | A_UNDERLINE);
  mvprintw(10, 16 - strlen(ia.name)/2, ia.name);
  mvprintw(LINES - 3, (COLS/2 - strlen(player.name)/2), player.name);
  attroff(COLOR_PAIR(4) | A_UNDERLINE);
}

int     nbrlen(int nb)
{
  int	res;

  res = 1;
  if (nb < 0)
    return (0);
  while (nb > 9)
    {
      nb = nb/10;
      res++;
    }
  return (res);
}

void	aff_sous()
{
  mvprintw(12, 16 - nbrlen(ia.argent)/2, " %d ", ia.argent);
  mvprintw(LINES - 1, COLS/2 - nbrlen(player.argent)/2 - 1, " %d ", player.argent);
}
