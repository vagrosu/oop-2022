#include "Headers/VowelsHash.h"

int CountVowelsHash::HashFromString(const char *sir) {
    unsigned vowelsNumber = 0;
    for(unsigned i = 0; i < strlen(sir); i++) {
        if(strchr("AEIOUaeiou", sir[i])) {
            vowelsNumber++;
        }
    }
    return vowelsNumber;
}
