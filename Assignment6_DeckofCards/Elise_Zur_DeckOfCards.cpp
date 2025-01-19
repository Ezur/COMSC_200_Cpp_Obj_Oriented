//  DeckOfCards.cpp

#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>
using namespace std;

#include "Elise_Zur_Card.h"
#include "Elise_Zur_DeckOfCards.h"

int currentCard = 0;

// COMMENT SEVEN
// this is the constructor for DeckOfCards(), this
// allows us to create new DeckOfCards objects
// and in this situation, we will create a
// DeckOfCards made up of Card objects.
DeckOfCards::DeckOfCards()
{
  // COMMENT EIGHT
  // because we are using a vector, instead of
  // simply assigning the values, we are
  // using the operator .push_back() to
  // push the value into the vector.
  for (int f = 0; f < 13; f++) // face
    for (int s = 0; s < 4; s++)  // suit
    {
      Card c(f,s);
      deck.push_back(c);
    }
  currentCard = 0;
}

// COMMENT NINE
// the function shuffle() calculates two random
// card numbers and swaps them. this acts as a
// shuffle simulation and i used a swap() function
// to switch the card's values.
void DeckOfCards::shuffle()
{
  srand(unsigned(time(0)));
  for (int i = 0; i < 52; i++)
  {
    int random = rand() % 51;
    int random2 = rand() % 51;
    swap(random,random2);
  }
  currentCard = 0;
}

void DeckOfCards::swap(int a, int b)
{
  Card temp = deck[b];
  deck[b] = deck[a];
  deck[a] = temp;
}

Card DeckOfCards::dealCard()
{
  return deck[currentCard++];
}

// COMMENT TEN
// moreCards() is a function that allows us to check
// if we have dealt out all of the cards yet. in main
// we can use this in a while loop to continue
// running the program until there are no more cards left.
bool DeckOfCards::moreCards()
{
  if (currentCard < 52)
    return true;
  return false;
}
