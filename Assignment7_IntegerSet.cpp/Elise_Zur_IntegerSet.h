#include <iostream>
#include <vector>
using namespace std;

#ifndef Elise_Zur_IntegerSet_h
#define Elise_Zur_IntegerSet_h

class IntegerSet
{
  
public:
  IntegerSet();
  IntegerSet(int arr[], int size);
  IntegerSet unionOfSets(IntegerSet b);
  IntegerSet intersectionOfSets(IntegerSet b);
  void insertElement(int k);
  void deleteElement(int k);
  void printSet();
  bool isEqualTo(const IntegerSet&);
  void inputSet();
  void emptySet();
  
private:
  int set[101];
  int limit;

};

#endif /* Elise_Zur_IntegerSet_h */
