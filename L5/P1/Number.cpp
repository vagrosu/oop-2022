#include "Number.h"
#include <cstring>
#include <iostream>
#include <cstdlib>

unsigned charToInt(char value) {
    if(value >= '0' && value <= '9') {
        return value-'0';
    } else if(value >= 'A' && value <= 'F'){
        return value-55;
    }
    return 0;
}

char intToChar(int value) {
    if(value >= 0 && value <= 9) {
        return value+'0';
    } else if(value >= 10 && value <= 15) {
        return value+55;
    }
}

Number::Number(const char *value, int base) {
    this->value = new char[strlen(value)];
    strcpy(this->value, value);
    this->base = base;
}

Number::~Number() {
    delete this->value;
    this->base=0;
}

void Number::SwitchBase(int newBase) {
    if(this->base != newBase) {
        unsigned power = 1;
        unsigned base10Number = 0;
        for(int i = strlen(this->value)-1; i >= 0; i--) {
            base10Number += power * charToInt(this->value[i]);
            power *= this->base;
        }

        int i = -1;
        while(base10Number) {
            this->value[++i] = intToChar(base10Number % newBase);
            base10Number /= newBase;
        }
        this->value[++i] = NULL;
        for(int i = 0; i < strlen(this->value)/2; i++) {
            std::swap(this->value[i], this->value[strlen(this->value)-i-1]);
        }
        this->base = newBase;
    }
}

void Number::Print() {
    std::cout << this->value << '\n';
}

int Number::GetDigitsCount() {
    return strlen(this->value);
}

int Number::GetBase() const {
    return this->base;
}

char *Number::GetValue() const{
    return this->value;
}

char Number::operator[](unsigned int index) {
    return this->value[index];
}

Number Number::operator=(int value) {
    unsigned finalBase = this->base;
    std::string stringValue = std::to_string(value);
    char const *charValue = stringValue.c_str();

    Number finalNumber(charValue, 10);
    finalNumber.SwitchBase(finalBase);
    strcpy(this->value, finalNumber.GetValue());
    return finalNumber;
}

Number Number::operator=(const char *value) {
    strcpy(this->value, value);
    this->base = 10;
    return Number(value, 10);
}

Number operator+(const Number &l, const Number &r) {
    unsigned maxBase = l.GetBase() > r.GetBase() ? l.GetBase() : r.GetBase();
    Number lCopy(l.GetValue(), l.GetBase());
    Number rCopy(r.GetValue(), r.GetBase());
    lCopy.SwitchBase(10);
    rCopy.SwitchBase(10);

    int intSum = atoi(lCopy.GetValue()) + atoi(rCopy.GetValue());
    std::string stringSum = std::to_string(intSum);
    char const *charSum = stringSum.c_str();

    Number sumResult(charSum, 10);
    sumResult.SwitchBase(maxBase);
    std::cout << "Suma celor 2 numere in baza " << sumResult.GetBase() << " este: " << ' ' << sumResult.GetValue() << '\n';
    return sumResult;
}

Number operator-(const Number &l, const Number &r) {
    unsigned maxBase = l.GetBase() > r.GetBase() ? l.GetBase() : r.GetBase();
    Number lCopy(l.GetValue(), l.GetBase());
    Number rCopy(r.GetValue(), r.GetBase());
    lCopy.SwitchBase(10);
    rCopy.SwitchBase(10);

    int intDif = atoi(lCopy.GetValue()) - atoi(rCopy.GetValue());
    std::string stringDif = std::to_string(intDif);
    char const *charDif = stringDif.c_str();

    Number difResult(charDif, 10);
    difResult.SwitchBase(maxBase);
    std::cout << "Diferenta celor 2 numere in baza " << difResult.GetBase() << " este: " << ' ' << difResult.GetValue() << '\n';
    return difResult;
}

bool operator>(const Number &l, const Number &r) {
    Number lCopy(l.GetValue(), l.GetBase());
    Number rCopy(r.GetValue(), r.GetBase());
    lCopy.SwitchBase(10);
    rCopy.SwitchBase(10);

    if(lCopy.GetValue() > rCopy.GetValue()) {
        return true;
    }
    return false;
}

bool operator<(const Number &l, const Number &r) {
    Number lCopy(l.GetValue(), l.GetBase());
    Number rCopy(r.GetValue(), r.GetBase());
    lCopy.SwitchBase(10);
    rCopy.SwitchBase(10);

    if(lCopy.GetValue() < rCopy.GetValue()) {
        return true;
    }
    return false;
}


