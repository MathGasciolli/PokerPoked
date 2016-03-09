/*
** ia_situations.c for PokerPoked in /home/gascio_m/code/PokerPoked/jeu/IA
**
** Made by Mathieu GASCIOLLI
** Login   <gascio_m@epitech.net>
**
** Started on  Tue Mar  8 20:24:41 2016 Mathieu GASCIOLLI
** Last update Tue Mar  8 20:34:37 2016 Mathieu GASCIOLLI
*/

#include "poker.h"

int	highpair()
{
  if ((IA[0].valeur > 9 || IA[0].valeur == 1) && (IA[0].valeur == IA[1].valeur))
    return (1);
  else
    return (0);
}

int	color_suite()
{
  if (IA[0].couleur == IA[1].couleur && IA[0].valeur - IA[1].valeur < 5 && IA[0].valeur - IA[1].valeur > -5)
    return (1);
  else
    return (0);
}

int	figure_et_high()
{
  if ((IA[1].valeur > 10 || IA[1].valeur == 1) && (IA[0].valeur > 7 || IA[0].valeur == 1))
    return (1);
  else if ((IA[0].valeur > 10 || IA[0].valeur == 1) && (IA[1].valeur > 7 || IA[1].valeur == 1))
    return (1);
  else
    return (0);
}

int	suited_connector()
{
  if ((IA[0].couleur == IA[1].couleur) && (IA[0].valeur - IA[1].valeur > -2 || IA[0].valeur - IA[1].valeur < 2) && IA[0].valeur > 9)
    return (1);
  else
    return (0);
}

int	as_figure()
{
  if ((IA[0].valeur == 1 && IA[1].valeur > 10) || (IA[1].valeur == 1 && IA[0].valeur > 10))
    return (1);
  else
    return (0);
}
