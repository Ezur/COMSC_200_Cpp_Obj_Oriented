//  main.cpp

#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

#include "Elise_Zur_DeckOfCards.h"

int main()
{
  DeckOfCards deck;
  int cardNum = 0;
  
  deck.shuffle();
  
  // COMMENT ONE
  // while the deck has less than 52 cards, the loop
  // will continue to print out the card names
  while (deck.moreCards())
  {
    // COMMENT TWO
    // this var cardNum is used to output the cards in
    // a proper format-- after ever 4 cards, the
    // output restarts a new line
    if (cardNum == 4)
    {
      cardNum = 0;
      cout << endl;
    }
    cardNum++;
    // COMMENT THREE
    // the dealCard() function must be followed by the
    // toString() function in order to properly print out
    // the cards in the correct format, this allows
    // us to streamline the process of output
    cout << left << setw(20) << deck.dealCard().toString() << " ";
  }
  cout << endl << endl;

  return 0;
}
