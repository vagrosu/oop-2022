#include "Canvas.h"
#include <cstdio>
#include <cstring>

Canvas::Canvas(int width, int height) {
    this->width = width;
    this->height = height;
    Clear();
}

void Canvas::DrawCircle(int x, int y, int ray, char ch) {
    unsigned start, end;
    for(unsigned i = x-ray; i <= x+ray; i++) {
        start = end = -1;
        for(unsigned j = y-ray; j <= y+ray; j++) {
            if((i-x)*(i-x) + (j-y)*(j-y) <= ray*ray) {
                if(start == -1) {
                    start = j;
                }
                end = j;
            }
        }
        if(start != -1) {
            SetPoint(i, start, ch);
            SetPoint(i, end, ch);
        }
    }
}

void Canvas::FillCircle(int x, int y, int ray, char ch) {
    for(unsigned i = x-ray; i <= x+ray; i++) {
        for(unsigned j = y-ray; j <= y+ray; j++) {
            if((i-x)*(i-x) + (j-y)*(j-y) <= ray*ray) {
                SetPoint(i, j, ch);
            }
        }
    }
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch) {
    for(unsigned j = left; j <= right; j++) {
        SetPoint(top,j, ch);
        SetPoint(bottom,j, ch);
    }
    for(unsigned i = top; i < bottom; i++) {
        SetPoint(i,left, ch);
        SetPoint(i,right, ch);
    }
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch) {
    for(unsigned i = top+1; i < bottom; i++) {
        for(unsigned j = left+1; j < right; j++) {
            SetPoint(i, j, ch);
        }
    }
}

void Canvas::SetPoint(int x, int y, char ch) {
    canv[x][y] = ch;
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int yi = 1;
    if(dy < 0) {
        yi = -1;
        dy = -dy;
    }
    int d = 2*dy - dx;
    int y = y1;
    for(int x = x1; x <= x2; x++) {
        SetPoint(x, y, ch);
        if(d > 0) {
            y = y + yi;
            d = d + (2*(dy - dx));
        } else {
            d = d + 2*dx;
        }
    }
}

void Canvas::Print() {
    for(unsigned i = 1; i <= height; i++) {
        for(unsigned j = 1; j <= width; j++) {
            printf(" %c ", canv[i][j]);
        }
        printf("\n");
    }
}

void Canvas::Clear() {
    memset(canv, ' ', sizeof(canv));
}
