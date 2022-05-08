#pragma once
#include "Weather.h"
#include "Car.h"

class Toyota : public Car{
public:
    Toyota();
    void SetAverageSpeed(Weather weather) override;
};



