##
## Makefile for PokerPoked in /home/gascio_m/code/PokerPoked
##
## Made by Mathieu GASCIOLLI
## Login   <gascio_m@epitech.net>
##
## Started on  Fri Mar  4 00:35:00 2016 Mathieu GASCIOLLI
## Last update Mon Mar 14 22:46:25 2016 Mathieu GASCIOLLI
##

CC	=gcc

HEADDIR	=./includes
SRCDIR1	=jeu
SRCDIR2	=affichage
SRCDIR3	=IA
SRCDIR4	=hand_eval
SRCDIR5	=langs

SRCDIR6	=mysql

BINDIR	= ./jeu/mysql

CFLAGS	= -I$(HEADDIR) \
	 `mysql_config --cflags`

NAME	= poker

SURNAME	= sql

SRC	= $(wildcard $(SRCDIR1)/*.c) \
	  $(wildcard $(SRCDIR2)/*.c) \
	  $(wildcard $(SRCDIR1)/$(SRCDIR3)/*.c) \
	  $(wildcard $(SRCDIR1)/$(SRCDIR4)/*.c) \
	  $(wildcard $(SRCDIR5)/*.c)

SRCS	= $(wildcard $(SRCDIR1)/$(SRCDIR6)/*.c)

OBJ	= $(SRC:.c=.o)

SBJ	= $(SRCS:.c=.o)

all:	all1 all2

all1:	$(NAME)

all2:  $(SURNAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) -lncurses -L/usr/local/mysql/lib -lmysqlclient

$(SURNAME):	$(SBJ)
	$(CC) -o $(BINDIR)/$(SURNAME) $(SBJ) $(CFLAGS) -L/usr/local/mysql/lib -lmysqlclient -lncurses

clean:	clean1 clean2

clean1:
	rm -f $(OBJ)

clean2:
	rm -f $(SBJ)

fclean:	 fclean1 fclean2

fclean1: clean1
	rm -f $(NAME)

fclean2: clean2
	rm -f $(BINDIR)/$(SURNAME)

re:	fclean all

install: all1 all2
	rm -f $(OBJ)
	rm -f $(SBJ)
