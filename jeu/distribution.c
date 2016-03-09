/*
** distribution.c for PokerPoked in /home/gascio_m/code/PokerPoked/jeu
**
** Made by Mathieu GASCIOLLI
** Login   <gascio_m@epitech.net>
**
** Started on  Fri Mar  4 02:02:31 2016 Mathieu GASCIOLLI
** Last update Fri Mar  4 13:48:31 2016 Mathieu GASCIOLLI
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
      i++;
      k++;
    }
}
