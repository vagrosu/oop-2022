#pragma once

class Movie {
private:
    char name[200];
    double score;
    unsigned year;
    unsigned length;

public:
    void init();
    void set_name(const char* name);
    void set_score(double score);
    void set_year(unsigned year);
    void set_length(unsigned length);
    const char* get_name() const;
    double get_score() const;
    unsigned get_year() const;
    unsigned get_length() const;

};