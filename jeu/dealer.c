/*
** dealer.c for PokerPoked in /home/gascio_m/code/PokerPoked/jeu
**
** Made by Mathieu GASCIOLLI
** Login   <gascio_m@epitech.net>
**
** Started on  Fri Mar  4 23:58:47 2016 Mathieu GASCIOLLI
** Last update Sat Mar  5 00:00:56 2016 Mathieu GASCIOLLI
*/

#include "poker.h"

void	change_dealer()
{
  if (dealer == 1)
    dealer = 0;
  else if (dealer == 0)
    dealer = 1;
}
