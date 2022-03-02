#include "movie.h";
#include <cstring>


void Movie::init() {
    score = 0.0;
    year = 0;
    length = 0;
    name[0] = '\0';
}

void Movie::set_name(const char* name) {
    strcpy(this->name, name);
}

void Movie::set_score(double score) {
    this->score = score;
}

void Movie::set_year(unsigned year) {
    this->year = year;
}

void Movie::set_length(unsigned length) {
    this->length = length;
}

const char* Movie::get_name() const {
    return name;
}

double Movie::get_score() const {
    return score;
}

unsigned Movie::get_year() const {
    return year;
}

unsigned Movie::get_length() const {
    return length;
}