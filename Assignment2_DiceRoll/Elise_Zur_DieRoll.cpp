// Class Implementation file -- member function definitions

#include <iostream>
#include <cstdlib>
using namespace std;

#include "Elise_Zur_Die.h"

Die::Die(int numSides) {
  roll();
}

void Die::setSides(int numSides) {
  roll();
  sides = numSides;
}

void Die::roll() {
  value = rand() % 6 + 1;
}

int Die::getSides() {
  return sides;
}

int Die::getValue() {
  return value;
}
