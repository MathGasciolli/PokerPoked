/*
** poker.h for PokerPoked in /home/gascio_m/code/PokerPoked/includes
**
** Made by Mathieu GASCIOLLI
** Login   <gascio_m@epitech.net>
**
** Started on  Fri Mar  4 00:50:29 2016 Mathieu GASCIOLLI
** Last update Mon Mar 14 21:54:22 2016 Mathieu GASCIOLLI
*/

#ifndef POKER_H_
#define POKER_H_

#include <mysql.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <string.h>
#include <ncurses/curses.h>

#include "carte.h"
#include "prototypes.h"
#include "joueur.h"
#include "lang.h"

// LA STRUCTURE PARAMETRES

typedef struct s_params
{
  int	stack;
  int	blind;
  char	*ianame;
  char	*playername;
  char	button_forces;
  char	button_pause;
  char	button_exit;
  char	button_restart;
  char	*lang;
  lang	langue;
} params;

typedef struct s_card
{
  int	rank;
  int	suit;
} Card;

// GLOBALES

int	updating;
params	jeu;
lang	english;
lang	francais;
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
Card	*hand1;
Card	*hand2;
int	forces_hands;
int	key;

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

// GNL

#ifndef READ_SIZE_
#define READ_SIZE (15)
#endif


#endif
