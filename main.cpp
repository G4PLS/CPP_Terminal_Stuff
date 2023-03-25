#include <iostream>
#include "terminal_utils.h"
#include "Shapes/shape.h"
#include "image.h"

#include <array>

#include <fstream>
#include <sstream>
#include <string>

int main()
{
    char x;

    Image i("/home/gapls/Documents/Programming/cpp/TerminalStuff/testPPM.ppm", Point(0, 0), 200, 50);
    i.Load();
    i.Draw();

    Cursor::Down(1);
    Cursor::Next_Line(1);

    return -1;
}