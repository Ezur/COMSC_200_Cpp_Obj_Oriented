//  Account.cpp

#include <iostream>
#include "Elise_Zur_Account.h"
using namespace std;

// COMMENT ONE: I am building an inheritance hierarchy.
// Account is the base class which includes a constructor,
// which will initialize the balance.
Account::Account(double initialBalance)
{
  if (initialBalance >= 0.0)
    balance = initialBalance;
  else
    cout << "Initial balance cannot be negative";
}
// COMMENT TWO: credit() adds an amount to the current balance.
void Account::credit(double amount) {
  balance = balance + amount;
}

// COMMENT THREE: debit() withdraws money from the
// account and ensures the amount is not greater
// than the current balance.
bool Account::debit(double amount)
{
  if (amount > balance)
  {
    cout << "Debit amount exceeded account balance." << endl;
    return false;
  }
  else
  {
    balance = balance - amount;
    return true;
  }
}

void Account::setBalance(double newBalance) {
  balance = newBalance;
}

double Account::getBalance() {
  return balance;
}
