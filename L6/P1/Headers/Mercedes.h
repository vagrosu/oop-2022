#pragma once
#include "Weather.h"
#include "Car.h"

class Mercedes : public Car{
public:
    Mercedes();
    void SetAverageSpeed(Weather weather) override;
};



