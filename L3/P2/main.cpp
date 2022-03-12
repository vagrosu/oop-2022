#include <iostream>
#include "Canvas.h"
void useCanvasExample() {
    Canvas canv(50, 50);
    canv.Clear();
    canv.DrawLine(22, 21, 26, 28, '\\');
    canv.DrawLine(22, 29, 26, 21, '/');
    canv.SetPoint(26, 25, '-');
    canv.DrawRect(24, 33, 26, 40, '|');
    canv.FillRect(24, 33, 26, 45, '|');
    canv.DrawCircle(18, 25, 15, '+');
    canv.FillCircle(13, 18, 2, '0');
    canv.FillCircle(13, 32, 2, '0');
    canv.Print();
}
int main() {

    useCanvasExample();
    return 0;
}
