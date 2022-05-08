#pragma once
#include <cstring>
#include <stdio.h>

class Hash {
public:
    virtual int HashFromString(const char *) = 0;
};
