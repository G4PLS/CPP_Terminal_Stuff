#include <iostream>
#include "terminal_utils.h"
#include "Shapes/shape.h"

int main()
{
    char x;

    Screen::Clear();
    Cursor::Reset();
    
    Triangle t(Point(10, 5), Point(21, 5), Point(16, 10));
    t.Draw();
    std::cin >> x;
    t.Set_X(1);
    t.Set_Y(1);
    t.Redraw();

    Cursor::Set(0, 25);
    return -1;
}