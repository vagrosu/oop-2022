#include "serializer.h"

bool Serializer::write_buffer(const void* buffer, unsigned size) {
    return fwrite(buffer, 1, size, file) == size;
}

bool Serializer::write_movie(const Movie& movie) {


    unsigned year = movie.get_year();
    double score = movie.get_score();
    unsigned length = movie.get_length();
    const char* name = movie.get_name();
    unsigned name_length = (unsigned)strlen(name);
    if (!write_buffer(&year, sizeof(year)))
        return false;
    if (!write_buffer(&score, sizeof(score)))
        return false;
    if (!write_buffer(&length, sizeof(length)))
        return false;
    if (!write_buffer(&name_length, sizeof(name_length)))
        return false;
    if (!write_buffer(name, sizeof(char)*name_length))
        return false;
    return true;

}

bool Serializer::init(const char* file_name) {
    file = fopen(file_name, "wb");
    return file != nullptr;
}

void Serializer::close() {
    if (file) {
        fclose(file);
    }
}

bool Serializer::write(const MovieSeries& series) {
    unsigned series_length = series.get_size();
    if (!write_buffer(&series_length, sizeof(series_length)))
        return false;
    for (unsigned i = 0; i < series.get_size(); i++) {
        if (!write_movie(series.get_movie_by_index(i)))
            return false;
    }
    return true;
}