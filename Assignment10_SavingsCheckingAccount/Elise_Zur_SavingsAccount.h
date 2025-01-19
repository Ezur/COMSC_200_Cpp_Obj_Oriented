//  SavingsAccount.h

#ifndef Elise_Zur_SavingsAccount_h
#define Elise_Zur_SavingsAccount_h

#include <iostream>
#include "Elise_Zur_Account.h"

class SavingsAccount:public Account
{
public:
  SavingsAccount(double intialBalance, double initialRate);
  double calculateInterest();
private:
  double interestRate;
};

#endif /* Elise_Zur_SavingsAccount_h */
