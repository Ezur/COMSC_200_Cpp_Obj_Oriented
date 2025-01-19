// class specification file

#include <string>

#ifndef Elise_Zur_Coin_h
#define Elise_Zur_Coin_h

class Coin
{
public:
  Coin(); // constructor
  void toss();
  std::string getSideUp();
  
private:
  std::string sideUp; // stores either "heads" or "tails"
};

#endif /* Elise_Zur_Coin_h */
