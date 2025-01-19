// APPLICATION PROGRAM.CPP

#include <iostream>
using namespace std;

#include "FuelGauge.h"
#include "Odometer.h"

int main()
{
  // comments 1-6 --> 200_assign5.cpp
  // comments 7-8 --> FuelGauge.cpp
  // comments 9-10 --> Odometer.cpp
  
  // COMMENT ONE
  // we create two objects-- one FuelGauge object named fuelTank
  // and one Odometer object named meter. we are utilizing the
  // different constructors here to create objects and set them to
  // initial values.
  
  FuelGauge fuelTank;
  
  // COMMENT TWO
  // inside the Odometer constructor, the meter object is
  // initializing the beginning starting amount which is
  // zero. we start with an empty tank because this allows
  // the user to specify how much gas they want to start at.
  
  // COMMENT THREE
  // when we pass the fuelTank into the Odometer object,
  // we are not storing a copy of the FuelGauge object,
  // but rather it is manipulating the object from
  // main. we do this by creating a member variable
  // that is a reference to a FuelGauge object
  // see Odometer.h for reference
  Odometer meter(0, fuelTank);
  
  // COMMENT FOUR
  // this is the starting point of the program where this
  // function will increase the fuelTank up to 15 gallons.
  // in this case, according to the validation, i
  // set it to a full tank of gas which is 15 gallons.
  // it is useful to utilize this
  // function because it includes input validation
  // to ensure that it will stop increasing the gas
  // when the currentFuel is less than 15 and greater
  // than 0!
  fuelTank.increaseFuel();
  
  // COMMENT FIVE
  // inside this while loop, we test to make sure the
  // amount of fuel is any number greater than 0. inside
  // the FuelGauge header, we specify the max amount
  // of fuel (15 gallons). due to that specification,
  // we can utilize the fuel is greater than 0 to
  // run until the fuelTank does not have any more gas left
  // (in this case- the fuelTank's currentFuel variable.
  while (fuelTank.getFuel() > 0)
  {
    // COMMENT SIX
    // inside the while loop, the function will output the mileage
    // on the meter and amount of fuel inside the fuelTank.
    // we increase the mileage here and like a chain reaction,
    // when the mileage increases, the fuel decreases.
    meter.increaseMileage();
    cout << "Mileage: " << meter.getMileage() << endl;
    cout << "Fuel Level: " << fuelTank.getFuel() << " gallons" << endl;
    cout << "-----------------------------------------------" << endl;
  }
  
}
