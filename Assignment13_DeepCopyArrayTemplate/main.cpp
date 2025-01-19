#include <iostream>
#include <stdexcept>
#include <string>
#include "Elise_Zur_Array.h"

int main()
{
  Array<int> intArray(5);
  Array<string> stringArray(5);

  cout << "Enter " << intArray.getSize() << " integer values: \n";
  cin >> intArray;
  cout << "\nThe values in the integer array are: \n" << intArray;
  
  cout << "--------------------------------------------------------------\n";
  
  cout << "\nEnter " << stringArray.getSize() << " string values: \n";
  cin.ignore();
  for (int i = 0; i < stringArray.getSize(); i++)
    getline(cin, stringArray[i]);
  cout << "\nThe values in the string array are: \n" << stringArray;
  
  return 0;
}
