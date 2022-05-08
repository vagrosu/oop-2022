#include "Headers/Mercedes.h"

Mercedes::Mercedes() {
    this->fuelCapacity = 60;
    this->fuelConsumption = 12;
    this->averageSpeed = 120;
    this->carName = {"Mercedes"};
}

void Mercedes::SetAverageSpeed(Weather weather) {
    if(weather == Weather::Rain) {
        this->averageSpeed -= 20;
    } else if(weather == Weather::Snow) {
        this->averageSpeed -= 30;
    }
}