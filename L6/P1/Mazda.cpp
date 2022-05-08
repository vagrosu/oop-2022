#include "Headers/Mazda.h"

Mazda::Mazda() {
    this->fuelCapacity = 40;
    this->fuelConsumption = 7;
    this->averageSpeed = 80;
    this->carName = {"Mazda"};
}

void Mazda::SetAverageSpeed(Weather weather) {
    if(weather == Weather::Rain) {
        this->averageSpeed -= 20;
    } else if(weather == Weather::Snow) {
        this->averageSpeed -= 30;
    }
}