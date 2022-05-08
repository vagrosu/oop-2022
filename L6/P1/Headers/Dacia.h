#pragma once
#include "Weather.h"
#include "Car.h"

class Dacia : public Car{
public:
    Dacia();
    void SetAverageSpeed(Weather weather) override;
};



