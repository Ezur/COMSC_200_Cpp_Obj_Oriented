// class implementation file

#include <iostream>
#include <cstdlib>
#include "Elise_Zur_Coin.h"
using namespace std;

// constructor
Coin::Coin()
{
  toss();
}

void Coin::toss()
{
  int side = rand() % 2;
  if (side == 0)
    sideUp = "heads";
  else
    sideUp = "tails";
}

string Coin::getSideUp()
{
  return sideUp;
}
