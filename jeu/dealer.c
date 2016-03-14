/*
** dealer.c for PokerPoked in /home/gascio_m/code/PokerPoked/jeu
**
** Made by Mathieu GASCIOLLI
** Login   <gascio_m@epitech.net>
**
** Started on  Fri Mar  4 23:58:47 2016 Mathieu GASCIOLLI
** Last update Mon Mar 14 10:29:50 2016 Mathieu GASCIOLLI
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
      mvprintw(5, COLS/2 - 9, "Same Hands..");
      refresh();
      player.argent = player.argent + pot/2;
      ia.argent = ia.argent + pot/2;
      pot = 0;
    }
  else if (o == 1)
    {
      mvprintw(5, COLS/2 - 9, "You won !");
      refresh();
      player.argent = player.argent + pot;
      pot = 0;
    }
  else if (o == 0)
    {
      mvprintw(5, COLS/2 - 9, "%s won !", ia.name);
      refresh();
      ia.argent = ia.argent + pot;
      pot = 0;
    }
}
