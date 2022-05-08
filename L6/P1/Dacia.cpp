#include "Headers/Dacia.h"

Dacia::Dacia() {
    this->fuelCapacity = 40;
    this->fuelConsumption = 7;
    this->averageSpeed = 80;
    this->carName = {"Dacia"};
}

void Dacia::SetAverageSpeed(Weather weather) {
    if(weather == Weather::Rain) {
        this->averageSpeed -= 20;
    } else if(weather == Weather::Snow) {
        this->averageSpeed -= 30;
    }
}
