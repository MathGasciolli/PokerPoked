/*
** action.c for PokerPoked in /home/gascio_m/code/PokerPoked/jeu
**
** Made by Mathieu GASCIOLLI
** Login   <gascio_m@epitech.net>
**
** Started on  Sat Mar  5 00:23:30 2016 Mathieu GASCIOLLI
** Last update Fri Mar 11 19:41:04 2016 Mathieu GASCIOLLI
*/

#include "poker.h"

int	check_board()
{
  if (board[4].valeur != 0)
    return (RIVER);
  else if (board[3].valeur != 0)
    return (TURN);
  else if (board[2].valeur != 0)
    return (FLOP);
  else
    return (PREFLOP);
}

int	get_action_menu()
{
  int	selected;
  int	c;

  if (situation != ALLIN && situation != FOLD)
    {
      selected = 2;
      keypad(stdscr, TRUE);
      aff_choix(selected);
      c = 0;
      while (c != 10)
	{
	  c = getch();
	  if (c == KEY_LEFT && selected > 1)
	    selected--;
	  else if (c == KEY_RIGHT && selected < 3)
	    selected++;
	  else if (c == 10)
	    return (selected);
	  else if (c == jeu.button_exit)
	    //	    aff_menu_ingame(selected);
	    quitter_prog();
	  else if (c == jeu.button_forces)
	    aff_forces_hands();
	  aff_choix(selected);
	}
    }
  else if (situation == ALLIN)
    {
      selected = 1;
      keypad(stdscr, TRUE);
      aff_choix(selected);
      c = 0;
      while (c != 10)
	{
	  c = getch();
	  if (c == KEY_LEFT && selected > 1)
	    selected--;
	  else if (c == KEY_RIGHT && selected < 2)
	    selected++;
	  else if (c == 10)
	    return (selected);
	  else if (c == jeu.button_exit)
	    //	    aff_menu_ingame(selected);
	    quitter_prog();
	  else if (c == jeu.button_forces)
	    aff_forces_hands();
	  aff_choix(selected);
	}
    }
  else if (situation == FOLD)
    {
      selected = 1;
      keypad(stdscr, TRUE);
      aff_choix(selected);
      c = 0;
      while (c != 10)
	{
	  c = getch();
	  if (c == jeu.button_exit)
	    //	    aff_menu_ingame(selected);
	    quitter_prog();
	  else if (c == 10)
	    return (selected);
	  else if (c == jeu.button_forces)
	    aff_forces_hands();
	  aff_choix(selected);
	}
    }
}

void	get_action()
{
  int	act;

  act = get_action_menu();
  mvprintw(LINES-5, COLS-55, "                                     ");
  refresh();
  if (situation == CHECK)
    {
      if (act == 1)
	act_fold();
      else if (act == 2)
	act_check();
      else if (act == 3)
	act_bet();
    }
  else if (situation == BET)
    {
      if (act == 1)
	act_fold();
      else if (act == 2)
	act_call();
      else if (act == 3)
	act_raise();
    }
  else if (situation == ALLIN)
    {
      if (act == 1)
	act_fold();
      else if (act == 2)
	act_call();
    }
  aff_sous_mise();
  refresh();
}
