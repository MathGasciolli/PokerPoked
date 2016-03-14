/*
** aff_forces.c for PokerPoked in /home/gascio_m/code/PokerPoked/affichage
**
** Made by Mathieu GASCIOLLI
** Login   <gascio_m@epitech.net>
**
** Started on  Fri Mar 11 14:28:39 2016 Mathieu GASCIOLLI
** Last update Mon Mar 14 14:43:33 2016 Mathieu GASCIOLLI
*/

#include "poker.h"

void	aff_forces_hands()
{
  int	i;

  i = 0;
  if (forces_hands == 1)
    {
      mvprintw(1, COLS-25, "%s", jeu.langue.handsstrength);
      mvprintw(3, COLS-30, "1: %s", jeu.langue.high);
      mvprintw(4, COLS-30, "2: %s", jeu.langue.pair);
      mvprintw(5, COLS-30, "3: %s", jeu.langue.twopair);
      mvprintw(6, COLS-30, "4: %s", jeu.langue.trips);
      mvprintw(7, COLS-30, "5: %s", jeu.langue.str);
      mvprintw(8, COLS-30, "6: %s", jeu.langue.flush);
      mvprintw(9, COLS-30, "7: %s", jeu.langue.full);
      mvprintw(10, COLS-30, "8: %s", jeu.langue.four);
      mvprintw(11, COLS-30, "9: %s", jeu.langue.str_fl);
      mvprintw(12, COLS-30, "10: %s", jeu.langue.royal);
      refresh();
    }
  else if (forces_hands == 0)
    {
      while (i < 12)
	{
	  mvprintw(i+1,COLS-31,"                             ");
	  i++;
	}
      refresh();
    }
}
