// Die header file

#ifndef Elise_Zur_Die.h
#define Elise_Zur_Die.h

class Die
{
  int sides; // number of sides on the die
  int value; // the die's value
  
public:
  Die(int);
  void setSides(int);
  void roll();
  int getSides();
  int getValue();
    
};

#endif /* Elise_Zur_Die.h */
