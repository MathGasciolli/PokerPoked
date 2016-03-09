/*
** poker.h for PokerPoked in /home/gascio_m/code/PokerPoked/includes
**
** Made by Mathieu GASCIOLLI
** Login   <gascio_m@epitech.net>
**
** Started on  Fri Mar  4 00:50:29 2016 Mathieu GASCIOLLI
** Last update Tue Mar  8 20:53:09 2016 Mathieu GASCIOLLI
*/

#ifndef POKER_H_
#define POKER_H_

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <ncurses/curses.h>

#include "carte.h"
#include "prototypes.h"
#include "joueur.h"

// LA STRUCTURE PARAMETRES

typedef struct s_params
{
  int	stack;
  int	blind;
  char	*ianame;
} params;


// GLOBALES

params	jeu;
carte	*paquet;
carte	*joueur;
carte	*IA;
carte	*board;
play	ia;
play	player;
int	situation;
int	dealer;
int	pot;
int	whofolded;
int	last_action;
int	ia_check;
int	pl_check;

// Macros

#define CHECK (0)
#define BET (1)
#define ALLIN (2)
#define FOLD (3)

// Pour la board

#define PREFLOP (0)
#define FLOP (1)
#define TURN (2)
#define RIVER (3)

// Macros JOUEUR/IA

#define IAFOLD (0)
#define PLAYERFOLD (1)


#endif
