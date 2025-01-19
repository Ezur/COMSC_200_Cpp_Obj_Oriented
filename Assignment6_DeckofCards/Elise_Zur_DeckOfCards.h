//  DeckOfCards.h

#ifndef DeckOfCards_h
#define DeckOfCards_h

#include <iostream>
#include <vector>
using namespace std;

#include "Elise_Zur_Card.h"

class DeckOfCards
{
private:
  // COMMENT SIX
  // here is the vector of cards named deck, below it
  // is the integer currentCard-- this is used as an
  // index to access the deck vector
  vector<Card> deck;
  int currentCard;
  void swap(int, int);
  
public:
  DeckOfCards();
  void shuffle();
  Card dealCard();
  bool moreCards();
  
};


#endif /* DeckOfCards_h */
