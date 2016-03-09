/*
** carte.h for PokerPoked in /home/gascio_m/code/PokerPoked/includes
**
** Made by Mathieu GASCIOLLI
** Login   <gascio_m@epitech.net>
**
** Started on  Fri Mar  4 00:39:17 2016 Mathieu GASCIOLLI
** Last update Fri Mar  4 00:59:02 2016 Mathieu GASCIOLLI
*/

#ifndef CARTE_H_
#define CARTE_H_


// TYPES DE CARTES
#ifndef PIQUE_
#define PIQUE (1)
#endif
#ifndef CARREAU_
#define CARREAU (2)
#endif
#ifndef TREFLE_
#define TREFLE (3)
#endif
#ifndef COEUR_
#define COEUR (4)
#endif


// LES FIGURES
#ifndef J_
#define J (11)
#endif
#ifndef Q_
#define Q (12)
#endif
#ifndef K_
#define K (13)
#endif
#ifndef A_
#define A (1)
#endif


// SCHEMA D'UNE CARTE
typedef struct s_carte
{
  int	valeur;       // DE 1 A 13
  int	couleur;      // DE 1 A 4
} carte;


#endif
