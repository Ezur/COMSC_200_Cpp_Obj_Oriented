// FUELGAUGE.CPP

#include <iostream>
using namespace std;

#include "FuelGauge.h"

const int maxFuel = 15;

FuelGauge::FuelGauge()
{
  currentFuel = 0;
}

int FuelGauge::getFuel() const
{
  return currentFuel;
}

// COMMENT SEVEN
// the function increaseFuel() will perform
// input validation and verify that if the currentFuel amount
// is less than the maximum fuel amount (15 gallons) AND
// the currentFuel amount is greater than or equal to 0,
// then increment the amount of fuel.
void FuelGauge::increaseFuel()
{
  while ((currentFuel < maxFuel) && (currentFuel >= 0))
    ++currentFuel;
}

// COMMENT EIGHT
// the function decreaseFuel() will perform
// input validation and verify that if the currentFuel amount
// if less than or equal to the maximum fuel amount (15 gallons)
// AND the currentFuel amount is greater than 0, then
// decrement the amount of fuel.
// tank if more than 15, then fuel will decrease by 1
void FuelGauge::decreaseFuel()
{
  if ((currentFuel <= maxFuel) && (currentFuel > 0))
    --currentFuel;
}

