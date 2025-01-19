//  CruiseShip.cpp

#include "Elise_Zur_CruiseShip.h"
#include "Elise_Zur_Ship.h"

// COMMENT SIX: this constructor creates a CruiseShip object.
// it takes in 3 parameters for name, year built, and # passengers.
// it creates a ship object with those characteristics.
CruiseShip::CruiseShip(string n, string y, int p)
  : Ship(n,y)
{
  passengers = p;
}

// COMMENT SEVEN: this print function simply outputs the
// name of the ship using the get function which
// is inherited from the Ship class. it also outputs
// the number of passengers. 
void CruiseShip::print()
{
  cout << "Name: " << getName() << endl;
  cout << "Maximum passengers: " << passengers << endl;
}
