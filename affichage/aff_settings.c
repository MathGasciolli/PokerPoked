/*
** aff_settings.c for PokerPoked in /home/gascio_m/code/PokerPoked/affichage
**
** Made by Mathieu GASCIOLLI
** Login   <gascio_m@epitech.net>
**
** Started on  Fri Mar 11 18:25:51 2016 Mathieu GASCIOLLI
** Last update Mon Mar 14 15:07:20 2016 Mathieu GASCIOLLI
*/

#include "poker.h"

void	aff_langues(int k, char **opt)
{
  int	i;

  i = 0;
  while (i < 2)
    {
      if (i == k)
	{
	  attron(A_REVERSE);
	  mvprintw(5+2*i, COLS/2 - strlen(opt[i])/2, "%s", opt[i]);
	  attroff(A_REVERSE);
	}
      else
	mvprintw(5+2*i, COLS/2 - strlen(opt[i])/2, "%s", opt[i]);
      i++;
    }
}

void	aff_langs()
{
  int	selected = 0;
  int	c;
  char	*langues[] = {
    "english",
    "francais",
  };

  c = 0;
  keypad(stdscr, TRUE);
  aff_langues(selected, langues);
  refresh();
  while (c != 10)
    {
      c = getch();
      if (c == KEY_UP && selected > 0)
	selected--;
      else if (c == KEY_DOWN && selected < 1)
	selected++;
      else if (c == 10){
	jeu.lang = langues[selected];
	if (strcmp(jeu.lang, "english") == 0)
	  jeu.langue = english;
	else if (strcmp(jeu.lang, "francais") == 0)
	  jeu.langue = francais;
      }
      clear();
      aff_langues(selected, langues);
      refresh();
    }
}

void	aff_settings(int selected, char **option)
{
  int	i;
  char	**params;

  params = malloc(10 * sizeof(char*));
  for (i=0;i<9;i++)
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
  sprintf(params[8], "%s", jeu.lang);
  i = 0;
  attron(A_DIM);
  while (i < 10)
    {
      if (i == selected && i != 9)
	{
	  attron(A_REVERSE);
	  mvprintw(8+3*i, 30, "%s: ", option[i]);
	  mvprintw(8+3*i, COLS-strlen(params[i])-30, "'%s'", params[i]);
	  attroff(A_REVERSE);
	}
      else if (i == 9 && i != selected)
	mvprintw(8+4*i, COLS/2 - (strlen(option[i])/2), "%s", option[i]);
      else if (i == 9 && i == selected){
	attron(A_REVERSE);
	mvprintw(8+4*i, COLS/2 - (strlen(option[i])/2), "%s", option[i]);
	attroff(A_REVERSE);
      }
      else
	{
	  mvprintw(8+3*i, 30, "%s: ", option[i]);
	  mvprintw(8+3*i, COLS-strlen(params[i])-30, "'%s'", params[i]);
	}
      i++;
    }
  mvprintw(3, COLS/2-4, "%s", jeu.langue.settings);
  mvprintw(LINES-4, COLS/2 - 17, "%s", jeu.langue.press_fin);
  mvprintw(LINES-3, COLS/2 - 17, "%s", jeu.langue.press_esc);
  attroff(A_DIM);
  free(params);
}

void	modif(int i)
{
  char	c;
  char	*tmp;

  tmp = malloc(100 * sizeof(char));
  clear();
  refresh();
  if (i == 0)
    {
      echo();
      curs_set(1);
      mvprintw(LINES/2 - 5, COLS/2 - 11, "%s", jeu.langue.enter_bank);
      mvscanw(LINES/2, COLS/2 - 3, "%s", tmp);
      jeu.stack = atoi(tmp);
      if (jeu.stack < 0)
	jeu.stack = 0;
      curs_set(0);
      noecho();
    }
  else if (i == 1)
    {
      echo();
      curs_set(1);
      mvprintw(LINES/2 - 5, COLS/2 - 9, "%s", jeu.langue.enter_blind);
      mvscanw(LINES/2, COLS/2 - 3, "%s", tmp);
      jeu.blind = atoi(tmp);
      if (jeu.blind < 0)
	jeu.blind = 0;
      curs_set(0);
      noecho();
    }
  else if (i == 2)
    {
      echo();
      curs_set(1);
      jeu.ianame = malloc(100 * sizeof(char));
      mvprintw(LINES/2 - 5, COLS/2 - 10, "%s", jeu.langue.enter_ianame);
      mvscanw(LINES/2, COLS/2 - 8, "%[^\n]", jeu.ianame);
      while (strlen(jeu.ianame) <= 2){
	mvscanw(LINES/2, COLS/2 - 8, "%[^\n]", jeu.ianame);
	if (strlen(jeu.ianame) <= 2)
	  mvprintw(LINES/2, COLS/2 -8, "   ");
	refresh();
      }
      curs_set(0);
      noecho();
    }
  else if (i == 3)
    {
      echo();
      curs_set(1);
      jeu.playername = malloc(100 * sizeof(char));
      mvprintw(LINES/2 - 5, COLS/2 - 10, "%s", jeu.langue.enter_plname);
      mvscanw(LINES/2, COLS/2 - 8, "%[^\n]", jeu.playername);
      while (strlen(jeu.playername) <= 2){
	mvscanw(LINES/2, COLS/2 - 8, "%[^\n]", jeu.playername);
	if (strlen(jeu.playername) <= 2)
	  mvprintw(LINES/2, COLS/2 -8, "   ");
	refresh();
      }
      curs_set(0);
      noecho();
    }
  else if (i == 4)
    {
      mvprintw(LINES/2 - 5, COLS/2 - 5, "%s", jeu.langue.press_a_key);
      c = getch();
      jeu.button_forces = c;
    }
  else if (i == 5)
    {
      mvprintw(LINES/2 - 5, COLS/2 - 5, "%s", jeu.langue.press_a_key);
      c = getch();
      jeu.button_pause = c;
    }
  else if (i == 6)
    {
      mvprintw(LINES/2 - 5, COLS/2 - 5, "%s", jeu.langue.press_a_key);
      c = getch();
      jeu.button_exit = c;
    }
  else if (i == 7)
    {
      mvprintw(LINES/2 - 5, COLS/2 - 5, "%s", jeu.langue.press_a_key);
      c = getch();
      jeu.button_restart = c;
    }
  else if (i == 8)
    aff_langs();
  else if (i == 9)
    aff_config();
  free(tmp);
}

void	my_putchar(char z)
{
  write(1, &z, 1);
}

void	open_settings()
{
  int	selected;
  int	c = 0;
  char	**option;

  option = malloc(11 * sizeof(char *));
  while (c < 11)
    {
      option[c] = malloc(30 * sizeof(char));
      c++;
    }
  option[0] = jeu.langue.initial_bankroll;
  option[1] = jeu.langue.blind_amount;
  option[2] = jeu.langue.ianame;
  option[3] = jeu.langue.playername;
  option[4] = jeu.langue.show_hands;
  option[5] = jeu.langue.button_pause;
  option[6] = jeu.langue.button_exit;
  option[7] = jeu.langue.button_res;
  option[8] = jeu.langue.lang;
  option[9] = jeu.langue.other_conf;
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
      else if (c == KEY_DOWN && selected < 9)
	selected++;
      else if (c == 360)
	export_config();
      else if (c == 27)
	break;
      else if (c == 10)
	modif(selected);
      clear();
      aff_settings(selected, option);
      refresh();
    }
  free(option);
}
