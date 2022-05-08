#pragma once
#include "Weather.h"
#include "Car.h"

class Mazda : public Car{
public:
    Mazda();
    void SetAverageSpeed(Weather weather) override;
};