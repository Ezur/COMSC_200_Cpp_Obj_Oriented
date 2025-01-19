//  CargoShip.h

#ifndef Elise_Zur_CargoShip_h
#define Elise_Zur_CargoShip_h

#include <iostream>
#include "Elise_Zur_Ship.h"

// COMMENT EIGHT: this is the CargoShip class which
// contains one private data member for capacity,
// as well as a constructor and a virtual function
// to enact dynamic binding.
class CargoShip : public Ship
{
private:
  int capacity;
public:
  CargoShip(string n, string y, int c);
  virtual void print();
};

#endif /* Elise_Zur_CargoShip_h */
