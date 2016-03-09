/*
** ia_reflexion_turn.c for PokerPoked in /home/gascio_m/code/PokerPoked/jeu/IA
**
** Made by Mathieu GASCIOLLI
** Login   <gascio_m@epitech.net>
**
** Started on  Wed Mar  9 01:41:34 2016 Mathieu GASCIOLLI
** Last update Wed Mar  9 01:47:12 2016 Mathieu GASCIOLLI
*/

#include "poker.h"

int	ia_turn()
{
  if (last_action == CHECK)
    {
      situation = CHECK;
      return (1);
    }
}
