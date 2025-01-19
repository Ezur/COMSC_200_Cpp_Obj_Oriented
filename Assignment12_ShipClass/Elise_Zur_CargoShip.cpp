//  CargoShip.cpp

#include "Elise_Zur_CargoShip.h"

// COMMENT NINE: this constructor creates a CargoShip object.
// it takes in 3 parameters for name, year built, and tonnage.
// it creates a ship object with those characteristics.
CargoShip::CargoShip(string n, string y, int c)
  : Ship(n,y)
{
  capacity = c;
}

// COMMENT TEN: this print function simply outputs the
// name of the ship using the get function which
// is inherited from the Ship class. it also outputs
// the tonnage in tons.
void CargoShip::print()
{
  cout << "Name: " << getName() << endl;
  cout << "Cargo capacity: " << capacity << " tons" << endl;
}
