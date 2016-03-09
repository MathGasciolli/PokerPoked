/*
** couleur_cartes.c for PokerPoked in /home/gascio_m/code/PokerPoked/affichage
**
** Made by Mathieu GASCIOLLI
** Login   <gascio_m@epitech.net>
**
** Started on  Fri Mar  4 14:24:28 2016 Mathieu GASCIOLLI
** Last update Tue Mar  8 16:46:47 2016 Mathieu GASCIOLLI
*/

#include "poker.h"

void	couleurs()
{
  init_pair(1, COLOR_BLUE, COLOR_BLACK);
  init_pair(2, COLOR_MAGENTA, COLOR_BLACK);
  init_pair(3, COLOR_GREEN, COLOR_BLACK);
  init_pair(4, COLOR_RED, COLOR_BLACK);
  init_pair(5, COLOR_YELLOW, COLOR_BLACK);
}

void	color_carte(int carte)
{
  if (carte == PIQUE)
    attron(COLOR_PAIR(PIQUE));
  else if (carte == CARREAU)
    attron(COLOR_PAIR(CARREAU));
  else if (carte == TREFLE)
    attron(COLOR_PAIR(TREFLE));
  else if (carte == COEUR)
    attron(COLOR_PAIR(COEUR));
}

void	decolor_carte(int carte)
{
  if (carte == PIQUE)
    attroff(COLOR_PAIR(PIQUE));
  else if (carte == CARREAU)
    attroff(COLOR_PAIR(CARREAU));
  else if (carte == TREFLE)
    attroff(COLOR_PAIR(TREFLE));
  else if (carte == COEUR)
    attroff(COLOR_PAIR(COEUR));
}
