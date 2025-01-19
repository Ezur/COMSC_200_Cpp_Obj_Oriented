//  Ship.cpp

#include "Elise_Zur_Ship.h"

// COMMENT TWO: this constructor for a Ship object
// takes in two parameters for the ship's name
// and the year it was built.
Ship::Ship(string n, string y)
{
  name = n;
  built = y;
}

// COMMENT THREE: this get function is very simple
// and just returns the name of the ship.
string Ship::getName()
{
  return name;
}

// COMMENT FOUR: this get function is very simple
// and just returns the year the ship was built.
string Ship::getBuilt()
{
  return built;
}

void Ship::print()
{
  cout << "Name: " << getName() << "\nYear built: " << getBuilt() << endl;
}
