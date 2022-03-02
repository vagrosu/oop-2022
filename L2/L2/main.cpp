#include "movieseries.h"
#include "serializer.h"
#include "deserializer.h"

MovieSeries get_series() {
    Movie ep5;
    ep5.init();
    ep5.set_name("Star Wars: Episode V - The Empire Strikes Back");
    ep5.set_score(8.7);
    ep5.set_year(1980);
    ep5.set_length(124);

    Movie ep4;
    ep4.init();
    ep4.set_name("Star Wars: Episode IV - A New Hope");
    ep4.set_score(8.6);
    ep4.set_year(1977);
    ep4.set_length(121);

    Movie ep6;
    ep6.init();
    ep6.set_name("Star Wars: Episode VI - Return of the Jedi");
    ep6.set_score(8.3);
    ep6.set_year(1983);
    ep6.set_length(131);

    MovieSeries series;
    series.init();
    series.add(ep4);
    series.add(ep5);
    series.add(ep6);

    return series;
}

#define FILE_NAME "movies.data"

bool do_write(const MovieSeries& series) {
    Serializer serializer;
    if (!serializer.init(FILE_NAME)) {
        serializer.close();
        return false;
    }

    if (!serializer.write(series)) {
        serializer.close();
        return false;
    }

    serializer.close();
    return true;
}
//
// bool do_read(MovieSeries& series) {
//    Deserializer deserializer;
//    if (!deserializer.init(FILE_NAME)) {
//        deserializer.close();
//        return false;
//    }
//
//    if (!deserializer.read(series)) {
//        deserializer.close();
//        return false;
//    }
//
//    deserializer.close();
//    return true;
//}

int main() {
    MovieSeries series = get_series();
    series.print();

    if (!do_write(series)) {
        return -1;
    }

    // MovieSeries new_series;
    // new_series.init();
    // if (!do_read(new_series)) {
    //    return -1;
    //}

    // printf("\n---------------------------------------------------------------------------------\n\n");
    // new_series.print();
}