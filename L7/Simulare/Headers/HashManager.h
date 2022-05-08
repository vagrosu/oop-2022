#include "Hash.h"

class HashManager {
    struct pair {
        Hash* hash;
        const char* nume;
    };
    pair hashes[20];
    int size;
public:
    HashManager();
    Hash*& operator[] (const char*);
    void print_hashes(const char*);
};
