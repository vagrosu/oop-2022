#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include "movieseries.h"

class Deserializer {
private:
    FILE* file;

    bool read_buffer(void* buffer, unsigned size);
    bool read_movie(Movie& movie);

public:
    bool init(const char* file_name);
    void close();

    bool read(MovieSeries& series);
};