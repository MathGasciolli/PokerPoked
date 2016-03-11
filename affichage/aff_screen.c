/*
** aff_screen.c for PokerPoked in /home/gascio_m/code/PokerPoked/affichage
**
** Made by Mathieu GASCIOLLI
** Login   <gascio_m@epitech.net>
**
** Started on  Fri Mar  4 14:27:08 2016 Mathieu GASCIOLLI
** Last update Fri Mar 11 18:38:20 2016 Mathieu GASCIOLLI
*/

#include "poker.h"

void	close_screen()
{
  endwin();
  exit(EXIT_SUCCESS);
}

void	aff_menu(int selected, char **aff)
{
  int	i;

  i = 0;
  attron(A_DIM);
  while (i < 3)
    {
      if (i == selected)
	{
	  attron(A_REVERSE);
	  mvprintw(LINES/2 + 2*i, COLS/2 - strlen(aff[i])/2 - 3, "%s", aff[i]);
	  attroff(A_REVERSE);
	}
      else
	mvprintw(LINES/2 + 2*i, COLS/2 - strlen(aff[i])/2 - 3, "%s", aff[i]);
      i++;
    }
  attroff(A_DIM);
}

void	do_thing_menu(int i)
{
  attroff(A_BOLD);
  if (i == 0)
    clear();
  /*else if (i == 1)
    open_settings();*/
  else if (i == 2)
    close_screen();
}

int	aff_accueil()
{
  int	selected;
  int	c;
  char	*aff[] = {
    "PLAY",
    "SETTINGS",
    "QUIT",
  };

  selected = 0;
  attron(A_BOLD);
  keypad(stdscr, TRUE);
  mvprintw(LINES/2 - 15, COLS/2 - 30, "  ___   ___        ___  ___     ___   ___       ___  __");
  mvprintw(LINES/2 - 14, COLS/2 - 30, " |   | |   |  | / |    |   |   |   | |   | | / |    |  \\");
  mvprintw(LINES/2 - 13, COLS/2 - 30, " |___| |   |  |/  |__  |___|   |___| |   | |/  |__  |   |");
  mvprintw(LINES/2 - 12, COLS/2 - 30, " |     |   |  |\\  |    | \\   - |     |   | |\\  |    |   |");
  mvprintw(LINES/2 - 11, COLS/2 - 30, " |     |___|  | \\ |___ |  \\    |     |___| | \\ |___ |__/");
  c = 0;
  aff_menu(selected, aff);
  while (c != 10)
    {
      c = getch();
      if (c == KEY_UP && selected > 0)
	selected--;
      else if (c == KEY_DOWN && selected < 2)
	selected++;
      else if (c == 10)
	return (selected);
      aff_menu(selected, aff);
    }
}

void	init_screen()
{
  int	i;

  i = 0;
  initscr();
  start_color();
  cbreak();
  couleurs();
  curs_set(0);
  noecho();
  clear();
  do_thing_menu(aff_accueil(i));
  clear();
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
