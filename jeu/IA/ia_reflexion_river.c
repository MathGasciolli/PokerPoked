/*
** ia_reflexion_river.c for PokerPoked in /home/gascio_m/code/PokerPoked/jeu/IA
**
** Made by Mathieu GASCIOLLI
** Login   <gascio_m@epitech.net>
**
** Started on  Wed Mar  9 01:42:28 2016 Mathieu GASCIOLLI
** Last update Wed Mar  9 01:47:22 2016 Mathieu GASCIOLLI
*/

#include "poker.h"

int	ia_river()
{
  if (last_action == CHECK)
    {
      situation = CHECK;
      return (1);
    }
}