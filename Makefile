##
## Makefile for PokerPoked in /home/gascio_m/code/PokerPoked
##
## Made by Mathieu GASCIOLLI
## Login   <gascio_m@epitech.net>
##
## Started on  Fri Mar  4 00:35:00 2016 Mathieu GASCIOLLI
## Last update Wed Mar  9 01:28:54 2016 Mathieu GASCIOLLI
##


CC	=gcc

HEADDIR	=includes
SRCDIR1	=jeu
SRCDIR2	=affichage
SRCDIR3	=IA


CFLAGS	= -I$(HEADDIR)

NAME	= poker

SRC	= $(wildcard $(SRCDIR1)/*.c) \
	  $(wildcard $(SRCDIR2)/*.c) \
	  $(wildcard $(SRCDIR1)/$(SRCDIR3)/*.c)

OBJ	= $(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) -lncurses

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

install:	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) -lncurses
	rm -f $(OBJ)
