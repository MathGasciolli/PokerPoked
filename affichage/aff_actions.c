/*
** aff_actions.c for PokerPoked in /home/gascio_m/code/PokerPoked/affichage
**
** Made by Mathieu GASCIOLLI
** Login   <gascio_m@epitech.net>
**
** Started on  Fri Mar  4 18:13:00 2016 Mathieu GASCIOLLI
** Last update Sat Mar  5 17:49:33 2016 Mathieu GASCIOLLI
*/

#include "poker.h"

// MY_SELECT DE FOLD-CHECK-BET / FOLD-CALL-RAISE

void	aff_choix(int selected)
{
  int	x;
  int	y;
  int	i;

  i = 0;
  move(LINES - 5, COLS - 55);
  if (situation == CHECK)
    {
      char *option[] = {
	"FOLD",
	"CHECK",
	"BET",
      };
      while (i < 3)
	{
	  if (i == selected - 1)
	    {
	      attron(A_REVERSE);
	      printw("%s", option[i]);
	      attroff(A_REVERSE);
	    }
	  else
	    printw("%s", option[i]);
	  i++;
	  printw("        ");
	  y = y + 10;
	}
    }
  else if (situation == BET)
    {
      char *option[] = {
	"FOLD",
	"CALL",
	"RAISE",
      };
      while (i < 3)
	{
	  if (i == selected - 1)
	    {
	      attron(A_REVERSE);
	      printw("%s", option[i]);
	      if (i == 1)
		printw("(%d)", ia.mise - player.mise);
	      attroff(A_REVERSE);
	    }
	  else
	    {
	      printw("%s", option[i]);
	      if (i == 1)
		printw("(%d)", ia.mise - player.mise);
	    }
	  i++;
	  printw("        ");
	  y = y + 10;
	}
    }
  else if (situation == ALLIN)
    {
      char *option[] = {
	"FOLD",
	"CALL",
      };
      while (i < 2)
	{
	  if (i == selected - 1)
	    {
	      attron(A_REVERSE);
	      printw("%s", option[i]);
	      if (i == 1)
		printw("(%d)", ia.mise - player.mise);
	      attroff(A_REVERSE);
	    }
	  else
	    {
	      printw("%s", option[i]);
	      if (i == 1)
		printw("(%d)", ia.mise - player.mise);
	    }
	  i++;
	  printw("        ");
	  y = y + 10;
	}
    }
  else if (situation == FOLD)
    {
      printw("        ");
      attron(A_REVERSE);
      printw("NEXT");
      attroff(A_REVERSE);
      printw("                      "); // Beurk :/
    }
}
