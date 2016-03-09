/*
** interpreteur.c for PokerPoked in /home/gascio_m/code/PokerPoked
**
** Made by Mathieu GASCIOLLI
** Login   <gascio_m@epitech.net>
**
** Started on  Fri Mar  4 01:41:52 2016 Mathieu GASCIOLLI
** Last update Fri Mar  4 01:42:05 2016 Mathieu GASCIOLLI
*/

#include "poker.h"

char    *interpreteur_valeur(carte carte)
{
  char  *valeur;

  valeur = malloc(3 * sizeof(char));
  if (carte.valeur == 1)
    valeur = "A";
  else if (carte.valeur == 11)
    valeur = "J";
  else if (carte.valeur == 12)
    valeur = "Q";
  else if (carte.valeur == 13)
    valeur = "K";
  else if (carte.valeur == 10)
    valeur = "10";
  else
    {
      valeur[0] = carte.valeur + 48;
      valeur[1] = '\0';
    }
  return (valeur);
}

char    *interpreteur_couleur(carte carte)
{
  char  *couleur;

  couleur = malloc(10*sizeof(char));
  if (carte.couleur == PIQUE)
    couleur = "PIQUE";
  else if (carte.couleur == CARREAU)
    couleur = "CARREAU";
  else if (carte.couleur == TREFLE)
    couleur = "TREFLE";
  else if (carte.couleur == COEUR)
    couleur = "COEUR";
  return (couleur);
}
