/*
** distribution.c for PokerPoked in /home/gascio_m/code/PokerPoked/jeu
**
** Made by Mathieu GASCIOLLI
** Login   <gascio_m@epitech.net>
**
** Started on  Fri Mar  4 02:02:31 2016 Mathieu GASCIOLLI
** Last update Wed Mar  9 17:51:40 2016 Mathieu GASCIOLLI
*/

#include "poker.h"

int	rand_carte()
{
  return (rand()%52);
}

void	distrib_cartes_debut()
{
  int	i;
  int	j;
  int	k;

  i = 0;
  k = 0;
  while (i < 2)
    {
      j = rand_carte();
      while (paquet[j].valeur == 0)
	j = rand_carte();
      joueur[k].valeur = paquet[j].valeur;
      joueur[k].couleur = paquet[j].couleur;
      paquet[j].valeur = 0;
      if (joueur[k].valeur == 1)
	hand1[k].rank = 14;
      else
	hand1[k].rank = joueur[k].valeur;
      hand1[k].suit = joueur[k].couleur;
      i++;
      k++;
    }
  k = 0;
  while (i < 4)
    {
      j = rand_carte();
      while (paquet[j].valeur == 0)
	j = rand_carte();
      IA[k].valeur = paquet[j].valeur;
      IA[k].couleur = paquet[j].couleur;
      paquet[j].valeur = 0;
      if (IA[k].valeur == 1)
	hand2[k].rank = 14;
      else
	hand2[k].rank = IA[k].valeur;
      hand2[k].suit = IA[k].couleur;
      i++;
      k++;
    }
}
