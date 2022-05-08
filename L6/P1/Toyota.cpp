#include "Headers/Toyota.h"

Toyota::Toyota() {
    this->fuelCapacity = 65;
    this->fuelConsumption = 9;
    this->averageSpeed = 100;
    this->carName = {"Toyota"};
}

void Toyota::SetAverageSpeed(Weather weather) {
    if(weather == Weather::Rain) {
        this->averageSpeed -= 20;
    } else if(weather == Weather::Snow) {
        this->averageSpeed -= 30;
    }
}