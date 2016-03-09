##
## Makefile for PokerPoked in /home/gascio_m/code/PokerPoked
##
## Made by Mathieu GASCIOLLI
## Login   <gascio_m@epitech.net>
##
## Started on  Fri Mar  4 00:35:00 2016 Mathieu GASCIOLLI
## Last update Tue Mar  8 19:11:12 2016 Mathieu GASCIOLLI
##

SRC	= jeu/*.c \
	  affichage/*.c \
	  jeu/IA/*.c

NAME	= poker

all:	$(NAME)

$(NAME): fclean
	cc -o $(NAME) $(SRC) -lncurses -I./includes

fclean:
	rm -f $(NAME)
