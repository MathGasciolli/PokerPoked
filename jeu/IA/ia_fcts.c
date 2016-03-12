/*
** ia_fcts.c for PokerPoked in /home/gascio_m/code/PokerPoked/jeu
**
** Made by Mathieu GASCIOLLI
** Login   <gascio_m@epitech.net>
**
** Started on  Sat Mar  5 18:17:09 2016 Mathieu GASCIOLLI
** Last update Sat Mar 12 18:28:25 2016 Mathieu GASCIOLLI
*/

#include "poker.h"

int	todo;

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
  last_action = CHECK;
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
  if (player.mise > 0 && player.mise == ia.mise)
    ia_see();
  else{
    pot = pot + amount;
    ia.mise = ia.mise + amount;
    ia.argent = ia.argent - amount;
    situation = BET;
    last_action = BET;
  }
}

void	ias_turn()
{
  int	act;
  int	i;

  mvprintw(5, COLS/2 - 5, "%s's turn..", ia.name);
  refresh();
  i = rand()%5;
  sleep(1);
  if (check_board() == PREFLOP)
    act = ia_preflop(i);
  else if (check_board() == FLOP)
    act = ia_flop(i);
  else if (check_board() == TURN)
    act = ia_turn(i);
  else if (check_board() == RIVER)
    act = ia_river(i);
  if (act == 0){
    mvprintw(5, COLS/2 - 5, "                                                  ");
    mvprintw(5, COLS/2 - 5, "%s folds", ia.name);
    refresh();
    sleep(1);
    ia_fold();
  }
  else if (act == 1){
    mvprintw(5, COLS/2 - 5, "                                                  ");
    mvprintw(5, COLS/2 - 5, "%s checks", ia.name);
    refresh();
    sleep(1);
    ia_see();
  }
  else if (act == 2){
    mvprintw(5, COLS/2 - 5, "                                                  ");
    mvprintw(5, COLS/2 - 5, "%s calls", ia.name);
    refresh();
    sleep(1);
    ia_call();
  }
  else if (act == 3){
    mvprintw(5, COLS/2 - 5, "                                                  ");
    mvprintw(5, COLS/2 - 5, "%s is allin !!", ia.name);
    refresh();
    sleep(1);
    ia_allin();
  }
  else if (act > 4){
    mvprintw(5, COLS/2 - 5, "                                                  ");
    mvprintw(5, COLS/2 - 5, "%s bets", ia.name);
    refresh();
    sleep(1);
    ia_bet(act);
  }
  mvprintw(5, COLS/2 - 5, "                                                  ");
  refresh();
}
