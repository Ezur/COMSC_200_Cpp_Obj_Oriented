//  Account.h

#ifndef Elise_Zur_Account_h
#define Elise_Zur_Account_h

#include <iostream>

class Account
{
public:
  Account(double initialBalance);
  void credit(double amount);
  bool debit(double amount);
  void setBalance(double newBalance);
  double getBalance();
private:
  double balance;
};

#endif /* Elise_Zur_Account_h */
