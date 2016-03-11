##
## Makefile for PokerPoked in /home/gascio_m/code/PokerPoked
##
## Made by Mathieu GASCIOLLI
## Login   <gascio_m@epitech.net>
##
## Started on  Fri Mar  4 00:35:00 2016 Mathieu GASCIOLLI
## Last update Fri Mar 11 21:37:49 2016 Mathieu GASCIOLLI
##

CC	=gcc

HEADDIR	=./includes
SRCDIR1	=jeu
SRCDIR2	=affichage
SRCDIR3	=IA
SRCDIR4	=hand_eval
SRCDIR5	=confmaker

CFLAGS	= -I$(HEADDIR)

NAME	= poker

NAME2	= preset-maker

SRC	= $(wildcard $(SRCDIR1)/*.c) \
	  $(wildcard $(SRCDIR2)/*.c) \
	  $(wildcard $(SRCDIR1)/$(SRCDIR3)/*.c) \
	  $(wildcard $(SRCDIR1)/$(SRCDIR4)/*.c)

SRC2	= $(wildcard $(SRCDIR5)/*.c)

OBJ	= $(SRC:.c=.o)

OBJ2	= $(SRC2:.c=.o)

all:	$(NAME) $(OBJ2)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) -lncurses

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all1

install: all
	cc -o $(NAME2) $(OBJ2) $(CFLAGS)
	rm -f $(OBJ)
	rm -f $(OBJ2)
