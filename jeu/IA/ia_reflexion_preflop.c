/*
** ia_reflexion_preflop.c for PokerPoked in /home/gascio_m/code/PokerPoked/jeu/IA
**
** Made by Mathieu GASCIOLLI
** Login   <gascio_m@epitech.net>
**
** Started on  Tue Mar  8 19:09:46 2016 Mathieu GASCIOLLI
** Last update Sat Mar 12 17:15:26 2016 Mathieu GASCIOLLI
*/

#include "poker.h"

int	ia_preflop(int i)
{
  if (i > 2)
    {
      if (player.mise > jeu.blind && player.mise > ia.mise) // RAISE PREFLOP
	{
	  if (player.mise < ia.argent/4) // MISE INFERIEURE AU QUART DU STACK
	    {
	      if (IA[0].valeur == IA[1].valeur) // POCKET PAIRE
		return (2);
	      else if (color_suite() == 1)
		return (2); // MEME COULEUR ET POSSIBILITE DE SUITE
	      else if (figure_et_high() == 1)
		return (2); // UNE FIGURE ET 2ND CARTE > 7
	      else
		return (0);
	    }
	  else if (player.mise >= ia.argent/4)
	    {
	      if (highpair() == 1)
		return (3); // PAIRE > 9
	      else if (suited_connector() == 1)
		return (3); // SUITED CONNECTOR > 9
	      else if (as_figure() == 1)
		return (3); // AS ET FIGURE
	      else
		return (0);
	    }
	}
      else if (player.mise > ia.mise && player.mise == jeu.blind) // MISE BLIND
	{
	  if ((IA[0].valeur > 1 && IA[0].valeur < 6) && (IA[1].valeur > 1 && IA[1].valeur < 6) && IA[0].valeur != IA[1].valeur && IA[0].couleur != IA[1].couleur && ia.mise == 0)
	    return (0); // JEU POURRI NUL A CHIER
	  else if (highpair() == 1 || as_figure() == 1)
	    return (3*player.mise);
	  else
	    return (2);
	}
      else if (player.mise == ia.mise && ia.mise == jeu.blind)
	{
	  if (highpair() == 1 || as_figure() == 1)
	    return (3*ia.mise);
	  else
	    return (1);
	}
      else if (player.mise == ia.mise && ia.mise > jeu.blind)
	return (1);
    }
  else if (i == 2)
    {
      if (player.mise > jeu.blind && player.mise > ia.mise) // RAISE PREFLOP
	{
	  if (player.mise < ia.argent/4) // MISE INFERIEURE AU QUART DU STACK
	    {
	      if (IA[0].valeur == IA[1].valeur) // POCKET PAIRE
		return (3*player.mise);
	      else if (color_suite() == 1)
		return (3*player.mise); // MEME COULEUR ET POSSIBILITE DE SUITE
	      else if (figure_et_high() == 1)
		return (2); // UNE FIGURE ET 2ND CARTE > 7
	      else
		return (2);
	    }
	  else if (player.mise >= ia.argent/4)
	    {
	      if (highpair() == 1)
		return (2); // PAIRE > 9
	      else if (suited_connector() == 1)
		return (2); // SUITED CONNECTOR > 9
	      else if (as_figure() == 1)
		return (2); // AS ET FIGURE
	      else
		return (0);
	    }
	}
      else if (player.mise > ia.mise && player.mise == jeu.blind) // MISE BLIND
	{
	  if ((IA[0].valeur > 1 && IA[0].valeur < 6) && (IA[1].valeur > 1 && IA[1].valeur < 6) && IA[0].valeur != IA[1].valeur && IA[0].couleur != IA[1].couleur && ia.mise == 0)
	    return (2); // JEU POURRI NUL A CHIER
	  else if (highpair() == 1 || as_figure() == 1)
	    return (2);
	  else
	    return (2);
	}
      else if (player.mise == ia.mise && ia.mise == jeu.blind)
	{
	  if (highpair() == 1 || as_figure() == 1)
	    return (1);
	  else
	    return (1);
	}
      else if (player.mise == ia.mise && ia.mise > jeu.blind)
	return (1);
    }
  else if (i < 2)
    {
      if (player.mise > jeu.blind && player.mise > ia.mise) // RAISE PREFLOP
	{
	  if (player.mise < ia.argent/4) // MISE INFERIEURE AU QUART DU STACK
	    {
	      if (IA[0].valeur == IA[1].valeur) // POCKET PAIRE
		return (3);
	      else if (color_suite() == 1)
		return (2); // MEME COULEUR ET POSSIBILITE DE SUITE
	      else if (figure_et_high() == 1)
		return (2); // UNE FIGURE ET 2ND CARTE > 7
	      else
		return (0);
	    }
	  else if (player.mise >= ia.argent/4)
	    {
	      if (highpair() == 1)
		return (3); // PAIRE > 9
	      else if (suited_connector() == 1)
		return (2); // SUITED CONNECTOR > 9
	      else if (as_figure() == 1)
		return (2); // AS ET FIGURE
	      else
		return (0);
	    }
	}
      else if (player.mise > ia.mise && player.mise == jeu.blind) // MISE BLIND
	{
	  if ((IA[0].valeur > 1 && IA[0].valeur < 6) && (IA[1].valeur > 1 && IA[1].valeur < 6) && IA[0].valeur != IA[1].valeur && IA[0].couleur != IA[1].couleur && ia.mise == 0)
	    return (2); // JEU POURRI NUL A CHIER
	  else if (highpair() == 1 || as_figure() == 1)
	    return (3*player.mise);
	  else
	    return (2);
	}
      else if (player.mise == ia.mise && ia.mise == jeu.blind)
	{
	  if (highpair() == 1 || as_figure() == 1)
	    return (1);
	  else
	    return (1);
	}
      else if (player.mise == ia.mise && ia.mise > jeu.blind)
	return (1);
    }
}
