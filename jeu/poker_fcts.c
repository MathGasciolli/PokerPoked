/*
** poker_fcts.c for PokerPoked in /home/gascio_m/code/PokerPoked/jeu
**
** Made by Mathieu GASCIOLLI
** Login   <gascio_m@epitech.net>
**
** Started on  Sat Mar  5 00:51:23 2016 Mathieu GASCIOLLI
** Last update Wed Mar  9 01:33:43 2016 Mathieu GASCIOLLI
*/

#include "poker.h"

void	blind()
{
  int	blind;

  ia.mise = 0;
  player.mise = 0;
  blind = jeu.blind;
  if (dealer == 0)
    {
      if (ia.argent < jeu.blind)
	blind = ia.argent;
      ia.argent = ia.argent - blind;
      pot = pot + blind;
      ia.mise = blind;
      if (ia.argent > 0)
	situation = BET;
      else
	situation = ALLIN;
    }
  else if (dealer == 1)
    {
      if (player.argent < jeu.blind)
	blind = player.argent;
      player.argent = player.argent - blind;
      pot = pot + blind;
      player.mise = blind;
      if (player.argent > 0)
	situation = BET;
      else
	situation = ALLIN;
    }
}

void    act_fold()
{
  whofolded = PLAYERFOLD;
  ia.argent = ia.argent + pot;
  pot = 0;
  situation = FOLD;
  last_action = FOLD;
}

void	act_check()
{
  if (ia.mise == player.mise)
    {
      if (ia_check == 1)
	{
	  situation = CHECK;
	  ia_check = 0;
	  pl_check = 0;
	  thecheck();
	}
      else
	pl_check = 1;
    }
}

void    thecheck()
{
  int	i;
  int	j;
  int	k;
  int	o;

  o = 0;
  k = check_board();
  if (k == 0)
    {
      j = 0;
      k = 3;
    }
  else if (k == FLOP)
    {
      j = 3;
      k = 4;
    }
  else if (k == TURN)
    {
      j = 4;
      k = 5;
    }
  else if (k == RIVER)
    {
      j = 5;
      k = 5;
      o = 1;
    }
  while (j < k)
    {
      i = rand_carte();
      while (paquet[i].valeur == 0)
	i = rand_carte();
      board[j].valeur = paquet[i].valeur;
      board[j].couleur = paquet[i].couleur;
      paquet[i].valeur = 0;
      j++;
    }
  if (o == 0)
    {
      clear();
      affichage_hud();
    }
  ia.mise = 0;
  player.mise = 0;
  last_action = CHECK;
}

void    act_bet()
{
  int	bet;
  char	*amount;

  bet = 0;
  curs_set(1);
  echo();
  while (42)
    {
      mvprintw(LINES-5, COLS-55, "                                      "); // TRES MOCHE !
      refresh();
      mvprintw(LINES - 5, COLS - 55, "Enter amount: ");
      scanw("%s", amount);
      refresh();
      bet = atoi(amount);
      if (bet <= player.argent && bet > 0)
	break;
    }
  curs_set(0);
  noecho();
  pot = pot + bet;
  player.argent = player.argent - bet;
  player.mise = player.mise + bet;
  if (player.argent > 0)
    situation = BET;
  else
    situation = ALLIN;
  last_action = BET;
}

void    act_call()
{
  int	call;

  call = ia.mise - player.mise;
  if (player.argent < call)
    call = player.argent;
  pot = pot + call;
  player.argent = player.argent - call;
  player.mise = player.mise + call;
  pl_check = 1;
  situation = CHECK;
  last_action = BET;
}

void    act_raise()
{
  int	bet;
  char	*amount;

  bet = 0;
  sprintf(amount, "%d", ia.mise-player.mise);
  curs_set(1);
  echo();
  while (42)
    {
      mvprintw(LINES-5, COLS-55, "                                      "); // TRES MOCHE !
      refresh();
      mvprintw(LINES - 5, COLS - 55, "Enter amount: ");
      scanw("%s", amount);
      refresh();
      bet = atoi(amount);
      if (bet <= player.argent && bet >= ia.mise-player.mise)
	break;
    }
  curs_set(0);
  noecho();
  pot = pot + bet;
  player.argent = player.argent - bet;
  player.mise = player.mise + bet;
  if (player.argent > 0)
    situation = BET;
  else
    situation = ALLIN;
  last_action = BET;
}
