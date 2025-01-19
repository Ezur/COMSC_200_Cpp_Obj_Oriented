// FUELGAUGE.H

#ifndef FuelGauge_h
#define FuelGauge_h

class FuelGauge
{
  int currentFuel;
  
public:
  FuelGauge(); // constructor
  void setFuel(int g);
  int getFuel() const;
  void increaseFuel();
  void decreaseFuel();
};

#endif /* FuelGauge_h */

