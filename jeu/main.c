/*
** main.c for PokerPoked in /home/gascio_m/code/PokerPoked/jeu
**
** Made by Mathieu GASCIOLLI
** Login   <gascio_m@epitech.net>
**
** Started on  Fri Mar  4 00:50:00 2016 Mathieu GASCIOLLI
** Last update Wed Mar  9 15:18:17 2016 Mathieu GASCIOLLI
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

void	deroulement(int o)
{
  aff_hand_value();
  refresh();
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
}

int	main(int ac, char **av)
{
  srand(time(NULL));
  init_params();
  init_screen();
  some_inits();
  while (player.argent > 0 && ia.argent > 0)
    {
      debut_hand();
      poker_hand();
    }
  clear();
  finpartie(ac, av);
  return (0);
}
