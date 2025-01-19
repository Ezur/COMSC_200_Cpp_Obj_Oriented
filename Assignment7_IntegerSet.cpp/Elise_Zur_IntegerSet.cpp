#include <iostream>
#include <vector>
#include "Elise_Zur_IntegerSet.h"
using namespace std;

//const int limit = 101;

IntegerSet::IntegerSet()
:limit{101}
{
    for(int i = 0; i < limit; i++)
        set[i] = 0;
}

// COMMENT ONE
// this constructor is important as it is used
// in one of the last lines of code in the program.
// it is used to be able to create a new set
// after inputting an already initialized array,
// intArray[]. the function will make sure
// to only use valid numbers in the set.
IntegerSet::IntegerSet(int intArray[], int size)
  : IntegerSet()
{
  for (int i = 0; i < size; i++)
  {
    if (intArray[i] >= -1 && intArray[i] <= limit)
      set[intArray[i]] = 1;
    else
      cout << "Invalid insert attempted!" << endl;
  }
}

// COMMENT TWO
// this member function creates a 3rd set.
// it is the union of 2 pre-existing sets
// the union will include elements set to true in
// either or both existing sets
// and an element set to false in both sets
IntegerSet IntegerSet::unionOfSets(IntegerSet b)
{
  IntegerSet temp;
  temp.emptySet();
  
  for (int i = 0; i < limit; i++)
  {
    if (this->set[i] == 1 || b.set[i] == 1)
      temp.set[i] = 1;
  }
    return temp;
}

// COMMENT THREE
// this function creates a 3rd set.
// it is the intersection of 2 pre-existing sets
// the intersection will include elements that are
// set to false in either or both existing sets
// and elements set to true in both sets
IntegerSet IntegerSet::intersectionOfSets(IntegerSet b)
{
  IntegerSet temp;
  temp.emptySet();

  for(int i = 0; i < limit; i++)
  {
    if(this->set[i] == 1 && b.set[i] == 1)
      temp.set[i] = 1;
  }
    return temp;
}

// COMMENT FOUR
// this function will receieve an integer, k, to
// be placed into the set. this is done by
// placing k as the index of set[] and
// setting it's value to 1, or true.
void IntegerSet::insertElement(int k)
{
  if (k <= 0 || k >= 100)
    cout << "Invalid Input" << endl;
  else
    set[k] = 1;
}

// COMMENT FIVE
// this function will receieve an integer, m, to
// be removed from the set. this is done by
// placing m as the index of set[] and
// setting it's value to 0, or false.
void IntegerSet::deleteElement(int m)
{
  if (m < 0 || m > 100)
    cout << "Invalid Input" << endl;
  else
    set[m] = 0;
}

// COMMENT SIX
// this function will print the set in a list format
// each number is separated by spaces
// the number is only printed if it's position in
// the vector is set to true, or 1.
// in the case that the set is empty, it will print a
// null operator (--)
void IntegerSet::printSet()
{
  bool isEmpty = true;
  cout << "{   ";
  for(int i = 0; i < limit; i++)
  {
    if(set[i] == 1)
    {
      cout << i << "   ";
      isEmpty = false;
    }
  }
  if (isEmpty)
    cout << " -- ";
  cout << "}";
  cout << endl;

}

// COMMENT SEVEN
// this function will decide if the two sets are
// equal or not. in order to do this, we need
// to have a for loop that checks if each sets
// value is the same at each index. if the sets
// are not equal to each other, then the function
// will return false. if they are equal, it will return
// true.
bool IntegerSet::isEqualTo(const IntegerSet &r)
{
   for(int i = 0; i < limit; i++)
     if(set[i] != r.set[i])
         return false;
   return true;
}

// COMMENT EIGHT
// the function inputSet() will allow us to enter
// values into a set. it is important that the
// output specifies what value the user must enter
// to finalize the set values.
void IntegerSet::inputSet()
{
  int num;
  
  do
  {
    cout << "Enter an element (-1 to end): ";
    cin >> num;
    
    // COMMENT NINE
    // in the case that the user has input that
    // is out of bounds, the program will
    // output that it was an Invalid Argument
    // and the program will ignore the input
    // from entering the set.
    if (num < -1 || num >= limit)
      cout << "Invalid Argument" << endl;
    else if (num != -1)
      set[num] = 1;
    
  } while (num != -1);
    cout << "Entry complete" << endl;
}

// COMMENT TEN
// this function was added on after I realized
// that it was important to set the set
// to have all false values before using it.
// inside this function, there is a for loop
// that initializes each position to 0, or false.
void IntegerSet::emptySet()
{
  for (int i = 0; i < limit; i++)
    set[i] = 0;
}

