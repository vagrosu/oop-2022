#pragma once
#include "Weather.h"
#include "Car.h"

class Ford : public Car{
public:
    Ford();
    void SetAverageSpeed(Weather weather) override;
};