#include "Headers/Car.h"


const int Car::getFuelCapacity() const {
    return fuelCapacity;
}

const int Car::getFuelConsumption() const {
    return fuelConsumption;
}

const float Car::getAverageSpeed() const {
    return averageSpeed;
}

const char *Car::getCarName() const {
    return carName;
}
