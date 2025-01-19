// Game logic

#include <iostream>
#include <cstdlib>
#include "Elise_Zur_Coin.h"
#include <iomanip>
using namespace std;

double tossCoins (double&, Coin, Coin, Coin);
void results (double, double);

int main()
{
  srand(time(0));

  // COMMENT ONE
  // variable declaration includes a round counter var and
  // two double vars to keep track of both player and
  // computer's balance throughout the game.
  // three Coin objects are created; quarter, dime, & nickel.
  // we only need three because both the player & computer toss
  // the same coins.
  int round = 1;
  double pBalance = 0, cBalance = 0;
  Coin quarter, dime, nickel;
  
  cout << fixed << setprecision(2) << endl;
  cout << "Your starting balance: $" << pBalance << endl;
  cout << "The computer's starting balance: $" << cBalance << endl;

  while (true)
  {
    // COMMENT TWO
    // tossCoins() function will receive either the player
    // or computer's balance and the three coins.
    tossCoins(pBalance, quarter, dime, nickel);
    tossCoins(cBalance, quarter, dime, nickel);
    
    // COMMENT THREE
    // the output statements print to show the user the
    // number of rounds the game went through until one
    // of the participant's balance == 1
    cout << "\nYour balance after round " << round << ": $" << pBalance << endl;
    cout << "The computer's balance after round " << round << ": $" << cBalance << endl;
    
    // COMMENT FOUR
    // if either participants values are greater than
    // or equal to 1, the game will stop. if that condition
    // is false, the round value will increment and the
    // while loop will continue running until this condition
    // is met.
    if (pBalance >= 1 || cBalance >= 1)
      break;
    
    round++;
    
  }
  
  // COMMENT FIVE
  // once the program has identified that the condition above
  // has been met, the program will break out of the while loop
  // and output the ending results
  
  // COMMENT SIX
  // the output statements will print to show the player their
  // score and the computer's score. this comparison will decide
  // who has won the game below.
  cout << "\nYour ending balance: $" << pBalance << endl;
  cout << "The computer's ending balance: $" << cBalance << endl;
  cout << endl;
  
  // COMMENT SEVEN
  // the results() function receives two parameters-- the player's
  // balance and the computer's balance. this allows the function
  // to compare scores and decide which participant won/lost/tied.
  results(pBalance, cBalance);
}

// COMMENT EIGHT
// tossCoins() function receives a participant's balance and
// the three coins that will be flipped. this allows the program
// to be reused for as many participants as needed.
double tossCoins (double &balance, Coin q, Coin d, Coin n)
{
  q.toss();
  d.toss();
  n.toss();
  
  // COMMENT NINE
  //the if/else if/else if statement below decides that if
  // the coins member function getSideUp() is heads,
  // then the amount will be added to the balance.
  // if getSideUp() results in tails, the balance
  // will not be added and ignored.
  if (q.getSideUp() == "heads")
    balance += 0.25;
  else if (d.getSideUp() == "heads")
    balance += 0.10;
  else if (n.getSideUp() == "heads")
    balance += 0.05;
  
  return balance;
}

// COMMENT TEN
// the results() function receives two parameters--
// the player's balance and the computer's balance.
// here they are labeled as just player and computer.
// below are several conditions that will decide who
// has won/lost or if the two participants have tied. 
void results(double player, double computer)
{
  if (player < 1 && computer >= 1) // less than 1
    cout << "Sorry! The computer won." << endl;
  else if (computer < 1 && player >= 1)
    cout << "Congratulations! You won." << endl;
  else if (player > 1 && computer > 1 && player > computer) // more than 1
    cout << "Sorry! The computer won." << endl;
  else if (computer > 1 && player > 1 && computer > player)
    cout << "Congratulations! You won." << endl;
  else if ((player < 1 || player > 1) && computer == 1)   // playerA or B = 1
    cout << "Sorry! The computer won." << endl;
  else if ((computer < 1 || computer > 1) && player == 1)
    cout << "Congratulations! You won." << endl;
  else if ((computer > 1) == (player > 1))
    cout << "Tie! Nobody wins." << endl;
  else if (computer < 1 && player < 1)
    cout << "Tie! Nobody wins." << endl;
  
  cout << endl;
}
