//  CheckingAccount.h

#ifndef Elise_Zur_CheckingAccount_h
#define Elise_Zur_CheckingAccount_h

#include <iostream>
#include "Elise_Zur_Account.h"

class CheckingAccount:public Account
{
public:
  CheckingAccount(double initialBalance, double fee);
  void credit(double amount);
  bool debit(double amount);
private:
  double transactionFee;
  void chargeFee();
};


#endif /* Elise_Zur_CheckingAccount_h */
