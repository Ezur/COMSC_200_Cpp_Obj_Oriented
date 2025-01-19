//  Card.cpp

#include <iostream>
#include <string>
using namespace std;

#include "Elise_Zur_Card.h"

string Card::facesArray[] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
string Card::suitsArray[] = {"Hearts", "Diamonds", "Clubs", "Spades"};

Card::Card(int f, int s)
{
  face = f;
  suit = s;
}

string Card::toString() const
{
  return facesArray[face] + " of " + suitsArray[suit];
}
