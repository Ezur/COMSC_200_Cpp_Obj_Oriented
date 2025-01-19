#include <iostream>
#include <string>
using namespace std;

#include "Elise_Zur_HeartRates.h"

// default constructor
HeartRates::HeartRates()
{
  firstName = " ";
  lastName = " ";
  monthOfBirth = 0;
  dayOfBirth = 0;
  yearOfBirth = 0;
}

// constructor initializes the data members
HeartRates::HeartRates(string first, string last,
                       int month, int day, int year)
{
  setFirstName(firstName);
  setLastName(lastName);
  setMonthOfBirth(monthOfBirth);
  setDayOfBirth(dayOfBirth);
  setYearOfBirth(yearOfBirth);
}

// (1) firstName
void HeartRates::setFirstName(std::string first)
{
  firstName = first;
}
std::string HeartRates::getFirstName() const
{
  return firstName;
}

// (2) lastName
void HeartRates::setLastName(std::string last)
{
  lastName = last;
}
std::string HeartRates::getLastName() const
{
  return lastName;
}

// (3) monthOfBirth
void HeartRates::setMonthOfBirth(int month)
{
  monthOfBirth = month;
}
int HeartRates::getMonthOfBirth() const
{
  return monthOfBirth;
}

// (4) dayOfBirth
void HeartRates::setDayOfBirth(int day)
{
  dayOfBirth = day;
}
int HeartRates::getDayOfBirth() const
{
  return dayOfBirth;
}

// (5) yearOfBirth
void HeartRates::setYearOfBirth(int year)
{
  yearOfBirth = year;
}
int HeartRates::getYearOfBirth() const
{
  return yearOfBirth;
}

// (6) getAge()
int HeartRates::getAge()
{
  // local variables
  int currentMonth = 0, currentDay = 0, currentYear = 0;
  
  cin >> currentMonth;
  cin >> currentDay;
  cin >> currentYear;
  
  return currentYear - getYearOfBirth();
}

// (7) getMaximumHeartRate()
int HeartRates::getMaximumHeartRate(int age)
{
  return (220 - age);
}

// (8) getTargetHeartRate()
int HeartRates::getTargetHeartRate(int maxHR, int &minT, int &maxT)
{
  int range = 0;
  minT = ((maxHR * 50) / 100);
  maxT = ((maxHR * 85) / 100);
  
  return range;
}
