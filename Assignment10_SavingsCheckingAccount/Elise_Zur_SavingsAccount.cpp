//  SavingsAccount.cpp

#include "Elise_Zur_SavingsAccount.h"
using namespace std;

// COMMENT EIGHT: SavingsAccount is a derived class inherited from
// the Account class. it inherits the functionality of an Account class,
// as well as includes a member variable to indicate the interest rate.
SavingsAccount::SavingsAccount(double initialBalance, double initialRate)
: Account(initialBalance)
{
  // COMMENT NINE: the constructor for SavingsAccount() performs
  // input validation to make sure that the initial interest
  // rate value, is at least 0.0, if it is not, then an output
  // statement is displayed.
  if (initialRate >= 0.0)
    interestRate = initialRate;
  else
    cout << "Interest rate must be at least 0.0";
}

// COMMENT TEN: calculateInterest() function multiplies the
// interest rate by the account balance. we use the account
// balance by creating a variable which will hold the value
// returned from getBalance().
double SavingsAccount::calculateInterest()
{
  double b = getBalance();
  return (b * interestRate);
}
