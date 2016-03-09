/*
** preflop.c for PokerPoked in /home/gascio_m/code/PokerPoked/jeu/hand_eval
**
** Made by Mathieu GASCIOLLI
** Login   <gascio_m@epitech.net>
**
** Started on  Wed Mar  9 14:51:55 2016 Mathieu GASCIOLLI
** Last update Wed Mar  9 15:17:41 2016 Mathieu GASCIOLLI
*/

#include "poker.h"

// Entre 1 et 13 : High Card.
// Entre 101 et 113 : Pair.

void	aff_hand_preflop(int nb)
{
  char	*type;
  char	*hauteur;

  move(LINES-2, 3);
  if (nb < 100)
    type = "High Card";
  else
    {
      type = "Pair of";
      nb = nb - 100;
    }
  if (nb < 10 && nb > 1)
    {
      hauteur[0] = nb + 48;
      hauteur[1] = '\0';
    }
  else if (nb == 1)
    hauteur = "Ace";
  else if (nb == 10)
    hauteur = "10";
  else if (nb == 11)
    hauteur = "Jack";
  else if (nb == 12)
    hauteur = "Queen";
  else if (nb == 13)
    hauteur = "King";
  printw("%s %s.", type, hauteur);
}

int	preflop_hand(carte *carte, int o)
{
  int	res;

  res = 0;
  if (carte[0].valeur == carte[1].valeur)
    res = res + 100;
  if (carte[0].valeur > carte[1].valeur && carte[1].valeur != 1)
    res = res + carte[0].valeur;
  else
    res = res + carte[1].valeur;
  if (o == 1)
    aff_hand_preflop(res);
  return (res);
}
