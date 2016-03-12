/*
** prototypes.h for PokerPoked in /home/gascio_m/code/PokerPoked
**
** Made by Mathieu GASCIOLLI
** Login   <gascio_m@epitech.net>
**
** Started on  Fri Mar  4 01:47:15 2016 Mathieu GASCIOLLI
** Last update Sat Mar 12 16:27:11 2016 Mathieu GASCIOLLI
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
void	end_of_hand_0();
void	end_of_hand_1();
void	finpartie(int, char**);
void	poker_hand();
void	debut_hand();
void	quitter_prog();
void	malloc_init();
void	free_all();
void	deroulement(int);
int	check_board();
int	get_action_menu();
void	get_action();
void	res_mises();
void	set_players_datas();
int	choose_name();
void	some_inits();
void	change_dealer();
int	rand_carte();
void	init_params();
void	blind();
void	act_fold();
void	act_check();
void	thecheck();
void	act_bet();
void	act_call();
void	act_raise();
char	*get_next_line(const int);
char	**file_names(char **);

#endif
