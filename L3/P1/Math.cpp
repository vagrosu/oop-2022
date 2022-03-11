#include "Math.h"
#include <cstring>
#include <cstdarg>

int Math::Add(int a, int b) {
    return a+b;
}

int Math::Add(int a, int b, int c) {
    return a+b+c;
}

double Math::Add(double a, double b) {
    return a+b;
}

double Math::Add(double a, double b, double c) {
    return a+b+c;
}

int Math::Mul(int a, int b) {
    return a*b;
}

int Math::Mul(int a, int b, int c) {
    return a*b*c;
}

double Math::Mul(double a, double b) {
    return a*b;
}

double Math::Mul(double a, double b, double c) {
    return a*b*c;
}

int Math::Add(int count, ...) {
    va_list list;
    va_start(list, count);
    int sum = 0;
    for(int i = 0; i < count; i++) {
        sum += va_arg(list, int);
    }
    va_end(list);
    return sum;
}

char* Math::Add(const char *a, const char *b) {
    if(a == nullptr || b == nullptr) {
        return nullptr;
    }
    static char c[256];
    strcpy(c, a);
    strcat(c, b);
    return c;
}
