/*
** action.c for PokerPoked in /home/gascio_m/code/PokerPoked/jeu
**
** Made by Mathieu GASCIOLLI
** Login   <gascio_m@epitech.net>
**
** Started on  Sat Mar  5 00:23:30 2016 Mathieu GASCIOLLI
** Last update Mon Mar 14 16:08:46 2016 Mathieu GASCIOLLI
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
  char	**av;
  char	**env;

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
	    quitter_prog();
	  else if (c == jeu.button_pause)
	    {
	      c = 0;
	      mvprintw(3, COLS/2 - 2, "%s", jeu.langue.paused);
	      refresh();
	      while (c != jeu.button_pause)
		c = getch();
	      mvprintw(3, COLS/2 - 2, "      ");
	      refresh();
	    }
	  else if (c == jeu.button_restart)
	      {
		clear();
		mvprintw(LINES/2, COLS/2 - 15, "%s", jeu.langue.want_to_res);
		mvprintw(LINES/2+1, COLS/2 - 25, "%s", jeu.langue.press_or_not);
		refresh();
		c = 0;
		c = getch();
		if (c == jeu.button_restart)
		  {
		    clear();
		    mvprintw(LINES/2, COLS/2 - 10, "%s", jeu.langue.restarting);
		    refresh();
		    sleep(2);
		    main(0, av, env);
		  }
		else
		  {
		    clear();
		    affichage_hud();
		    refresh();
		  }
	      }
	  else if (c == jeu.button_forces){
	    if (forces_hands == 0)
	      forces_hands = 1;
	    else if (forces_hands == 1)
	      forces_hands = 0;
	  }
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
	    quitter_prog();
	  else if (c == jeu.button_pause)
	    {
	      c = 0;
	      mvprintw(3, COLS/2 - 2, "%s", jeu.langue.paused);
	      refresh();
	      while (c != jeu.button_pause)
		c = getch();
	      mvprintw(3, COLS/2 - 2, "      ");
	      refresh();
	    }
	  else if (c == jeu.button_restart)
	      {
		clear();
		mvprintw(LINES/2, COLS/2 - 15, "%s", jeu.langue.want_to_res);
		mvprintw(LINES/2+1, COLS/2 - 25, "%s", jeu.langue.press_or_not);
		refresh();
		c = 0;
		c = getch();
		if (c == jeu.button_restart)
		  {
		    clear();
		    mvprintw(LINES/2, COLS/2 - 10, "%s", jeu.langue.restarting);
		    refresh();
		    sleep(2);
		    main(0, av, env);
		  }
		else
		  {
		    clear();
		    affichage_hud();
		    refresh();
		  }
	      }
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
	    quitter_prog();
	  else if (c == jeu.button_pause)
	    {
	      c = 0;
	      mvprintw(3, COLS/2 - 2, "%s", jeu.langue.paused);
	      refresh();
	      while (c != jeu.button_pause)
		c = getch();
	      mvprintw(3, COLS/2 - 2, "      ");
	      refresh();
	    }
	  else if (c == jeu.button_restart)
	      {
		clear();
		mvprintw(LINES/2, COLS/2 - 15, "%s", jeu.langue.want_to_res);
		mvprintw(LINES/2+1, COLS/2 - 25, "%s", jeu.langue.press_or_not);
		refresh();
		c = 0;
		c = getch();
		if (c == jeu.button_restart)
		  {
		    clear();
		    mvprintw(LINES/2, COLS/2 - 10, "%s", jeu.langue.restarting);
		    refresh();
		    sleep(2);
		    main(0, av, env);
		  }
		else
		  {
		    clear();
		    affichage_hud();
		    refresh();
		  }
	      }
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
  keypad(stdscr, FALSE);
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
