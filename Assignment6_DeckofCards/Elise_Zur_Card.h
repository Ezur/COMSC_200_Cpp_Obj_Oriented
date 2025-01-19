//  Card.h

#ifndef Card_h
#define Card_h

#include <iostream>
#include <cstring>
using namespace std;

class Card
{
private:
  // COMMENT FOUR
  // i decided to make these variables private because they
  // are only necessary inside the member functions.
  // if they were necessary outside of the class implementation
  // then i would have made them public.
  int face;
  int suit;
  static string facesArray[13];
  static string suitsArray[4];
  
public:
  // COMMENT FIVE
  // the Card() constructor takes in two int paramters,
  // the face and the suit. these values will later be
  // assigned in the class implementation file
  Card(int f, int s);
  string toString() const;
  
};


#endif /* Card_h */
