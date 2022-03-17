#include "mylibrary.h"
#include <cstring>

MyLibrary::~MyLibrary() {
    delete[] books;
}

MyLibrary::MyLibrary(std::ostream &output_stream) : output_stream (output_stream) {
    books_count = 0;
    books = nullptr;
}

MyLibrary::MyLibrary(std::ostream &output_stream, unsigned int books_count, int *books) : output_stream (output_stream) {
    books = new int[books_count];
    this->books_count = books_count;
    for(int i = 0; i < books_count; i++) {
        this->books[i] = books[i];
    }
}

MyLibrary::MyLibrary(std::ostream &output_stream, unsigned int books_count, int min, int max) : output_stream (output_stream) {
    books = new int[books_count];
    this->books_count = books_count;
    for(int i = 0; i < books_count; i++) {
        this->books[i] = rand()%max+min;
    }
}

MyLibrary::MyLibrary(std::ostream &output_stream, const char *books_values) : output_stream (output_stream) {
    int count = 1;
    for(int i = 0 ; i < strlen(books_values); i++) {
        if(books_values[i] == ';') {
            count++;
        }
    }
    books_count = count;
    books = new int[count];

    char *sir = new char[(strlen(books_values)+1) * sizeof(char)];
    strcpy(sir, books_values);
    char *p = strtok(sir, ";");

    while(p) {
        int numar = atoi(p);
        books[]
    }
}

MyLibrary::MyLibrary(std::ostream &output_stream, unsigned int books_count, ...) {

}

void MyLibrary::print_books() {

}

void MyLibrary::update_book_id_by_index(unsigned int book_index, int book_id) {

}
