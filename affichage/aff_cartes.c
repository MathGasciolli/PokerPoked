/*
** aff_cartes.c for PokerPoked in /home/gascio_m/code/PokerPoked/affichage
**
** Made by Mathieu GASCIOLLI
** Login   <gascio_m@epitech.net>
**
** Started on  Fri Mar  4 15:08:15 2016 Mathieu GASCIOLLI
** Last update Mon Mar 14 15:45:20 2016 Mathieu GASCIOLLI
*/

#include "poker.h"

void	aff_cartes_IA()
{
  int	i;
  int	j;
  int	k;

  i = 0;
  k = 5;
  mvprintw(1, k, "|---------|\n");
  while (i < 7)
    {
      mvprintw(i+2, k, "|#########|");
      i++;
    }
  mvprintw(8, k, "|---------|\n");
  k = 18;
  i = 0;
  mvprintw(1, k, "|---------|\n");
  while (i < 7)
    {
      mvprintw(i+2, k, "|#########|");
      i++;
    }
  mvprintw(8, k, "|---------|\n");
}

void	aff_cartes_IA_end()
{
  int	i;
  int	j;

  j = 0;
  i = 8;
  while (i > 0)
    {
      if (i == 8)
	mvprintw(1, 5, "|---------|\n");
      else if (i > 5 && i != 8)
	mvprintw(1+(8-i), 5, "|         |\n");
      else if (i == 5)
	{
	  mvprintw(1+(8-i), 5, "|   ");
	  color_carte(IA[j].couleur);
	  printw("(%s)", interpreteur_valeur(IA[j]));
	  decolor_carte(IA[j].couleur);
	  mvprintw(1+(8-i), 15, "|\n");
	}
      else if (i == 4)
	{
	  mvprintw(1+(8-i), 5, "| ");
	  color_carte(IA[j].couleur);
	  if (IA[j].couleur == PIQUE)
	    printw(" %s ", jeu.langue.pique);
	  else if (IA[j].couleur == CARREAU)
	    printw("%s", jeu.langue.carreau);
	  else if (IA[j].couleur == TREFLE)
	    printw("%s ", jeu.langue.trefle);
	  else if (IA[j].couleur == COEUR)
	    printw(" %s ", jeu.langue.coeur);
	  decolor_carte(IA[j].couleur);
	  mvprintw(1+(8-i), 15, "|");
	}
      else if (i < 4 && i != 1)
	mvprintw(1+(8-i), 5, "|         |\n");
      else if (i == 1)
	mvprintw(1+(8-i), 5, "|---------|\n");
      i--;
    }
  j++;
  i = 8;
  while (i > 0)
    {
      if (i == 8)
	mvprintw(1, 18, "|---------|\n");
      else if (i > 5 && i != 8)
	mvprintw(1+(8-i), 18, "|         |\n");
      else if (i == 5)
	{
	  mvprintw(1+(8-i), 18, "|   ");
	  color_carte(IA[j].couleur);
	  printw("(%s)", interpreteur_valeur(IA[j]));
	  decolor_carte(IA[j].couleur);
	  mvprintw(1+(8-i), 28, "|\n");
	}
      else if (i == 4)
	{
	  mvprintw(1+(8-i), 18, "| ");
	  color_carte(IA[j].couleur);
	  if (IA[j].couleur == PIQUE)
	    printw(" %s ", jeu.langue.pique);
	  else if (IA[j].couleur == CARREAU)
	    printw("%s", jeu.langue.carreau);
	  else if (IA[j].couleur == TREFLE)
	    printw("%s ", jeu.langue.trefle);
	  else if (IA[j].couleur == COEUR)
	    printw(" %s ", jeu.langue.coeur);
	  decolor_carte(IA[j].couleur);
	  mvprintw(1+(8-i), 28, "|");
	}
      else if (i < 4 && i != 1)
	mvprintw(1+(8-i), 18, "|         |\n");
      else if (i == 1)
	mvprintw(1+(8-i), 18, "|---------|\n");
      i--;
    }
}

void	aff_cartes_joueur()
{
  int	i;
  int	j;

  j = 0;
  i = 8;
  while (i > 0)
    {
      if (i == 8)
	mvprintw(LINES - (i + 4), COLS/2-12, "|---------|\n");
      else if (i > 5 && i != 8)
	mvprintw(LINES - (i + 4), COLS/2-12, "|         |\n");
      else if (i == 5)
	{
	  mvprintw(LINES - (i + 4), COLS/2 - 12, "|   ");
	  color_carte(joueur[j].couleur);
	  printw("(%s)", interpreteur_valeur(joueur[j]));
	  decolor_carte(joueur[j].couleur);
	  mvprintw(LINES - (i + 4), COLS/2 - 2, "|\n");
	}
      else if (i == 4)
	{
	  mvprintw(LINES - (i + 4), COLS/2 - 12, "| ");
	  color_carte(joueur[j].couleur);
	  if (joueur[j].couleur == PIQUE)
	    printw(" %s ", jeu.langue.pique);
	  else if (joueur[j].couleur == CARREAU)
	    printw("%s", jeu.langue.carreau);
	  else if (joueur[j].couleur == TREFLE)
	    printw("%s ", jeu.langue.trefle);
	  else if (joueur[j].couleur == COEUR)
	    printw(" %s ", jeu.langue.coeur);
	  decolor_carte(joueur[j].couleur);
	  mvprintw(LINES - (i + 4), COLS/2 - 2, "|");
	}
      else if (i < 4 && i != 1)
	mvprintw(LINES - (i + 4), COLS/2-12, "|         |\n");
      else if (i == 1)
	mvprintw(LINES - (i + 4), COLS/2-12, "|---------|\n");
      i--;
    }
  j++;
  i = 8;
  while (i > 0)
    {
      if (i == 8)
	mvprintw(LINES - (i + 4), COLS/2+1, "|---------|\n");
      else if (i > 5 && i != 8)
	mvprintw(LINES - (i + 4), COLS/2+1, "|         |\n");
      else if (i == 5)
	{
	  mvprintw(LINES - (i + 4), COLS/2 + 1, "|   ");
	  color_carte(joueur[j].couleur);
	  printw("(%s)", interpreteur_valeur(joueur[j]));
	  decolor_carte(joueur[j].couleur);
	  mvprintw(LINES - (i + 4), COLS/2 + 11, "|\n");
	}
      else if (i == 4)
	{
	  mvprintw(LINES - (i + 4), COLS/2 + 1, "| ");
	  color_carte(joueur[j].couleur);
	  if (joueur[j].couleur == PIQUE)
	    printw(" %s ", jeu.langue.pique);
	  else if (joueur[j].couleur == CARREAU)
	    printw("%s", jeu.langue.carreau);
	  else if (joueur[j].couleur == TREFLE)
	    printw("%s ", jeu.langue.trefle);
	  else if (joueur[j].couleur == COEUR)
	    printw(" %s ", jeu.langue.coeur);
	  decolor_carte(joueur[j].couleur);
	  mvprintw(LINES - (i + 4), COLS/2 + 11, "|");
	}
      else if (i < 4 && i != 1)
	mvprintw(LINES - (i + 4), COLS/2+1, "|         |\n");
      else if (i == 1)
	mvprintw(LINES - (i + 4), COLS/2+1, "|---------|\n");
      i--;
    }
}

void	aff_cartes_turn()
{
  int   i;
  int   j;

  mvprintw(5, COLS/2 - 9, "%s", jeu.langue.turn);
  j = 0;
  i = 8;
  while (i > 0)
    {
      if (i == 8)
	mvprintw(LINES/2 - i, COLS/2-30, "|---------|\n");
      else if (i > 5 && i != 8)
	mvprintw(LINES/2 - i, COLS/2-30, "|         |\n");
      else if (i == 5)
	{
	  mvprintw(LINES/2 - i, COLS/2 - 30, "|   ");
	  color_carte(board[j].couleur);
	  printw("(%s)", interpreteur_valeur(board[j]));
	  decolor_carte(board[j].couleur);
	  mvprintw(LINES/2 - i, COLS/2 - 20, "|\n");
	}
      else if (i == 4)
	{
	  mvprintw(LINES/2 - i, COLS/2 - 30, "| ");
	  color_carte(board[j].couleur);
	  if (board[j].couleur == PIQUE)
	    printw(" %s ", jeu.langue.pique);
	  else if (board[j].couleur == CARREAU)
	    printw("%s", jeu.langue.carreau);
	  else if (board[j].couleur == TREFLE)
	    printw("%s ", jeu.langue.trefle);
	  else if (board[j].couleur == COEUR)
	    printw(" %s ", jeu.langue.coeur);
	  decolor_carte(board[j].couleur);
	  mvprintw(LINES/2 - i, COLS/2 - 20, "|");
	}
      else if (i < 4 && i != 1)
	mvprintw(LINES/2 - i, COLS/2-30, "|         |\n");
      else if (i == 1)
	mvprintw(LINES/2 - i, COLS/2-30, "|---------|\n");
      i--;
    }
  j++;
  i = 8;
  while (i > 0)
    {
      if (i == 8)
	mvprintw(LINES/2 - i, COLS/2-18, "|---------|\n");
      else if (i > 5 && i != 8)
	mvprintw(LINES/2 - i, COLS/2-18, "|         |\n");
      else if (i == 5)
	{
	  mvprintw(LINES/2 - i, COLS/2 - 18, "|   ");
	  color_carte(board[j].couleur);
	  printw("(%s)", interpreteur_valeur(board[j]));
	  decolor_carte(board[j].couleur);
	  mvprintw(LINES/2 - i, COLS/2 - 8, "|\n");
	}
      else if (i == 4)
	{
	  mvprintw(LINES/2 - i, COLS/2 - 18, "| ");
	  color_carte(board[j].couleur);
	  if (board[j].couleur == PIQUE)
	    printw(" %s ", jeu.langue.pique);
	  else if (board[j].couleur == CARREAU)
	    printw("%s", jeu.langue.carreau);
	  else if (board[j].couleur == TREFLE)
	    printw("%s ", jeu.langue.trefle);
	  else if (board[j].couleur == COEUR)
	    printw(" %s ", jeu.langue.coeur);
	  decolor_carte(board[j].couleur);
	  mvprintw(LINES/2 - i, COLS/2 - 8, "|");
	}
      else if (i < 4 && i != 1)
	mvprintw(LINES/2 - i, COLS/2-18, "|         |\n");
      else if (i == 1)
	mvprintw(LINES/2 - i, COLS/2-18, "|---------|\n");
      i--;
    }
  j++;
  i = 8;
  while (i > 0)
    {
      if (i == 8)
	mvprintw(LINES/2 - i, COLS/2-6, "|---------|\n");
      else if (i > 5 && i != 8)
	mvprintw(LINES/2 - i, COLS/2-6, "|         |\n");
      else if (i == 5)
	{
	  mvprintw(LINES/2 - i, COLS/2 - 6, "|   ");
	  color_carte(board[j].couleur);
	  printw("(%s)", interpreteur_valeur(board[j]));
	  decolor_carte(board[j].couleur);
	  mvprintw(LINES/2 - i, COLS/2 + 4, "|\n");
	}
      else if (i == 4)
	{
	  mvprintw(LINES/2 - i, COLS/2 - 6, "| ");
	  color_carte(board[j].couleur);
	  if (board[j].couleur == PIQUE)
	    printw(" %s ", jeu.langue.pique);
	  else if (board[j].couleur == CARREAU)
	    printw("%s", jeu.langue.carreau);
	  else if (board[j].couleur == TREFLE)
	    printw("%s ", jeu.langue.trefle);
	  else if (board[j].couleur == COEUR)
	    printw(" %s ", jeu.langue.coeur);
	  decolor_carte(board[j].couleur);
	  mvprintw(LINES/2 - i, COLS/2 + 4, "|");
	}
      else if (i < 4 && i != 1)
	mvprintw(LINES/2 - i, COLS/2-6, "|         |\n");
      else if (i == 1)
	mvprintw(LINES/2 - i, COLS/2-6, "|---------|\n");
      i--;
    }
  j++;
  refresh();
  sleep(1);
  i = 8;
  while (i > 0)
    {
      if (i == 8)
	mvprintw(LINES/2 - i, COLS/2+6, "|---------|\n");
      else if (i > 5 && i != 8)
	mvprintw(LINES/2 - i, COLS/2+6, "|         |\n");
      else if (i == 5)
	{
	  mvprintw(LINES/2 - i, COLS/2 + 6, "|   ");
	  color_carte(board[j].couleur);
	  printw("(%s)", interpreteur_valeur(board[j]));
	  decolor_carte(board[j].couleur);
	  mvprintw(LINES/2 - i, COLS/2 + 16, "|\n");
	}
      else if (i == 4)
	{
	  mvprintw(LINES/2 - i, COLS/2 + 6, "| ");
	  color_carte(board[j].couleur);
	  if (board[j].couleur == PIQUE)
	    printw(" %s ", jeu.langue.pique);
	  else if (board[j].couleur == CARREAU)
	    printw("%s", jeu.langue.carreau);
	  else if (board[j].couleur == TREFLE)
	    printw("%s ", jeu.langue.trefle);
	  else if (board[j].couleur == COEUR)
	    printw(" %s ", jeu.langue.coeur);
	  decolor_carte(board[j].couleur);
	  mvprintw(LINES/2 - i, COLS/2 + 16, "|");
	}
      else if (i < 4 && i != 1)
	mvprintw(LINES/2 - i, COLS/2+6, "|         |\n");
      else if (i == 1)
	mvprintw(LINES/2 - i, COLS/2+6, "|---------|\n");
      i--;
    }
  mvprintw(5, COLS/2 - 9, "                                                                                ");
  refresh();
  sleep(1);
}

void	aff_cartes_river()
{
  int   i;
  int   j;

  mvprintw(5, COLS/2 - 9, "%s", jeu.langue.river);
  j = 0;
  i = 8;
  while (i > 0)
    {
      if (i == 8)
	mvprintw(LINES/2 - i, COLS/2-30, "|---------|\n");
      else if (i > 5 && i != 8)
	mvprintw(LINES/2 - i, COLS/2-30, "|         |\n");
      else if (i == 5)
	{
	  mvprintw(LINES/2 - i, COLS/2 - 30, "|   ");
	  color_carte(board[j].couleur);
	  printw("(%s)", interpreteur_valeur(board[j]));
	  decolor_carte(board[j].couleur);
	  mvprintw(LINES/2 - i, COLS/2 - 20, "|\n");
	}
      else if (i == 4)
	{
	  mvprintw(LINES/2 - i, COLS/2 - 30, "| ");
	  color_carte(board[j].couleur);
	  if (board[j].couleur == PIQUE)
	    printw(" %s ", jeu.langue.pique);
	  else if (board[j].couleur == CARREAU)
	    printw("%s", jeu.langue.carreau);
	  else if (board[j].couleur == TREFLE)
	    printw("%s ", jeu.langue.trefle);
	  else if (board[j].couleur == COEUR)
	    printw(" %s ", jeu.langue.coeur);
	  decolor_carte(board[j].couleur);
	  mvprintw(LINES/2 - i, COLS/2 - 20, "|");
	}
      else if (i < 4 && i != 1)
	mvprintw(LINES/2 - i, COLS/2-30, "|         |\n");
      else if (i == 1)
	mvprintw(LINES/2 - i, COLS/2-30, "|---------|\n");
      i--;
    }
  j++;
  i = 8;
  while (i > 0)
    {
      if (i == 8)
	mvprintw(LINES/2 - i, COLS/2-18, "|---------|\n");
      else if (i > 5 && i != 8)
	mvprintw(LINES/2 - i, COLS/2-18, "|         |\n");
      else if (i == 5)
	{
	  mvprintw(LINES/2 - i, COLS/2 - 18, "|   ");
	  color_carte(board[j].couleur);
	  printw("(%s)", interpreteur_valeur(board[j]));
	  decolor_carte(board[j].couleur);
	  mvprintw(LINES/2 - i, COLS/2 - 8, "|\n");
	}
      else if (i == 4)
	{
	  mvprintw(LINES/2 - i, COLS/2 - 18, "| ");
	  color_carte(board[j].couleur);
	  if (board[j].couleur == PIQUE)
	    printw(" %s ", jeu.langue.pique);
	  else if (board[j].couleur == CARREAU)
	    printw("%s", jeu.langue.carreau);
	  else if (board[j].couleur == TREFLE)
	    printw("%s ", jeu.langue.trefle);
	  else if (board[j].couleur == COEUR)
	    printw(" %s ", jeu.langue.coeur);
	  decolor_carte(board[j].couleur);
	  mvprintw(LINES/2 - i, COLS/2 - 8, "|");
	}
      else if (i < 4 && i != 1)
	mvprintw(LINES/2 - i, COLS/2-18, "|         |\n");
      else if (i == 1)
	mvprintw(LINES/2 - i, COLS/2-18, "|---------|\n");
      i--;
    }
  j++;
  i = 8;
  while (i > 0)
    {
      if (i == 8)
	mvprintw(LINES/2 - i, COLS/2-6, "|---------|\n");
      else if (i > 5 && i != 8)
	mvprintw(LINES/2 - i, COLS/2-6, "|         |\n");
      else if (i == 5)
	{
	  mvprintw(LINES/2 - i, COLS/2 - 6, "|   ");
	  color_carte(board[j].couleur);
	  printw("(%s)", interpreteur_valeur(board[j]));
	  decolor_carte(board[j].couleur);
	  mvprintw(LINES/2 - i, COLS/2 + 4, "|\n");
	}
      else if (i == 4)
	{
	  mvprintw(LINES/2 - i, COLS/2 - 6, "| ");
	  color_carte(board[j].couleur);
	  if (board[j].couleur == PIQUE)
	    printw(" %s ", jeu.langue.pique);
	  else if (board[j].couleur == CARREAU)
	    printw("%s", jeu.langue.carreau);
	  else if (board[j].couleur == TREFLE)
	    printw("%s ", jeu.langue.trefle);
	  else if (board[j].couleur == COEUR)
	    printw(" %s ", jeu.langue.coeur);
	  decolor_carte(board[j].couleur);
	  mvprintw(LINES/2 - i, COLS/2 + 4, "|");
	}
      else if (i < 4 && i != 1)
	mvprintw(LINES/2 - i, COLS/2-6, "|         |\n");
      else if (i == 1)
	mvprintw(LINES/2 - i, COLS/2-6, "|---------|\n");
      i--;
    }
  j++;
  i = 8;
  while (i > 0)
    {
      if (i == 8)
	mvprintw(LINES/2 - i, COLS/2+6, "|---------|\n");
      else if (i > 5 && i != 8)
	mvprintw(LINES/2 - i, COLS/2+6, "|         |\n");
      else if (i == 5)
	{
	  mvprintw(LINES/2 - i, COLS/2 + 6, "|   ");
	  color_carte(board[j].couleur);
	  printw("(%s)", interpreteur_valeur(board[j]));
	  decolor_carte(board[j].couleur);
	  mvprintw(LINES/2 - i, COLS/2 + 16, "|\n");
	}
      else if (i == 4)
	{
	  mvprintw(LINES/2 - i, COLS/2 + 6, "| ");
	  color_carte(board[j].couleur);
	  if (board[j].couleur == PIQUE)
	    printw(" %s ", jeu.langue.pique);
	  else if (board[j].couleur == CARREAU)
	    printw("%s", jeu.langue.carreau);
	  else if (board[j].couleur == TREFLE)
	    printw("%s ", jeu.langue.trefle);
	  else if (board[j].couleur == COEUR)
	    printw(" %s ", jeu.langue.coeur);
	  decolor_carte(board[j].couleur);
	  mvprintw(LINES/2 - i, COLS/2 + 16, "|");
	}
      else if (i < 4 && i != 1)
	mvprintw(LINES/2 - i, COLS/2+6, "|         |\n");
      else if (i == 1)
	mvprintw(LINES/2 - i, COLS/2+6, "|---------|\n");
      i--;
    }
  j++;
  refresh();
  sleep(1);
  i = 8;
  while (i > 0)
    {
      if (i == 8)
	mvprintw(LINES/2 - i, COLS/2+18, "|---------|\n");
      else if (i > 5 && i != 8)
	mvprintw(LINES/2 - i, COLS/2+18, "|         |\n");
      else if (i == 5)
	{
	  mvprintw(LINES/2 - i, COLS/2 + 18, "|   ");
	  color_carte(board[j].couleur);
	  printw("(%s)", interpreteur_valeur(board[j]));
	  decolor_carte(board[j].couleur);
	  mvprintw(LINES/2 - i, COLS/2 + 28, "|\n");
	}
      else if (i == 4)
	{
	  mvprintw(LINES/2 - i, COLS/2 + 18, "| ");
	  color_carte(board[j].couleur);
	  if (board[j].couleur == PIQUE)
	    printw(" %s ", jeu.langue.pique);
	  else if (board[j].couleur == CARREAU)
	    printw("%s", jeu.langue.carreau);
	  else if (board[j].couleur == TREFLE)
	    printw("%s ", jeu.langue.trefle);
	  else if (board[j].couleur == COEUR)
	    printw(" %s ", jeu.langue.coeur);
	  decolor_carte(board[j].couleur);
	  mvprintw(LINES/2 - i, COLS/2 + 28, "|");
	}
      else if (i < 4 && i != 1)
	mvprintw(LINES/2 - i, COLS/2+18, "|         |\n");
      else if (i == 1)
	mvprintw(LINES/2 - i, COLS/2+18, "|---------|\n");
      i--;
    }
  mvprintw(5, COLS/2 - 9, "                                                                                              ");
  refresh();
  sleep(1);
}

void    aff_cartes_flop()
{
  int   i;
  int   j;

  mvprintw(5, COLS/2 - 9, "%s", jeu.langue.flop);
  j = 0;
  i = 8;
  refresh();
  sleep(1);
  while (i > 0)
    {
      if (i == 8)
	mvprintw(LINES/2 - i, COLS/2-30, "|---------|\n");
      else if (i > 5 && i != 8)
	mvprintw(LINES/2 - i, COLS/2-30, "|         |\n");
      else if (i == 5)
	{
	  mvprintw(LINES/2 - i, COLS/2 - 30, "|   ");
	  color_carte(board[j].couleur);
	  printw("(%s)", interpreteur_valeur(board[j]));
	  decolor_carte(board[j].couleur);
	  mvprintw(LINES/2 - i, COLS/2 - 20, "|\n");
	}
      else if (i == 4)
	{
	  mvprintw(LINES/2 - i, COLS/2 - 30, "| ");
	  color_carte(board[j].couleur);
	  if (board[j].couleur == PIQUE)
	    printw(" %s ", jeu.langue.pique);
	  else if (board[j].couleur == CARREAU)
	    printw("%s", jeu.langue.carreau);
	  else if (board[j].couleur == TREFLE)
	    printw("%s ", jeu.langue.trefle);
	  else if (board[j].couleur == COEUR)
	    printw(" %s ", jeu.langue.coeur);
	  decolor_carte(board[j].couleur);
	  mvprintw(LINES/2 - i, COLS/2 - 20, "|");
	}
      else if (i < 4 && i != 1)
	mvprintw(LINES/2 - i, COLS/2-30, "|         |\n");
      else if (i == 1)
	mvprintw(LINES/2 - i, COLS/2-30, "|---------|\n");
      i--;
    }
  j++;
  refresh();
  sleep(1);
  i = 8;
  while (i > 0)
    {
      if (i == 8)
	mvprintw(LINES/2 - i, COLS/2-18, "|---------|\n");
      else if (i > 5 && i != 8)
	mvprintw(LINES/2 - i, COLS/2-18, "|         |\n");
      else if (i == 5)
	{
	  mvprintw(LINES/2 - i, COLS/2 - 18, "|   ");
	  color_carte(board[j].couleur);
	  printw("(%s)", interpreteur_valeur(board[j]));
	  decolor_carte(board[j].couleur);
	  mvprintw(LINES/2 - i, COLS/2 - 8, "|\n");
	}
      else if (i == 4)
	{
	  mvprintw(LINES/2 - i, COLS/2 - 18, "| ");
	  color_carte(board[j].couleur);
	  if (board[j].couleur == PIQUE)
	    printw(" %s ", jeu.langue.pique);
	  else if (board[j].couleur == CARREAU)
	    printw("%s", jeu.langue.carreau);
	  else if (board[j].couleur == TREFLE)
	    printw("%s ", jeu.langue.trefle);
	  else if (board[j].couleur == COEUR)
	    printw(" %s ", jeu.langue.coeur);
	  decolor_carte(board[j].couleur);
	  mvprintw(LINES/2 - i, COLS/2 - 8, "|");
	}
      else if (i < 4 && i != 1)
	mvprintw(LINES/2 - i, COLS/2-18, "|         |\n");
      else if (i == 1)
	mvprintw(LINES/2 - i, COLS/2-18, "|---------|\n");
      i--;
    }
  j++;
  refresh();
  sleep(1);
  i = 8;
  while (i > 0)
    {
      if (i == 8)
	mvprintw(LINES/2 - i, COLS/2-6, "|---------|\n");
      else if (i > 5 && i != 8)
	mvprintw(LINES/2 - i, COLS/2-6, "|         |\n");
      else if (i == 5)
	{
	  mvprintw(LINES/2 - i, COLS/2 - 6, "|   ");
	  color_carte(board[j].couleur);
	  printw("(%s)", interpreteur_valeur(board[j]));
	  decolor_carte(board[j].couleur);
	  mvprintw(LINES/2 - i, COLS/2 + 4, "|\n");
	}
      else if (i == 4)
	{
	  mvprintw(LINES/2 - i, COLS/2 - 6, "| ");
	  color_carte(board[j].couleur);
	  if (board[j].couleur == PIQUE)
	    printw(" %s ", jeu.langue.pique);
	  else if (board[j].couleur == CARREAU)
	    printw("%s", jeu.langue.carreau);
	  else if (board[j].couleur == TREFLE)
	    printw("%s ", jeu.langue.trefle);
	  else if (board[j].couleur == COEUR)
	    printw(" %s ", jeu.langue.coeur);
	  decolor_carte(board[j].couleur);
	  mvprintw(LINES/2 - i, COLS/2 + 4, "|");
	}
      else if (i < 4 && i != 1)
	mvprintw(LINES/2 - i, COLS/2-6, "|         |\n");
      else if (i == 1)
	mvprintw(LINES/2 - i, COLS/2-6, "|---------|\n");
      i--;
    }
  mvprintw(5, COLS/2 - 9, "                                                                                            ");
  refresh();
  sleep(1);
}

void	aff_cartes_board()
{
  int   i;
  int   j;

  j = 0;
  i = 8;
  while (i > 0)
    {
      if (i == 8)
	mvprintw(LINES/2 - i, COLS/2-30, "|---------|\n");
      else if (i > 5 && i != 8)
	mvprintw(LINES/2 - i, COLS/2-30, "|         |\n");
      else if (i == 5)
	{
	  mvprintw(LINES/2 - i, COLS/2 - 30, "|   ");
	  color_carte(board[j].couleur);
	  printw("(%s)", interpreteur_valeur(board[j]));
	  decolor_carte(board[j].couleur);
	  mvprintw(LINES/2 - i, COLS/2 - 20, "|\n");
	}
      else if (i == 4)
	{
	  mvprintw(LINES/2 - i, COLS/2 - 30, "| ");
	  color_carte(board[j].couleur);
	  if (board[j].couleur == PIQUE)
	    printw(" %s ", jeu.langue.pique);
	  else if (board[j].couleur == CARREAU)
	    printw("%s", jeu.langue.carreau);
	  else if (board[j].couleur == TREFLE)
	    printw("%s ", jeu.langue.trefle);
	  else if (board[j].couleur == COEUR)
	    printw(" %s ", jeu.langue.coeur);
	  decolor_carte(board[j].couleur);
	  mvprintw(LINES/2 - i, COLS/2 - 20, "|");
	}
      else if (i < 4 && i != 1)
	mvprintw(LINES/2 - i, COLS/2-30, "|         |\n");
      else if (i == 1)
	mvprintw(LINES/2 - i, COLS/2-30, "|---------|\n");
      i--;
    }
  j++;
  i = 8;
  while (i > 0)
    {
      if (i == 8)
	mvprintw(LINES/2 - i, COLS/2-18, "|---------|\n");
      else if (i > 5 && i != 8)
	mvprintw(LINES/2 - i, COLS/2-18, "|         |\n");
      else if (i == 5)
	{
	  mvprintw(LINES/2 - i, COLS/2 - 18, "|   ");
	  color_carte(board[j].couleur);
	  printw("(%s)", interpreteur_valeur(board[j]));
	  decolor_carte(board[j].couleur);
	  mvprintw(LINES/2 - i, COLS/2 - 8, "|\n");
	}
      else if (i == 4)
	{
	  mvprintw(LINES/2 - i, COLS/2 - 18, "| ");
	  color_carte(board[j].couleur);
	  if (board[j].couleur == PIQUE)
	    printw(" %s ", jeu.langue.pique);
	  else if (board[j].couleur == CARREAU)
	    printw("%s", jeu.langue.carreau);
	  else if (board[j].couleur == TREFLE)
	    printw("%s ", jeu.langue.trefle);
	  else if (board[j].couleur == COEUR)
	    printw(" %s ", jeu.langue.coeur);
	  decolor_carte(board[j].couleur);
	  mvprintw(LINES/2 - i, COLS/2 - 8, "|");
	}
      else if (i < 4 && i != 1)
	mvprintw(LINES/2 - i, COLS/2-18, "|         |\n");
      else if (i == 1)
	mvprintw(LINES/2 - i, COLS/2-18, "|---------|\n");
      i--;
    }
  j++;
  i = 8;
  while (i > 0)
    {
      if (i == 8)
	mvprintw(LINES/2 - i, COLS/2-6, "|---------|\n");
      else if (i > 5 && i != 8)
	mvprintw(LINES/2 - i, COLS/2-6, "|         |\n");
      else if (i == 5)
	{
	  mvprintw(LINES/2 - i, COLS/2 - 6, "|   ");
	  color_carte(board[j].couleur);
	  printw("(%s)", interpreteur_valeur(board[j]));
	  decolor_carte(board[j].couleur);
	  mvprintw(LINES/2 - i, COLS/2 + 4, "|\n");
	}
      else if (i == 4)
	{
	  mvprintw(LINES/2 - i, COLS/2 - 6, "| ");
	  color_carte(board[j].couleur);
	  if (board[j].couleur == PIQUE)
	    printw(" %s ", jeu.langue.pique);
	  else if (board[j].couleur == CARREAU)
	    printw("%s", jeu.langue.carreau);
	  else if (board[j].couleur == TREFLE)
	    printw("%s ", jeu.langue.trefle);
	  else if (board[j].couleur == COEUR)
	    printw(" %s ", jeu.langue.coeur);
	  decolor_carte(board[j].couleur);
	  mvprintw(LINES/2 - i, COLS/2 + 4, "|");
	}
      else if (i < 4 && i != 1)
	mvprintw(LINES/2 - i, COLS/2-6, "|         |\n");
      else if (i == 1)
	mvprintw(LINES/2 - i, COLS/2-6, "|---------|\n");
      i--;
    }
  j++;
  i = 8;
  while (i > 0)
    {
      if (i == 8)
	mvprintw(LINES/2 - i, COLS/2+6, "|---------|\n");
      else if (i > 5 && i != 8)
	mvprintw(LINES/2 - i, COLS/2+6, "|         |\n");
      else if (i == 5)
	{
	  mvprintw(LINES/2 - i, COLS/2 + 6, "|   ");
	  color_carte(board[j].couleur);
	  printw("(%s)", interpreteur_valeur(board[j]));
	  decolor_carte(board[j].couleur);
	  mvprintw(LINES/2 - i, COLS/2 + 16, "|\n");
	}
      else if (i == 4)
	{
	  mvprintw(LINES/2 - i, COLS/2 + 6, "| ");
	  color_carte(board[j].couleur);
	  if (board[j].couleur == PIQUE)
	    printw(" %s ", jeu.langue.pique);
	  else if (board[j].couleur == CARREAU)
	    printw("%s", jeu.langue.carreau);
	  else if (board[j].couleur == TREFLE)
	    printw("%s ", jeu.langue.trefle);
	  else if (board[j].couleur == COEUR)
	    printw(" %s ", jeu.langue.coeur);
	  decolor_carte(board[j].couleur);
	  mvprintw(LINES/2 - i, COLS/2 + 16, "|");
	}
      else if (i < 4 && i != 1)
	mvprintw(LINES/2 - i, COLS/2+6, "|         |\n");
      else if (i == 1)
	mvprintw(LINES/2 - i, COLS/2+6, "|---------|\n");
      i--;
    }
  j++;
  i = 8;
  while (i > 0)
    {
      if (i == 8)
	mvprintw(LINES/2 - i, COLS/2+18, "|---------|\n");
      else if (i > 5 && i != 8)
	mvprintw(LINES/2 - i, COLS/2+18, "|         |\n");
      else if (i == 5)
	{
	  mvprintw(LINES/2 - i, COLS/2 + 18, "|   ");
	  color_carte(board[j].couleur);
	  printw("(%s)", interpreteur_valeur(board[j]));
	  decolor_carte(board[j].couleur);
	  mvprintw(LINES/2 - i, COLS/2 + 28, "|\n");
	}
      else if (i == 4)
	{
	  mvprintw(LINES/2 - i, COLS/2 + 18, "| ");
	  color_carte(board[j].couleur);
	  if (board[j].couleur == PIQUE)
	    printw(" %s ", jeu.langue.pique);
	  else if (board[j].couleur == CARREAU)
	    printw("%s", jeu.langue.carreau);
	  else if (board[j].couleur == TREFLE)
	    printw("%s ", jeu.langue.trefle);
	  else if (board[j].couleur == COEUR)
	    printw(" %s ", jeu.langue.coeur);
	  decolor_carte(board[j].couleur);
	  mvprintw(LINES/2 - i, COLS/2 + 28, "|");
	}
      else if (i < 4 && i != 1)
	mvprintw(LINES/2 - i, COLS/2+18, "|         |\n");
      else if (i == 1)
	mvprintw(LINES/2 - i, COLS/2+18, "|---------|\n");
      i--;
    }
}
