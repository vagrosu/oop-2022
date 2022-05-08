#pragma once
#include "Weather.h"

class Car {
protected:
    int fuelCapacity;
    int fuelConsumption;
    float averageSpeed;
    char * carName;
public:
    virtual void SetAverageSpeed(Weather weather)=0;
    const int getFuelCapacity() const;
    const int getFuelConsumption() const;
    const float getAverageSpeed() const;
    const char* getCarName() const;
};



