//  Ship.hpp

#ifndef Elise_Zur_Ship_h
#define Elise_Zur_Ship_h

#include <iostream>
#include <string>
using namespace std;

// COMMENT ONE: this is the Ship class which
// contains private data members for name and
// year built as well as a constructor, get
// functions and a virtual function to enact
// dynamic binding.
class Ship
{
private:
  string name;
  string built;
public:
  Ship(string n, string y);
  string getName();
  string getBuilt();
  virtual void print();
  
};

#endif /* Elise_Zur_Ship_h */
