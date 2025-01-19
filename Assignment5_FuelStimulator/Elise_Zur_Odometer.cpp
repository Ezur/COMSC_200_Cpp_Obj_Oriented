// ODOMETER.CPP

#include <iostream>
using namespace std;

#include "Odometer.h"

const int maxMileage = 999999;

// COMMENT NINE
// the Odometer constructor takes in two parameters--
// one to initialize the fg variable with the value
// of fuelg and one to initialize the startingAmount
// with the value passed in through startingAmount.
// this is useful as we can specify at what amount
// of gas we want to start at.
Odometer::Odometer(int startingAmount, FuelGauge& fuelg)
    :fg{fuelg}, mileage{startingAmount}
{

}

int Odometer::getMileage() const
{
  return mileage;
}

// COMMENT TEN
// in the function increaseMileage() the program will
// enter into two if statements. this is where
// the mileage incrememnts until the car runs out of
// fuel. when the mileage is less than the maxMileage
// (999,999 miles) the mileage will continue increasing.
// if the mileage is NOT less then the max, the mileage
// is set to zero. also-- if the mileage is greater than
// zero and if the mileage can return zero after the
// modulus operator, then the fuel will be decreased
// and then mileage will ultimately be returned.
int Odometer::increaseMileage()
{
  if (mileage < maxMileage)
    ++mileage;
  else
    mileage = 0;
  
  if (mileage > 0 && mileage % 24 == 0)
    fg.decreaseFuel();
  return mileage;
  
}
