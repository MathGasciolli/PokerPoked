/*
** dealer.c for PokerPoked in /home/gascio_m/code/PokerPoked/jeu
**
** Made by Mathieu GASCIOLLI
** Login   <gascio_m@epitech.net>
**
** Started on  Fri Mar  4 23:58:47 2016 Mathieu GASCIOLLI
** Last update Mon Mar 14 13:24:11 2016 Mathieu GASCIOLLI
*/

#include "poker.h"

void	change_dealer()
{
  if (dealer == 1)
    dealer = 0;
  else if (dealer == 0)
    dealer = 1;
}

void	argent_fin(int o)
{
  if (o == 2)
    {
      mvprintw(5, COLS/2 - 9, "%s", jeu.langue.same);
      refresh();
      player.argent = player.argent + pot/2;
      ia.argent = ia.argent + pot/2;
      pot = 0;
    }
  else if (o == 1)
    {
      mvprintw(5, COLS/2 - 9, "%s %s", jeu.playername, jeu.langue.won);
      refresh();
      player.argent = player.argent + pot;
      pot = 0;
    }
  else if (o == 0)
    {
      mvprintw(5, COLS/2 - 9, "%s %s", jeu.ianame, jeu.langue.won);
      refresh();
      ia.argent = ia.argent + pot;
      pot = 0;
    }
}
