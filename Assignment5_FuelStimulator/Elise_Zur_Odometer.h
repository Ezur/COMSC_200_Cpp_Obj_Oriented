// ODOMETER.H

#ifndef Odometer_h
#define Odometer_h

#include "FuelGauge.h"

class Odometer
{
  FuelGauge &fg;
  int mileage;
  
public:
  Odometer(int, FuelGauge& fuelg);
  void setMileage(int);
  int getMileage() const;
  int increaseMileage();
};

#endif /* Odometer_h */
