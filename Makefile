##
## Makefile for PokerPoked in /home/gascio_m/code/PokerPoked
##
## Made by Mathieu GASCIOLLI
## Login   <gascio_m@epitech.net>
##
## Started on  Fri Mar  4 00:35:00 2016 Mathieu GASCIOLLI
## Last update Mon Mar 14 23:10:23 2016 Mathieu GASCIOLLI
##

CC	=gcc

HEADDIR	=./includes
SRCDIR1	=jeu
SRCDIR2	=affichage
SRCDIR3	=IA
SRCDIR4	=hand_eval
SRCDIR5	=langs

CFLAGS	= -I$(HEADDIR)

NAME	= poker

SRC	= $(wildcard $(SRCDIR1)/*.c) \
	  $(wildcard $(SRCDIR2)/*.c) \
	  $(wildcard $(SRCDIR1)/$(SRCDIR3)/*.c) \
	  $(wildcard $(SRCDIR1)/$(SRCDIR4)/*.c) \
	  $(wildcard $(SRCDIR5)/*.c)

OBJ	= $(SRC:.c=.o)

all:	all1

all1:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) -lncurses

clean:	clean1

clean1:
	rm -f $(OBJ)

fclean:	 fclean1

fclean1: clean1
	rm -f $(NAME)

re:	fclean all

install: all1
	rm -f $(OBJ)
