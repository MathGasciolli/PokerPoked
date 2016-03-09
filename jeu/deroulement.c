/*
** deroulement.c for PokerPoked in /home/gascio_m/code/PokerPoked/jeu
**
** Made by Mathieu GASCIOLLI
** Login   <gascio_m@epitech.net>
**
** Started on  Wed Mar  9 02:11:01 2016 Mathieu GASCIOLLI
** Last update Wed Mar  9 18:39:42 2016 Mathieu GASCIOLLI
*/

#include "poker.h"

void	debut_hand()
{
  int	i;

  i = 0;
  malloc_init();
  board = init_board();
  paquet = init_paquet();
  distrib_cartes_debut();
  while (i < 7)
    {
      hand1[i].rank = 0;
      hand2[i].rank = 0;
      hand1[i].suit = 0;
      hand2[i].suit = 0;
      i++;
    }
  ia.mise = 0;
  player.mise = 0;
  blind();
  clear();
  affichage_hud();
}

void	poker_hand()
{
  if (dealer == 1)
    {
      while (check_board() < RIVER)
	{
	  if (last_action == CHECK)
	    res_mises();
	  deroulement(0);
	  if (situation == FOLD)
	    break;
	  deroulement(1);
	  if (situation == FOLD)
	    break;
	}
      end_of_hand_1();
    }
  else if (dealer == 0)
    {
      while (check_board() < RIVER)
	{
	  if (last_action == CHECK)
	    res_mises();
	  deroulement(1);
	  if (situation == FOLD)
	    break;
	  deroulement(0);
	  if (situation == FOLD)
	    break;
	}
      end_of_hand_0();
    }
  change_dealer();
  free_all();
}

void    end_of_hand_0()
{
  if (situation != FOLD)
    {
      deroulement(1);
      deroulement(0);
      if (situation == FOLD)
	{
	  clear();
	  affichage_hud_board();
	}
      else
	{
	  clear();
	  affichage_hud_board_end();
	}
      if (situation != FOLD)
	{
	  get_action();
	  argent_fin(aff_strength(1));
	}
    }
  if (situation == FOLD)
    {
      if (whofolded == PLAYERFOLD)
	mvprintw(5, COLS/2 - 9, "You folded. %s wins the pot.", ia.name);
      else if (whofolded == IAFOLD)
	mvprintw(5, COLS/2 - 9, "%s folded. You win the pot.", ia.name);
      get_action();
    }
  situation = CHECK;
}

void	end_of_hand_1()
{
  if (situation != FOLD)
    {
      deroulement(0);
      deroulement(1);
      if (situation == FOLD)
	{
	  clear();
	  affichage_hud_board();
	}
      else
	{
	  clear();
	  affichage_hud_board_end();
	}
      if (situation != FOLD)
	{
	  get_action();
	  argent_fin(aff_strength(1));
	}
    }
  if (situation == FOLD)
    {
      if (whofolded == PLAYERFOLD)
	mvprintw(5, COLS/2 - 9, "You folded. %s wins the pot.", ia.name);
      else if (whofolded == IAFOLD)
	mvprintw(5, COLS/2 - 9, "%s folded. You win the pot.", ia.name);
      get_action();
    }
  situation = CHECK;
}

void	finpartie(int ac, char **av)
{
  int	c;

  if (player.argent == 0)
    mvprintw(LINES/2, COLS/2 - 11, "You lost the game ! :-(");
  else
    mvprintw(LINES/2, COLS/2 - 11, "You won the game ! :-)");
  mvprintw(LINES/2 + 2, COLS/2 - 10, "Press R to restart !");
  mvprintw(LINES/2+3, COLS/2 - 17, "Or press something else to quit !");
  keypad(stdscr, TRUE);
  c = getch();
  if (c == 'r')
    {
      clear();
      mvprintw(LINES/2, COLS/2 - 10, "Let's Restart !! :-)");
      refresh();
      sleep(2);
      main(ac, av);
    }
  else
    {
      clear();
      mvprintw(LINES/2, COLS/2 - 10, "Au revoir %s..", player.name);
      refresh();
      sleep(2);
      close_screen();
    }
}
