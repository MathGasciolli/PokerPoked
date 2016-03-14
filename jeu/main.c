/*
** main.c for PokerPoked in /home/gascio_m/code/PokerPoked/jeu
**
** Made by Mathieu GASCIOLLI
** Login   <gascio_m@epitech.net>
**
** Started on  Fri Mar  4 00:50:00 2016 Mathieu GASCIOLLI
** Last update Mon Mar 14 16:42:40 2016 Mathieu GASCIOLLI
*/

#include "poker.h"

void	quitter_prog()
{
  clear();
  mvprintw(LINES/2, COLS/2 - 10, "%s %s !", jeu.langue.bye, jeu.playername);
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
  free(hand1);
  free(hand2);
  free(paquet);
  free(joueur);
  free(IA);
  free(board);
}

void	deroulement(int o)
{
  if (o == 0)
    {
      aff_sous();
      aff_sous_mise();
      refresh();
      ias_turn();
    }
  else if (o == 1)
    {
      aff_sous();
      aff_sous_mise();
      refresh();
      get_action();
    }
  if (check_board() != PREFLOP)
    aff_strength(0);
  refresh();
}

int	main(int argc, char **argv, char **envp)
{
  if (updating == 0)
    system("git reset --hard origin/master >> /dev/null");
  updating = 1;
  srand(time(NULL));
  lang_english();
  lang_francais();
  init_params();
  init_screen();
  some_inits();
  while (player.argent >= 0 && ia.argent >= 0)
    {
      debut_hand();
      poker_hand();
    }
  clear();
  finpartie(argc, argv, envp);
  return (0);
}
