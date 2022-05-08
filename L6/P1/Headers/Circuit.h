#pragma once
#include "Weather.h"
#include "Car.h"
#include "Dacia.h"
#include "Toyota.h"
#include "Mercedes.h"
#include "Ford.h"
#include "Mazda.h"

class Circuit {
    int length;
    int numberOfCars;
    Car *cars[25];
public:
    Circuit();
    void SetLength(int length);
    void SetWeather(Weather weather);
    void AddCar(Car* car);
    void Race();
    void ShowFinalRanks();
};



