#include <iostream>
#include <string>
using namespace std;

#include "Elise_Zur_HeartRates.h"

void inputName(HeartRates&);
void inputBirth(HeartRates&);
void outputName_Birth(HeartRates);
int getAge_(HeartRates);

int main()
{
  int age, maxHR;
  int minTarget, maxTarget;
  
  HeartRates heart;
  
  // COMMENT ONE
  // the program begins by having the user enter their first and
  // last name into the console. the function inputName() will
  // individually receive each variable and then fill it based
  // off of which object field needs to be filled.
  cout << "Please enter first and last name (separated by spaces): " << endl;
  inputName(heart);

  // COMMENT TWO
  // the program will next ask for the user to input their birth
  // date and again will individually receive and put the data
  // inside the correct object field. inside the function
  // inputBirth() will have local variables for month, day, and year.
  cout << "Please enter month, day, and year of birth (separated by spaces): " << endl;
  inputBirth(heart);
  
  // COMMENT THREE
  // the program will next use the function outputName_Birth() to
  // output the user's name and birthdate that was previously entered
  // above. the data will be past on to the next functions.
  outputName_Birth(heart);

  cout << "Please enter today's month, day, and year:" << endl;
  
  // COMMENT FOUR
  // instead of using individual one-liner functions to do the
  // actions of getting the age, max heart rate, and target heart
  // rate-- i chose to use the natural form of calling the
  // object's field to directly receive the data value and
  // then store it in a temporary variable that can be used
  // to output the data and later pass by value to other functions.
  age = heart.getAge();
  cout << "Age: " << age << endl;
  
  maxHR = heart.getMaximumHeartRate(age);
  cout << "Maximum Heart Rate: " << heart.getMaximumHeartRate(age) << endl;

  heart.getTargetHeartRate(maxHR, minTarget, maxTarget);
  cout << "Target Heart Rate: " << minTarget << '-' << maxTarget << endl;
}

// COMMENT FIVE
// inputName() receives the object heart by reference
// in order to change it's value and ensure the
// value will remain changed back up in main.
void inputName(HeartRates &heart)
{
  // COMMENT SIX
  // the function access heart's member functions and
  // receives variables for entering first and last name
  // and then sets those fields of the object with the
  // string inputs.
  string firstName, lastName;
  cin >> firstName;
  heart.setFirstName(firstName);
  cin >> lastName;
  heart.setLastName(lastName);
}

// COMMENT SEVEN
// inputBirth() receives the object heart by reference
// to ensure that the values we are setting for the
// person's birthday, will remain the same in main.
void inputBirth(HeartRates &heart)
{
  // COMMENT EIGHT
  // the function will access the heart's member functions
  // and will use 'set_OfBirth' according to month, day, or
  // year. the fields will be filled with the input.
  int month, day, year;
  cin >> month;
  heart.setMonthOfBirth(month);
  cin >> day;
  heart.setDayOfBirth(day);
  cin >> year;
  heart.setYearOfBirth(year);
}

// COMMENT NINE
// outputName_Birth() receives the object heart, this time
// passing by value because it is only outputing the
// object's values, and not changing anything.
void outputName_Birth(HeartRates heart)
{
  // COMMENT TEN
  // this function outputs the already filled object fields
  // and directly uses cout statements to access the data.
  // this is a more concise way of outputting the data
  // instead of creating variables to temporary hold the
  // data.
  cout << "\nFirst Name: " << heart.getFirstName() << endl;
  cout << "Last Name: " << heart.getLastName() << endl << endl;
  cout << "Date of Birth: " << heart.getMonthOfBirth() << '/'
       << heart.getDayOfBirth() << '/' << heart.getYearOfBirth() << endl;
}
