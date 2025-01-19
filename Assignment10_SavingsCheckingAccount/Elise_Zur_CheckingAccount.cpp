//  CheckingAccount.cpp

#include <iostream>
#include "Elise_Zur_CheckingAccount.h"
using namespace std;

// COMMENT FOUR: CheckingAcount is a derived class inherited from
// the Account class.
CheckingAccount::CheckingAccount(double initialBalance, double fee)
  : Account(initialBalance)
{
  if (fee >= 0.0)
    transactionFee = fee;
  else
    cout << "Transaction fee must be at least 0.0";
}

// COMMENT FIVE: credit() is a redfined function in terms
// of the derived class in order to subtract the transaction
// fee from the account balance whenever money is credited.
// this function invokes Account's credit() function
// to update the acount balance!
void CheckingAccount::credit(double amount)
{
  Account::credit(amount);
  chargeFee();
}

// COMMENT SIX: debit() is a redfined function in terms
// of the derived class in order to subtract the transaction
// fee from the account balance whenever money is debited.
// this function invokes Account's debit() function to
// update the acount balance!
bool CheckingAccount::debit(double amount)
{
  bool working;
  working = Account::debit(amount);
  
  if (working)
  {
    chargeFee();
    return true;
  }
  else
    return false;
}

// COMMENT SEVEN: chargeFee() invokes Account's setBalance() function.
// this function is used inside of the debit() function in order
// to charge the fee only if money is withdrawn.
void CheckingAccount::chargeFee()
{
  Account::setBalance(getBalance() - transactionFee);
  cout << "$" << transactionFee << " transaction fee charged." << endl;
}

