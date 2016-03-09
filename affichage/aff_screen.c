/*
** aff_screen.c for PokerPoked in /home/gascio_m/code/PokerPoked/affichage
**
** Made by Mathieu GASCIOLLI
** Login   <gascio_m@epitech.net>
**
** Started on  Fri Mar  4 14:27:08 2016 Mathieu GASCIOLLI
** Last update Wed Mar  9 17:36:32 2016 Mathieu GASCIOLLI
*/

#include "poker.h"

void	init_screen()
{
  int	i;

  i = 0;
  initscr();
  start_color();
  cbreak();
  couleurs();
  mvprintw((LINES / 2), (COLS /2) - 3, "POKER");
  set_players_datas();
  choose_name();
  refresh();
  curs_set(0);
  noecho();
  clear();
}

void	close_screen()
{
  endwin();
}

void	affichage_hud()
{
  int	i;

  aff_noms();
  aff_cartes_joueur();
  aff_cartes_IA();
  aff_sous();
  aff_dealer();
  aff_pot();
  i = check_board();
  if (i == FLOP)
    aff_cartes_flop();
  else if (i == TURN)
    aff_cartes_turn();
  else if (i == RIVER)
    aff_cartes_river();
}

void	affichage_hud_board()
{
  int	i;

  aff_noms();
  aff_cartes_joueur();
  aff_cartes_IA();
  aff_sous();
  aff_dealer();
  aff_pot();
  aff_cartes_board();
}

void	affichage_hud_board_end()
{
  int	i;

  aff_noms();
  aff_cartes_joueur();
  aff_cartes_IA_end();
  aff_sous();
  aff_dealer();
  aff_pot();
  aff_cartes_board();
}
