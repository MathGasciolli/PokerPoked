/*
** aff_config.c for PokerPoked in /home/gascio_m/code/PokerPoked/affichage
**
** Made by Mathieu GASCIOLLI
** Login   <gascio_m@epitech.net>
**
** Started on  Sat Mar 12 15:17:39 2016 Mathieu GASCIOLLI
** Last update Sat Mar 12 16:52:51 2016 Mathieu GASCIOLLI
*/

#include "poker.h"

int	nbr_config()
{
  int	nb = 0;
  DIR	*rep = NULL;
  struct dirent	*dos = NULL;

  rep = opendir("config/");
  while ((dos = readdir(rep)) != NULL)
    {
      if (strcmp(dos->d_name, ".") && strcmp(dos->d_name, ".."))
	nb++;
    }
  closedir(rep);
  return (nb);
}

char	**file_names(char **res)
{
  DIR	*rep = NULL;
  struct dirent	*dos = NULL;
  int	i;

  i = 0;
  res = malloc((nbr_config()+1) * sizeof(char*));
  while (i < nbr_config()+1)
    {
      res[i] = malloc(50 * sizeof(char));
      i++;
    }
  i = 0;
  rep = opendir("config/");
  while ((dos = readdir(rep)) != NULL)
    {
      if (strcmp(dos->d_name, ".") && strcmp(dos->d_name, "..")){
	res[i] = dos->d_name;
	i++;
      }
    }
  closedir(rep);
  return (res);
}

void	aff_config_files(int selected)
{
  char	**opt;
  int	i;

  i = 0;
  opt = file_names(opt);
  attron(A_DIM);
  while (i < nbr_config())
  {
    if (i == selected)
      {
	attron(A_REVERSE);
	mvprintw(10 + 2*i, COLS/2 - strlen(opt[i])/2, "%s", opt[i]);
	attroff(A_REVERSE);
      }
    else
      mvprintw(10 + 2*i, COLS/2 - strlen(opt[i])/2, "%s", opt[i]);
    i++;
  }
  mvprintw(3, COLS/2 - 15, "List of CONFIG files available");
  refresh();
  attroff(A_DIM);
  free(opt);
}

void	aff_config()
{
  int	selected = 0;
  int	c = 0;
  char	**opt;

  opt = file_names(opt);
  clear();
  aff_config_files(selected);
  while (c != 10)
    {
      c = getch();
      if (c == KEY_UP && selected > 0)
	selected--;
      else if (c == KEY_DOWN && selected < nbr_config() - 1)
	selected++;
      else if (c == 27)
	break;
      else if (c == 10)
	init_game(selected);
      aff_config_files(selected);
    }
  free(opt);
}
