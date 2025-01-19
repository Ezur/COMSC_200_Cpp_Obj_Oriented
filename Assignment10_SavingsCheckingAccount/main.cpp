#include <iostream>
#include <iomanip>
#include "Elise_Zur_Account.h" // Account class definition
#include "Elise_Zur_SavingsAccount.h" // SavingsAccount class definition
#include "Elise_Zur_CheckingAccount.h" // CheckingAccount class definition
using namespace std;

int main()
{
   Account account1( 6.8 ); // create Account object
   SavingsAccount account2( 85.2, .05 ); // create SavingsAccount object
   CheckingAccount account3( 164.0, 2.0 ); // create CheckingAccount object

   cout << fixed << setprecision( 2 );

   // display initial balance of each object
   cout << "account1 balance: $" << account1.getBalance() << endl;
   cout << "account2 balance: $" << account2.getBalance() << endl;
   cout << "account3 balance: $" << account3.getBalance() << endl;

   cout << "\nAttempting to debit $140.20 from account1." << endl;
   account1.debit( 140.2 ); // try to debit $25.00 from account1
   cout << "\nAttempting to debit $27.00 from account2." << endl;
   account2.debit( 27.0 ); // try to debit $30.00 from account2
   cout << "\nAttempting to debit $44.60 from account3." << endl;
   account3.debit( 44.6 ); // try to debit $40.00 from account3

   // display balances
   cout << "\naccount1 balance: $" << account1.getBalance() << endl;
   cout << "account2 balance: $" << account2.getBalance() << endl;
   cout << "account3 balance: $" << account3.getBalance() << endl;

   cout << "\nCrediting $139.20 to account1." << endl;
   account1.credit( 139.2 ); // credit $40.00 to account1
   cout << "\nCrediting $25.70 to account2." << endl;
   account2.credit( 25.7 ); // credit $65.00 to account2
   cout << "\nCrediting $194.10 to account3." << endl;
   account3.credit( 194.1 ); // credit $20.00 to account3

   // display balances
   cout << "\naccount1 balance: $" << account1.getBalance() << endl;
   cout << "account2 balance: $" << account2.getBalance() << endl;
   cout << "account3 balance: $" << account3.getBalance() << endl;

   // add interest to SavingsAccount object account2
   double interestEarned = account2.calculateInterest();
   cout << "\nAdding $" << interestEarned << " interest to account2."
      << endl;
   account2.credit( interestEarned );

   cout << "\nNew account2 balance: $" << account2.getBalance() << endl;

//   system("PAUSE");
   return 0;
   
}
