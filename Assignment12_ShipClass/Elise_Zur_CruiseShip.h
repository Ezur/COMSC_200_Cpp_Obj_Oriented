//  CruiseShip.h

#ifndef Elise_Zur_CruiseShip_h
#define Elise_Zur_CruiseShip_h

#include <iostream>
#include "Elise_Zur_Ship.h"

// COMMENT FIVE: this is the CruiseShip class which
// contains a private data member for number
// of passengers as well as a constructor
// and a virtual function to enact dynamic binding.
class CruiseShip : public Ship
{
private:
  int passengers;
public:
  CruiseShip(string n, string y, int p);
  virtual void print();
};

#endif /* Elise_Zur_CruiseShip_h */
