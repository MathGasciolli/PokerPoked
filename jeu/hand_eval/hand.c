/*
** hand.c for PokerPoked in /home/gascio_m/code/PokerPoked/jeu/hand_eval
**
** Made by Mathieu GASCIOLLI
** Login   <gascio_m@epitech.net>
**
** Started on  Wed Mar  9 16:27:42 2016 Mathieu GASCIOLLI
** Last update Fri Mar 11 12:13:29 2016 Mathieu GASCIOLLI
*/

#include "poker.h"

Card	*tmp;

int	nbr_cards(Card *hand)
{
  int	i;

  i = 0;
  while (hand[i].rank)
    i++;
  return (i);
}

int search(Card *hand,int n){
  int i;

  for (i=0;i<nbr_cards(hand);i++){
    if (hand[i].rank==n)
      return 1;
  }

  return 0;
}

int isStraight(Card *hand, int *type){
  int i,a,max,u;
  int	suit;

  a = 15;
  u = 1;
  while (u < nbr_cards(hand))
    {
      max = 3;
      for (i=0;i<nbr_cards(hand);i++)
	if (hand[i].rank > max && hand[i].rank < a)
	  max = hand[i].rank;
      if (search(hand,max-1))
	if (search(hand,max-2))
	  if (search(hand,max-3))
	    if (search(hand,max-4)){
	      *type = max;
	      for (i=0;i<nbr_cards(hand);i++){
		if (hand[i].rank == max)
		  suit = hand[i].suit;
	      }
	      a = 0;
	      i = 0;
	      while (max > *type - 5 && i < nbr_cards(hand))
		{
		  if (hand[i].rank == max && hand[i].suit == suit)
		    a++;
		  i++;
		  max--;
		}
	      if (a == 5)
		return 2;
	      else
		return 1;
	    }
      a = max;
      u++;
    }
  return 0;
}

/*
int isStraightFlush(Card *hand){
  int i;
  int suit;
  int	j;
  int	a;

  a = 0;
  while (a < nbr_cards(hand))
    {
      suit = hand[a].suit;
      j = 0;
      i = 0;
      while (i < nbr_cards(hand) && j < 5)
	{
	  if (hand[i].suit == suit)
	    j++;
	  i++;
	}
      if (j == 5)
	return 1;
      a++;
    }
  return 0;
}
*/

int isRoyal(Card *hand){
  if (search(hand,14))
    return 1;
  return 0;
}

int isFour(Card *hand, int *type){
  int	i;
  int	j;
  int	val;
  int	a;

  a = 0;
  while (hand[a].rank != 0)
    {
      j = 0;
      val = hand[a].rank;
      i = 0;
      while (j < 4 && i < nbr_cards(hand))
	{
	  if (hand[i].rank == val)
	    j++;
	  if (j == 4)
	    {
	      *type = val;
	      return 1;
	    }
	  i++;
	}
      a++;
    }

  return 0;

}

int isThree(Card *hand, int *type){
  int	i;
  int	j;
  int	val;
  int	a;

  a = 0;
  while (hand[a].rank != 0)
    {
      j = 0;
      val = hand[a].rank;
      i = 0;
      while (j < 3 && i < nbr_cards(hand))
	{
	  if (hand[i].rank == val)
	    j++;
	  if (j == 3)
	    {
	      *type = val;
	      return 1;
	    }
	  i++;
	}
      a++;
    }

  return 0;
}

int isFull(Card *hand,int *type, int *secondType){
  int	val1;
  int	val2;
  int	i;
  int	a;
  int	j;

  a = 0;
  if (isThree(hand, &val1))
    {
      *type = val1;
      while (a < nbr_cards(hand))
	{
	    i = 0;
	    j = 0;
	    val2 = hand[a].rank;
	    while (i < nbr_cards(hand))
	      {
		if (hand[i].rank == val2)
		  j++;
		i++;
	      }
	    if (j == 2){
	      *secondType = val2;
	      return 1;
	    }
	    a++;
	}
      return 0;
    }
  return 0;
}

int isPair(Card *hand,int *type){
  int i,j;

  for (i=0;i<nbr_cards(hand)-1;i++)
    for (j=i+1;j<nbr_cards(hand);j++)
      if (hand[i].rank==hand[j].rank){
	*type=hand[i].rank;
	return 1;
      }
  return 0;
}

int isTwoPairs(Card *hand, int *type, int *secondType){
  int i,j;

  for (i=0;i<nbr_cards(hand)-1;i++)
    for (j=i+1;j<nbr_cards(hand);j++)
      if (hand[i].rank==hand[j].rank&&hand[i].rank!=*type){
	if (hand[i].rank<*type){
	  *secondType=hand[i].rank;
	  return 1;
	}
	else{
	  *secondType=*type;
	  *type=hand[i].rank;
	  return 1;
	}

      }

  return 0;
}

int findHighDouble(Card *hand,int *type, int *secondType, int *highCard){
  int i;

  *highCard = 0;
  for (i=0;i<nbr_cards(hand);i++)
    if (hand[i].rank!=(*type)&&hand[i].rank!=(*secondType)){
      if (hand[i].rank > *highCard)
	*highCard = hand[i].rank;
    }
  return 1;
}

int findHighSimple(Card *hand,int *type, int *highCard){
  int i;
  int max = 0;

  for (i=0;i<nbr_cards(hand);i++)
    if (hand[i].rank!=*type&&hand[i].rank>max){
      max = hand[i].rank;
    }

  *highCard = max;
  return 1;
}

int findHigh(Card *hand, int *highCard){
  int i;
  int max = 0;

  for (i=0;i<nbr_cards(hand);i++)
    if (hand[i].rank>max)
      max = hand[i].rank;

  *highCard = max;
  return 1;
}

int findHighSuited(Card *hand, int suit){
  int i;
  int max = 0;

  for (i=0;i<nbr_cards(hand);i++)
    if (hand[i].rank>max && hand[i].suit == suit)
      max = hand[i].rank;

  return max;
}

int isFlush(Card *hand,int *highCard){
  int i;
  int suit;
  int	j;
  int	a;

  a = 0;
  while (a < nbr_cards(hand))
    {
      suit = hand[a].suit;
      j = 0;
      i = 0;
      while (i < nbr_cards(hand) && j < 5)
	{
	  if (hand[i].suit == suit)
	    j++;
	  i++;
	}
      if (j == 5){
	*highCard = findHighSuited(hand,suit);
	return 1;
      }
      a++;
    }
  return 0;
}

int findFlush(Card *hand){
  int i;
  int suit;
  int	j;
  int	a;

  a = 0;
  while (a < nbr_cards(hand))
    {
      suit = hand[a].suit;
      j = 0;
      i = 0;
      while (i < nbr_cards(hand) && j < 5)
	{
	  if (hand[i].suit == suit)
	    j++;
	  i++;
	}
      if (j == 5)
	return a;
      a++;
    }
  return 0;
}

int	find_hand(Card *hand, int *type, int *highCard, int *secondType)
{
  Card	*main;

  if (isFour(hand, type))
    return 8;

  if (isThree(hand,type)){
    if (isFull(hand,type,secondType))
      return 7;
    else
      return 4;
  }

  if (isStraight(hand,type) == 1)
    return 5;
  else if(isStraight(hand,type) == 2){
      if (isRoyal(hand))
	return 10;
      else
	return 9;
    }

  if (isFlush(hand,highCard))
    return 6;

  if (isPair(hand,type)){
    if (isTwoPairs(hand,type,secondType)){
      findHighDouble(hand,type,secondType,highCard);
      return 3;
    }
    else{
      findHighSimple(hand,type,highCard);
      return 2;
    }
  }

  findHigh(hand,highCard);
  return 1;


}

int	findwin_high(Card *hand1, Card *hand2)
{
  int	i = 0,j = 0;
  int	max1 = 2,max2 = 2;
  int	a = 15,b = 15;
  int	k=0;

  while (a == b && k < 5)
    {
      for (i=0;i<nbr_cards(hand1);i++)
	if (hand1[i].rank > max1 && hand1[i].rank < a)
	  max1 = hand1[i].rank;
      a = max1;
      max1 = 2;
      for (j=0;j<nbr_cards(hand2);j++)
	if (hand2[j].rank > max2 && hand2[j].rank < b)
	  max2 = hand2[j].rank;
      b = max2;
      max2 = 2;
      k++;
    }
  if (a == b)
    return 2;
  else if (a < b)
    return 0;
  else if (a > b)
    return 1;
}

int	findwin_high_suited(Card *hand1, Card *hand2)
{
  int	i = 0,j = 0;
  int	max1 = 2,max2 = 2;
  int	a = 15,b = 15;
  int	k=1;
  int	suit;

  suit = findFlush(hand1);
  while (a == b && k < 5)
    {
      for (i=0;i<nbr_cards(hand1);i++)
	if (hand1[i].rank > max1 && hand1[i].rank < a && hand1[i].suit == suit)
	  max1 = hand1[i].rank;
      a = max1;
      max1 = 2;
      for (j=0;j<nbr_cards(hand2);j++)
	if (hand2[j].rank > max2 && hand2[j].rank < b && hand2[j].suit == suit)
	  max2 = hand2[j].rank;
      b = max2;
      max2 = 2;
      k++;
    }
  if (a == b)
    return 2;
  else if (a < b)
    return 0;
  else if (a > b)
    return 1;
}

char    *int_rank(int val)
{
  char  *valeur;

  valeur = malloc(3 * sizeof(char));
  if (val == 14)
    valeur = "Ace";
  else if (val == 11)
    valeur = "Jack";
  else if (val == 12)
    valeur = "Queen";
  else if (val == 13)
    valeur = "King";
  else if (val == 10)
    valeur = "10";
  else
    {
      valeur[0] = val + 48;
      valeur[1] = '\0';
    }
  return (valeur);
}

int	aff_strength(int end)
{
  int	type1,type2;
  int	highCard1,highCard2;
  int	secondType1,secondType2;
  int	points1,points2;

  tmp = malloc(6 * sizeof(Card));

  if (end == 0)
    {
      points1 = find_hand(hand1, &type1, &highCard1, &secondType1);
      points2 = find_hand(hand2, &type2, &highCard2, &secondType2);

      free(tmp);

      move(LINES-2, 3);
      if (points1 == 1)
	printw("High Card (%s)", int_rank(highCard1));
      else if (points1 == 2)
	printw("One Pair (%s)", int_rank(type1));
      else if (points1 == 3)
	printw("Two Pairs (%s, %s)", int_rank(type1), int_rank(secondType1));
      else if (points1 == 4)
	printw("Three of a kind (%s)", int_rank(type1));
      else if (points1 == 5)
	printw("Straight (%s high)", int_rank(type1));
      else if (points1 == 6)
	printw("Flush (%s high)", int_rank(highCard1));
      else if (points1 == 7)
	printw("Full House (%s, %s)", int_rank(type1), int_rank(secondType1));
      else if (points1 == 8)
	printw("Four of a kind (%s)", int_rank(type1));
      else if (points1 == 9)
	printw("Straight Flush (%s high)", int_rank(type1));
      else if (points1 == 10)
	printw("Royal Flush !");

      move(LINES-3, 3);
      if (points2 == 1)
	printw("High Card (%s)", int_rank(highCard2));
      else if (points2 == 2)
	printw("One Pair (%s)", int_rank(type2));
      else if (points2 == 3)
	printw("Two Pairs (%s, %s)", int_rank(type2), int_rank(secondType2));
      else if (points2 == 4)
	printw("Three of a kind (%s)", int_rank(type2));
      else if (points2 == 5)
	printw("Straight (%s high)", int_rank(type2));
      else if (points2 == 6)
	printw("Flush (%s high)", int_rank(highCard2));
      else if (points2 == 7)
	printw("Full House (%s, %s)", int_rank(type2), int_rank(secondType2));
      else if (points2 == 8)
	printw("Four of a kind (%s)", int_rank(type2));
      else if (points2 == 9)
	printw("Straight Flush (%s high)", int_rank(type2));
      else if (points2 == 10)
	printw("Royal Flush !");
    }
  else if (end == 1)
    {
      points1 = find_hand(hand1, &type1, &highCard1, &secondType1);
      points2 = find_hand(hand2, &type2, &highCard2, &secondType2);

      free(tmp);

      if (points1>points2)
	return 1;
      else if (points2>points1)
	return 0;
      else{
	if (points1==1){
	  if (highCard1>highCard2)
	    return 1;
	  else if (highCard1==highCard2)
	    return (findwin_high(hand1,hand2));
	  else
	    return (0);
	}
	if (points1==2){
	  if (type1>type2)
	    return 1;
	  else if (type2>type1)
	    return 0;
	  else{
	    if (highCard1>highCard2)
	      return 1;
	    else if (highCard1==highCard2)
	      return (findwin_high(hand1,hand2));
	    else
	      return 0;
	  }
	}
	if (points1==3){
	  if (type1>type2)
	    return 1;
	  else if (type2>type1)
	    return 0;
	  else {
	    if (secondType1>secondType2)
	      return 1;
	    else if(secondType2>secondType1)
	      return 0;
	    else{
	      if (highCard1>highCard2)
		return 1;
	      else if (highCard1==highCard2)
		return 2;
	      else
		return 0;
	    }
	  }
	}
	if (points1==4){
	  if (type1>type2)
	    return 1;
	  else if (type1==type2)
	    return (findwin_high(hand1,hand2));
	  else
	    return 0;
	}
	if (points1==5){
	  if (type1>type2)
	    return 1;
	  else if (type1==type2)
	    return 2;
	  else
	    return 0;
	}
	if (points1==9){
	  if (type1>type2)
	    return 1;
	  else if (type1==type2)
	    return 2;
	  else
	    return 0;
	}
	if (points1==6){
	  if (highCard1>highCard2)
	    return 1;
	  else if (highCard1==highCard2)
	    return (findwin_high_suited(hand1,hand2));
	  else
	    return 0;
	}
      }
      return 2;
    }
}
