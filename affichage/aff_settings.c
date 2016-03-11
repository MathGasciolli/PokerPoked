/*
** aff_settings.c for PokerPoked in /home/gascio_m/code/PokerPoked/affichage
**
** Made by Mathieu GASCIOLLI
** Login   <gascio_m@epitech.net>
**
** Started on  Fri Mar 11 18:25:51 2016 Mathieu GASCIOLLI
** Last update Fri Mar 11 20:51:14 2016 Mathieu GASCIOLLI
*/

#include "poker.h"

void	aff_settings(int selected, char **option)
{
  int	i;
  char	**params;

  params = malloc(50 * sizeof(char*));
  for (i=0;i<8;i++)
    params[i] = malloc(150 * sizeof(char));
  sprintf(params[0], "%d", jeu.stack);
  sprintf(params[1], "%d", jeu.blind);
  sprintf(params[2], "%s", jeu.ianame);
  sprintf(params[3], "%s", jeu.playername);
  if (jeu.button_forces == 27)
    sprintf(params[4], "%s", "ESC");
  else
    sprintf(params[4], "%c", jeu.button_forces);
  if (jeu.button_pause == 27)
    sprintf(params[5], "%s", "ESC");
  else
    sprintf(params[5], "%c", jeu.button_pause);
  if (jeu.button_exit == 27)
    sprintf(params[6], "%s", "ESC");
  else
    sprintf(params[6], "%c", jeu.button_exit);
  if (jeu.button_restart == 27)
    sprintf(params[7], "%s", "ESC");
  else
    sprintf(params[7], "%c", jeu.button_restart);
  i = 0;
  attron(A_DIM);
  while (option[i])
    {
      if (i == selected)
	{
	  attron(A_REVERSE);
	  mvprintw(8+3*i, 30, "%s: ", option[i]);
	  mvprintw(8+3*i, COLS-strlen(params[i])-30, "'%s'", params[i]);
	  attroff(A_REVERSE);
	}
      else
	{
	  mvprintw(8+3*i, 30, "%s: ", option[i]);
	  mvprintw(8+3*i, COLS-strlen(params[i])-30, "'%s'", params[i]);
	}
      i++;
    }
  mvprintw(3, COLS/2-4, "SETTINGS");
  mvprintw(LINES-3, COLS/2 - 16, "Press ESC to return to the menu");
  attroff(A_DIM);
  free(params);
}

void	modif(int i)
{
  char	c;

  clear();
  refresh();
  if (i == 0)
    {
    }
  else if (i == 1)
    {
    }
  else if (i == 2)
    {
    }
  else if (i == 3)
    {
    }
  else if (i == 4)
    {
      mvprintw(LINES/2 - 5, COLS/2 - 5, "Press a key");
      c = getch();
      jeu.button_forces = c;
    }
  else if (i == 5)
    {
      mvprintw(LINES/2 - 5, COLS/2 - 5, "Press a key");
      c = getch();
      jeu.button_pause = c;
    }
  else if (i == 6)
    {
      mvprintw(LINES/2 - 5, COLS/2 - 5, "Press a key");
      c = getch();
      jeu.button_exit = c;
    }
  else if (i == 7)
    {
      mvprintw(LINES/2 - 5, COLS/2 - 5, "Press a key");
      c = getch();
      jeu.button_restart = c;
    }
}

void	open_settings()
{
  int	selected;
  int	c;
  char	*option[] = {
    "INITIAL BANKROLL",
    "BLIND AMOUNT",
    "IA NAME",
    "PLAYER NAME",
    "SHOW HANDS STRENGTH",
    "PAUSE BUTTON",
    "EXIT BUTTON",
    "RESTART BUTTON",
  };

  clear();
  selected = 0;
  keypad(stdscr, TRUE);
  aff_settings(selected, option);
  c = 0;
  refresh();
  while (c != 27)
    {
      c = getch();
      if (c == KEY_UP && selected > 0)
	selected--;
      else if (c == KEY_DOWN && selected < 7)
	selected++;
      else if (c == 27)
	break;
      else if (c == 10)
	modif(selected);
      clear();
      aff_settings(selected, option);
      refresh();
    }
}
