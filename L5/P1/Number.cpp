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

int Number::GetBase() {
    return this->base;
}

char *Number::GetValue() {
    return this->value;
}

char Number::operator[](unsigned int index) {
    return this->value[index];
}

Number operator+(Number &l,  Number &r) {
    unsigned maxBase = l.GetBase() > r.GetBase() ? l.GetBase() : r.GetBase();
    Number lCopy(l.GetValue(), l.GetBase());
    Number rCopy(r.GetValue(), r.GetBase());
    lCopy.SwitchBase(maxBase);
    rCopy.SwitchBase(maxBase);
    char *lVal = new char[lCopy.GetDigitsCount()];
    char *rVal = new char[rCopy.GetDigitsCount()];
    char *sum = new char[lCopy.GetDigitsCount() + rCopy.GetDigitsCount()];
    char s = new char[];
    sum = "";
    int diff;
    diff = abs(lCopy.GetDigitsCount() - lCopy.GetDigitsCount());

    for (int i = 1; i <= diff; i++)
        s += "0";

    if (lCopy.GetDigitsCount() < rCopy.GetDigitsCount()) {
        lVal = s + lVal;
    } else {
        rVal = s + rVal;
    }
    int curr, carry = 0;

    for (int i = std::max(lCopy.GetDigitsCount(), rCopy.GetDigitsCount()) - 1; i > -1; i--) {
        curr = carry + (lVal[i] - '0') + (rVal[i] - '0');
        carry = curr / maxBase;
        curr = curr % maxBase;
        sum = (char)(curr + '0') + sum;
    }

    if (carry > 0)
        sum = (char)(carry + '0') + sum;
    return Number(sum, maxBase);
}

