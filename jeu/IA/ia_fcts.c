/*
** ia_fcts.c for PokerPoked in /home/gascio_m/code/PokerPoked/jeu
**
** Made by Mathieu GASCIOLLI
** Login   <gascio_m@epitech.net>
**
** Started on  Sat Mar  5 18:17:09 2016 Mathieu GASCIOLLI
** Last update Wed Mar  9 01:34:09 2016 Mathieu GASCIOLLI
*/

#include "poker.h"

void	ia_fold()
{
  whofolded = IAFOLD;
  player.argent = player.argent + pot;
  pot = 0;
  situation = FOLD;
  last_action = FOLD;
}

void	ia_see()
{
  if (player.mise == ia.mise)
    {
      if (pl_check == 1)
	{
	  situation = CHECK;
	  ia_check = 0;
	  pl_check = 0;
	  thecheck();
	}
      else
	ia_check = 1;
    }
}

void	ia_call()
{
  int	call;

  call = player.mise - ia.mise;
  if (ia.argent < call)
    call = ia.argent;
  pot = pot + call;
  ia.argent = ia.argent - call;
  ia.mise = ia.mise + call;
  ia_check = 1;
  situation = CHECK;
  last_action = BET;
}

void	ia_allin()
{
  pot = pot + ia.argent;
  ia.mise = ia.mise + ia.argent;
  ia.argent = 0;
  situation = ALLIN;
  last_action = BET;
}

void	ia_bet(int amount)
{
  pot = pot + amount;
  ia.mise = ia.mise + amount;
  ia.argent = ia.argent - amount;
  situation = BET;
  last_action = BET;
}

void	ias_turn()
{
  int	act;

  mvprintw(5, COLS/2 - 5, "%s's turn..", ia.name);
  refresh();
  sleep(1);
  if (check_board() == PREFLOP)
    act = ia_preflop();
  /* else if (check_board() == FLOP)
    act = ia_flop();
  else if (check_board() == TURN)
    act = ia_turn();
  else if (check_board() == RIVER)
    act = ia_river();
  */ if (act == 0)
    ia_fold();
  else if (act == 1)
    ia_see();
  else if (act == 2)
    ia_call();
  else if (act == 3)
    ia_allin();
  else if (act > 4)
    ia_bet(act);
  mvprintw(5, COLS/2 - 5, "                                                  ");
  refresh();
}
