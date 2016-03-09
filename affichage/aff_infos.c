/*
** aff_infos.c for PokerPoked in /home/gascio_m/code/PokerPoked/affichage
**
** Made by Mathieu GASCIOLLI
** Login   <gascio_m@epitech.net>
**
** Started on  Wed Mar  9 15:08:58 2016 Mathieu GASCIOLLI
** Last update Wed Mar  9 15:13:59 2016 Mathieu GASCIOLLI
*/

#include "poker.h"

void	aff_hand_value()
{
  if (check_board() == 0)
    {
      preflop_hand(joueur, 1);
      preflop_hand(IA, 0);
    }
}
