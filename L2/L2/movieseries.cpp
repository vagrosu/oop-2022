#include "movieseries.h"
#include <iostream>
void MovieSeries::init() {
    size = 0;
}

void MovieSeries::add(const Movie& movie) {
    movies[size] = movie;
    size++;
}
void MovieSeries::print() const {
    for (unsigned i=0;i<size;i++) {
        std::cout << i+1 << '.'<< movies[i].get_name() << ' '
                  << movies[i].get_year() << ' '
                  << movies[i].get_score() << ' ' << movies[i].get_length() <<'\n';
    }
}

unsigned MovieSeries::get_size() const {
    return size;
}

const Movie& MovieSeries::get_movie_by_index(unsigned index) const {
    return movies[index];
}
