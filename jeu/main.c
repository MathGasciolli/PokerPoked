/*
** main.c for PokerPoked in /home/gascio_m/code/PokerPoked/jeu
**
** Made by Mathieu GASCIOLLI
** Login   <gascio_m@epitech.net>
**
** Started on  Fri Mar  4 00:50:00 2016 Mathieu GASCIOLLI
** Last update Tue Mar  8 21:18:34 2016 Mathieu GASCIOLLI
*/

#include "poker.h"

void	quitter_prog()
{
  clear();
  mvprintw(LINES/2, COLS/2 - 10, "Au revoir %s..", player.name);
  refresh();
  sleep(2);
  close_screen();
  free(paquet);
  exit(EXIT_SUCCESS);
}

void	malloc_init()
{
  paquet = malloc(53 * sizeof(carte));
  joueur = malloc(3 * sizeof(carte));
  board = malloc(6 * sizeof(carte));
  IA = malloc(3 * sizeof(carte));
}

void	free_all()
{
  free(paquet);
  free(joueur);
  free(IA);
  free(board);
}

int	main(int ac, char **av)
{
  int	i;
  int	c;

  i = 0;
  last_action = -1;
  ia_check = 0;
  pl_check = 0;
  srand(time(NULL));
  init_params();
  init_screen();
  some_inits();
  while (player.argent > 0 && ia.argent > 0)
    {
      malloc_init();
      board = init_board();
      paquet = init_paquet();
      distrib_cartes_debut();
      ia.mise = 0;
      player.mise = 0;
      blind();
      clear();
      affichage_hud();
      if (dealer == 1)
	{
	  while (check_board() < RIVER)
	    {
	      if (last_action == CHECK)
		{
		  res_mises();
		  aff_sous();
		  aff_sous_mise();
		  refresh();
		}
	      aff_sous();
	      aff_sous_mise();
	      refresh();
	      ias_turn();
	      aff_sous();
	      aff_sous_mise();
	      refresh();
	      if (situation == FOLD)
		break;
	      get_action();
	      aff_sous();
	      aff_sous_mise();
	      refresh();
	      if (situation == FOLD)
		break;
	    }
	  if (situation != FOLD)
	    {
	      ias_turn();
	      get_action();
	      clear();
	      affichage_hud_board();
	      get_action();
	    }
	  else
	    {
	      //refresh();
	      if (whofolded == PLAYERFOLD)
		mvprintw(5, COLS/2 - 9, "You folded. %s wins the pot.", ia.name);
	      else if (whofolded == IAFOLD)
		mvprintw(5, COLS/2 - 9, "%s folded. You win the pot.", ia.name);
	      get_action();
	    }
	  situation = CHECK;
	}
      else if (dealer == 0)
	{
	  while (check_board() < RIVER)
	    {
	      if (last_action == CHECK)
		{
		  res_mises();
		  aff_sous();
		  aff_sous_mise();
		  refresh();
		}
	      aff_sous();
	      aff_sous_mise();
	      refresh();
	      get_action();
	      aff_sous();
	      aff_sous_mise();
	      refresh();
	      if (situation == FOLD)
		break;
	      ias_turn();
	      aff_sous();
	      aff_sous_mise();
	      refresh();
	      if (situation == FOLD)
		break;
	    }
	  if (situation != FOLD)
	    {
	      ias_turn();
	      get_action();
	      clear();
	      affichage_hud_board();
	      get_action();
	    }
	  else
	    {
	      refresh();
	      if (whofolded == PLAYERFOLD)
		mvprintw(5, COLS/2 - 9, "You folded. %s wins the pot.", ia.name);
	      else if (whofolded == IAFOLD)
		mvprintw(5, COLS/2 - 9, "%s folded. You win the pot.", ia.name);
	      get_action();
	    }
	  situation = CHECK;
	}
      change_dealer();
      free_all();
    }
  clear();
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
      return (0);
    }
}
