/*
** aff_menu.c for PokerPoked in /home/gascio_m/code/PokerPoked/affichage
**
** Made by Mathieu GASCIOLLI
** Login   <gascio_m@epitech.net>
**
** Started on  Mon Mar  7 17:49:37 2016 Mathieu GASCIOLLI
** Last update Mon Mar  7 18:08:42 2016 Mathieu GASCIOLLI
*/

#include "poker.h"

int	my_strlen(char *s)
{
  int	i;

  i = 0;
  while (s[i])
    i++;
  return (i);
}

void	aff_menu_ingame(int a)
{
  char	c;

  clear();
  mvprintw(LINES/2-5, COLS/2 - my_strlen("POKERPOKED - Menu")/2 , "POKERPOKED - Menu");
  mvprintw(LINES/2-3, COLS/2 - my_strlen("Press enter to continue")/2, "Press enter to continue");
  mvprintw(LINES/2-2, COLS/2 - my_strlen("Press esc to quit")/2, "Press ESC to quit");
  refresh();
  while (c != 10 || c != 27)
    c = getch();
  if (c == 27)
    quitter_prog();
  else if (c == 10)
    {
      clear();
      keypad(stdscr, TRUE);
      affichage_hud();
      aff_choix(a);
      refresh();
    }
}
