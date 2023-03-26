#include <iostream>
#include "terminal_utils.h"
#include "Shapes/shape.h"
#include "image.h"

int main()
{
    Screen::Clear();
    Cursor::Reset();

    #pragma region Showcase
    Line l(Point(0, 0), Point(30, 0));
    Rect r(Point(0, 2), 5, 5);
    Mid_Point_Rect mr(Point(10, 5), 3);
    Circle c(Point(18, 5), 3);
    Ellipse e(Point(10, 13), 8, 3);

    Image i("NEED IMAGE", Point(40, 2), 16, 16);

    r.Set_BG(Text::PINK);
    mr.Set_BG(Text::RED);
    c.Set_BG(Text::BLUE);
    e.Set_BG(Text::RGB(7, 128, 125));

    Text::Set_BG_RGB(Text::BROWN);
    l.Draw(' ');
    r.Draw();
    mr.Draw();
    c.Draw();
    e.Draw();

    Write_At_Pos("This is some bold text", 23, 2, Text::RED, Text::BLACK, Text::BOLD);
    Write_At_Pos("This is some italic text", 23, 3, Text::RED, Text::BLACK, Text::ITALIC);
    Write_At_Pos("This is some underlined text", 23, 4, Text::RED, Text::BLACK, Text::UNDERLINED);
    Write_At_Pos("This is some double underlined text", 23, 5, Text::RED, Text::BLACK, Text::DOUBLE_UNDERLINE);

    Text::Text_Attribute a[] = {Text::CROSSED, Text::INVERSE};

    Write_At_Pos("This is some crosed and inversed text", 22, 6, Text::RED, Text::BLACK, a);
    #pragma endregion

    Cursor::Set(0, 18);

    return -1;
}