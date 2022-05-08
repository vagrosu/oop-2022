#include <algorithm>
#include <iostream>
#include "Headers/Circuit.h"

void Circuit::SetLength(int length) {
    this->length = length;
}

void Circuit::SetWeather(Weather weather) {
    for(unsigned i = 0; i < numberOfCars; i++){
        cars[i]->SetAverageSpeed(weather);
    }
}

Circuit::Circuit() {
    length = 0;
    numberOfCars = 0;
}

void Circuit::AddCar(Car *car) {
    cars[numberOfCars] = car;
    numberOfCars++;
}

void Circuit::Race() {
    for(unsigned i = 0; i < numberOfCars-1; i++) {
        for(unsigned j = i + 1; j <= numberOfCars-1; j++) {
            if(cars[i]->getAverageSpeed() < cars[j]->getAverageSpeed()) {
                std::swap(cars[i], cars[j]);
            }
        }
    }
}

void Circuit::ShowFinalRanks() {
    for(unsigned i = 0; i < numberOfCars; i++) {
        std::cout<< cars[i]->getCarName() << ' ' << length/cars[i]->getAverageSpeed() << '\n';
    }
}
