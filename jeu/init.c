/*
** init.c for PokerPoked in /home/gascio_m/code/PokerPoked/jeu
**
** Made by Mathieu GASCIOLLI
** Login   <gascio_m@epitech.net>
**
** Started on  Fri Mar  4 01:43:02 2016 Mathieu GASCIOLLI
** Last update Tue Mar  8 17:06:10 2016 Mathieu GASCIOLLI
*/

#include "poker.h"

void	init_params()
{
  jeu.stack = 1000;
  jeu.blind = 20;
  jeu.ianame = "John Smith";
}

void	res_mises()
{
  player.mise = 0;
  ia.mise = 0;
}

carte   *init_board()
{
  int   i;

  i = 0;
  while (i < 5)
    {
      board[i].valeur = 0;
      board[i].couleur = 0;
      i++;
    }
  return (board);
}

carte   *init_paquet()
{
  int   i;
  int   j;

  i = 0;
  j = 1;
  while (i < 13)
    {
      paquet[i].couleur = PIQUE;
      paquet[i].valeur = j;
      j++;
      i++;
    }
  j = 1;
  while (i < 26)
    {
      paquet[i].couleur = CARREAU;
      paquet[i].valeur = j;
      j++;
      i++;
    }
  j = 1;
  while (i < 39)
    {
      paquet[i].couleur = TREFLE;
      paquet[i].valeur = j;
      j++;
      i++;
    }
  j = 1;
  while (i < 52)
    {
      paquet[i].couleur = COEUR;
      paquet[i].valeur = j;
      j++;
      i++;
    }
  return (paquet);
}

void	set_players_datas()
{
  ia.name = jeu.ianame;
  ia.argent = jeu.stack;
  player.argent = jeu.stack;
  ia.mise = 0;
  player.mise = 0;
}

int	choose_name()
{
  while (!player.name || strlen(player.name) < 2)
    {
      move(LINES/2 + 2, COLS/2 - 11);
      printw("Votre nom: ");
      player.name = malloc(100*sizeof(char));
      scanw("%s", player.name);
    }
}

void	some_inits()
{
  situation = CHECK;
  dealer = 1;
  pot = 0;
}
