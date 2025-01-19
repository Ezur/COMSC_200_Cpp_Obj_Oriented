#include <iostream>
#include <string>
using namespace std;

#ifndef Elise_Zur_HeartRates_h
#define Elise_Zur_HeartRates_h

class HeartRates
{
  std::string firstName;
  std::string lastName;
  int monthOfBirth;
  int dayOfBirth;
  int yearOfBirth;
  
public:
  // default constructor
  HeartRates();
  
  // constructor
  HeartRates(std::string first, std::string last,
             int month, int day, int year);
  
  // set/get funcs --> firstName
  void setFirstName(std::string first);
  std::string getFirstName() const;
  
  // set/get funcs --> lastName
  void setLastName(std::string last);
  std::string getLastName() const;
  
  // set/get funcs --> monthOfBirth
  void setMonthOfBirth(int month);
  int getMonthOfBirth() const;
  
  // set/get funcs --> dayOfBirth
  void setDayOfBirth(int day);
  int getDayOfBirth() const;
  
  // set/get funcs --> yearOfBirth
  void setYearOfBirth(int year);
  int getYearOfBirth() const;

  // getAge() --> calculates and returns the person's age (in years)
  int getAge();
  
  // getMaximumHeartRate() --> calcs & returns the max heart rate
  int getMaximumHeartRate(int);
  
  // getTargetHeartRate() --> calc & returns the target heart rate
  int getTargetHeartRate(int, int&, int&);
  
};


#endif /* Elise_Zur_HeartRates_h */
