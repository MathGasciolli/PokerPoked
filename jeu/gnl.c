/*
** gnl.c for minishell1 in /home/gascio_m/rendu/PSU_2015_minishell1
**
** Made by Mathieu GASCIOLLI
** Login   <gascio_m@epitech.net>
**
** Started on  Wed Jan 20 18:01:40 2016 Mathieu GASCIOLLI
** Last update Fri Mar 11 16:37:40 2016 Mathieu GASCIOLLI
*/

#include "poker.h"

char* my_realloc(char* ptr, size_t size)
{
  char* tmp;
  int i;

  tmp = ptr;
  ptr = malloc(size);
  i = 0;
  while(tmp[i])
    {
      ptr[i] = tmp[i];
      i++;
    }
  free(tmp);
  return (ptr);
}

char get_char(const int fd)
{
  static char buf[READ_SIZE];
  static char* ptr_buf;
  static int len = 0;
  char c;

  if(len == 0)
    {
      len = read(fd, buf, READ_SIZE);
      ptr_buf = (char*)&buf;
      if(len == 0)
	return (0);
    }
  c = *ptr_buf;
  ptr_buf++;
  len--;
  return c;
}

char *get_next_line(const int fd)
{
  char c;
  char* str;
  int len;

  len = 0;
  str = malloc(READ_SIZE + 1);
  c = get_char(fd);
  while (c != '|' && c != '\0')
    {
      str[len] = c;
      c = get_char(fd);
      len++;
      if(len % (READ_SIZE+1) == 0)
	str = my_realloc(str, len + READ_SIZE + 1);
    }
  str[len] = 0;
  if(c == 0 && str[0] == 0)
      return (0);
  return (str);
}
