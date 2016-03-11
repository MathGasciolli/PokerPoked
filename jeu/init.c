/*
** init.c for PokerPoked in /home/gascio_m/code/PokerPoked/jeu
**
** Made by Mathieu GASCIOLLI
** Login   <gascio_m@epitech.net>
**
** Started on  Fri Mar  4 01:43:02 2016 Mathieu GASCIOLLI
** Last update Fri Mar 11 16:40:23 2016 Mathieu GASCIOLLI
*/

#include "poker.h"


void	my_putchar(char s)
{
  write(1, &s, 1);
}

void	my_putstr(char *s)
{
  int	i;

  i = 0;
  while (s[i])
    {
      my_putchar(s[i]);
      i++;
    }
}

void	get_params(int fd)
{
  char	*input;

  input = get_next_line(fd);
  input = get_next_line(fd);
  jeu.stack = atoi(input);
  input = get_next_line(fd);
  jeu.blind = atoi(input);
  input = get_next_line(fd);
  jeu.ianame = input;
  input = get_next_line(fd);
  jeu.button_forces = input[0];
  input = get_next_line(fd);
  jeu.button_restart = input[0];
  input = get_next_line(fd);
  jeu.button_menu = input[0];
}

void	init_game(char **av)
{
  int	fd;
  char	*dest;

  dest = malloc(50 * sizeof(char));
  strcat(dest, "config/");
  strcat(dest, av[1]);
  if (access(dest, F_OK))
    {
      printf("File %s not found.\nLet's start with default params..\n", av[1]);
      sleep(1);
      init_params();
    }
  else
    {
      printf("File %s found.\nLoading params..\n", av[1]);
      sleep(1);
      fd = open(dest,O_RDONLY);
      get_params(fd);
    }
}

void	init_params()
{
  jeu.stack = 1000;
  jeu.blind = 20;
  jeu.ianame = "John Smith";
  jeu.button_forces = '<';
  jeu.button_restart = 'r';
  jeu.button_menu = 27;
}

void	res_mises()
{
  player.mise = 0;
  ia.mise = 0;
}

carte   *init_board()
{
  int   i;

  i = 0;
  while (i < 5)
    {
      board[i].valeur = 0;
      board[i].couleur = 0;
      i++;
    }
  return (board);
}

carte   *init_paquet()
{
  int   i;
  int   j;

  i = 0;
  j = 1;
  while (i < 13)
    {
      paquet[i].couleur = PIQUE;
      paquet[i].valeur = j;
      j++;
      i++;
    }
  j = 1;
  while (i < 26)
    {
      paquet[i].couleur = CARREAU;
      paquet[i].valeur = j;
      j++;
      i++;
    }
  j = 1;
  while (i < 39)
    {
      paquet[i].couleur = TREFLE;
      paquet[i].valeur = j;
      j++;
      i++;
    }
  j = 1;
  while (i < 52)
    {
      paquet[i].couleur = COEUR;
      paquet[i].valeur = j;
      j++;
      i++;
    }
  return (paquet);
}

void	set_players_datas()
{
  ia.name = jeu.ianame;
  ia.argent = jeu.stack;
  player.argent = jeu.stack;
  ia.mise = 0;
  player.mise = 0;
}

int	choose_name()
{
  while (!player.name || strlen(player.name) < 2)
    {
      move(LINES/2 + 2, COLS/2 - 11);
      printw("Votre nom: ");
      player.name = malloc(100*sizeof(char));
      scanw("%s", player.name);
    }
}

void	some_inits()
{
  situation = CHECK;
  dealer = 1;
  pot = 0;
  last_action = -1;
  ia_check = 0;
  pl_check = 0;
}
