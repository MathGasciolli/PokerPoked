##
## Makefile for PokerPoked in /home/gascio_m/code/PokerPoked
##
## Made by Mathieu GASCIOLLI
## Login   <gascio_m@epitech.net>
##
## Started on  Fri Mar  4 00:35:00 2016 Mathieu GASCIOLLI
## Last update Mon Mar 14 15:08:54 2016 Mathieu GASCIOLLI
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

all:	$(NAME) $(OBJ2)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) -lncurses

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

install: all
	rm -f $(OBJ)
