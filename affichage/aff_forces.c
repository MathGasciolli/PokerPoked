/*
** aff_forces.c for PokerPoked in /home/gascio_m/code/PokerPoked/affichage
**
** Made by Mathieu GASCIOLLI
** Login   <gascio_m@epitech.net>
**
** Started on  Fri Mar 11 14:28:39 2016 Mathieu GASCIOLLI
** Last update Fri Mar 11 14:45:20 2016 Mathieu GASCIOLLI
*/

#include "poker.h"

int	forces_hands = 0;

void	aff_forces_hands()
{
  int	i;

  i = 0;
  if (forces_hands == 0)
    {
      mvprintw(1, COLS-25, "HANDS STRENGTH");
      mvprintw(3, COLS-30, "1: High Card");
      mvprintw(4, COLS-30, "2: One Pair");
      mvprintw(5, COLS-30, "3: Two Pairs");
      mvprintw(6, COLS-30, "4: Three of a kind");
      mvprintw(7, COLS-30, "5: Straight");
      mvprintw(8, COLS-30, "6: Flush");
      mvprintw(9, COLS-30, "7: Full House");
      mvprintw(10, COLS-30, "8: Four of a kind");
      mvprintw(11, COLS-30, "9: Straight Flush");
      mvprintw(12, COLS-30, "10: Royal Flush");
      refresh();
      forces_hands = 1;
    }
  else
    {
      while (i < 12)
	{
	  mvprintw(i+1,COLS-31,"                             ");
	  i++;
	}
      refresh();
      forces_hands = 0;
    }
}
