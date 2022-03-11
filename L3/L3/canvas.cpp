#include "canvas.h"
#include <string.h>
#include <stdarg.h>
#include <cstdio>
Canvas::Canvas(int lines, int columns) {
    this->lines = lines;
    this->columns = columns;
    clear();
}

void Canvas::set_pixel(int x, int y, char value) {
    poza[x][y] = value;
}

void Canvas::set_pixels(int count, ...) {
    int* p = &count;
    int x, y;
    char value;
    va_list args;
    va_start(args, count);
    for (unsigned i = 0; i < count; i++) {
        x = va_arg(args, int);
        y = va_arg(args, int);
        value = va_arg(args, char);
        set_pixel(x, y, value);
    }
    va_end(args);
}

void Canvas::clear() {
    memset(poza, ' ', sizeof(poza));
}

void Canvas::print() const {
    for (unsigned i = 0; i < lines; i++) {
        for (unsigned j = 0; j < columns; j++)
            printf("%c", poza[i][j]);
        printf("\n");
    }
}
