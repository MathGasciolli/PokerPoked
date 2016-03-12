/*
** ia_reflexion_flop.c for PokerPoked in /home/gascio_m/code/PokerPoked/jeu/IA
**
** Made by Mathieu GASCIOLLI
** Login   <gascio_m@epitech.net>
**
** Started on  Wed Mar  9 01:39:23 2016 Mathieu GASCIOLLI
** Last update Sat Mar 12 18:10:03 2016 Mathieu GASCIOLLI
*/

#include "poker.h"

int	ia_flop(int i)
{
  if (i > 2)
    {
      if (aff_strength(0) == 1 && player.mise > 0)
	return 0;
      else if (aff_strength(0) > 1 && player.mise > 0 && player.mise < ia.argent/2)
	return 2;
      else if (aff_strength(0) > 3 && player.mise > ia.argent/2)
	return 3;
      else if (aff_strength(0) > 1 && player.mise == 0)
	return (rand()%3*jeu.blind + jeu.blind);
      else if (player.mise == 0)
	return 1;
      else
	return 0;
    }
  else if (i == 2)
    {
      if (aff_strength(0) == 1 && player.mise > 0 && player.mise < ia.argent/4)
	return 2;
      else if (aff_strength(0) > 1 && player.mise > 0 && player.mise < ia.argent/2)
	return 2;
      else if (aff_strength(0) > 3 && player.mise > ia.argent/2)
	return 2;
      else if (aff_strength(0) > 1 && player.mise == 0)
	return (rand()%3*jeu.blind + jeu.blind);
      else if (player.mise == 0)
	return 1;
      else
	return 0;
    }
  else if (i < 2)
    {
      if (aff_strength(0) == 1 && player.mise > 0 && player.mise < ia.argent/4)
	return 2;
      else if (aff_strength(0) > 1 && player.mise > 0 && player.mise < ia.argent/2)
	return 2;
      else if (aff_strength(0) > 3 && player.mise > ia.argent/2)
	return 2;
      else if (aff_strength(0) > 1 && player.mise == 0)
	return (1);
      else if (player.mise == 0)
	return 1;
      else
	return 0;
    }
}
