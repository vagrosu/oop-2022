#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include "movieseries.h"

class Serializer {
private:
    FILE* file;

    bool write_buffer(const void* buffer, unsigned size);
    bool write_movie(const Movie& movie);

public:
    bool init(const char* file_name);
    void close();

    bool write(const MovieSeries& series);
};