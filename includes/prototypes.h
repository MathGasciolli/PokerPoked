/*
** prototypes.h for PokerPoked in /home/gascio_m/code/PokerPoked
**
** Made by Mathieu GASCIOLLI
** Login   <gascio_m@epitech.net>
**
** Started on  Fri Mar  4 01:47:15 2016 Mathieu GASCIOLLI
** Last update Tue Mar  8 21:05:17 2016 Mathieu GASCIOLLI
*/

#ifndef PROTOTYPES_H_
#define PROTOTYPES_H_

int	main(int, char**);
char	*interpreteur_valeur(carte);
char	*interpreteur_couleur(carte);
carte	*init_paquet();
carte	*init_board();
void	distrib_cartes_debut();
void	thecheck();

#endif
