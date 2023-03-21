#include <iostream>
#include "terminal_utils.h"

int main()
{
    Text::Set_Text_Attribute(Text::Text_Attribute::BLINK);
    Write_At_Pos(" ", 4, 1, Text::BLACK, Text::RED);
    Write_At_Pos(" ", 5, 1, Text::BLACK, Text::RED);
    Write_At_Pos(" ", 6, 1, Text::BLACK, Text::RED);
    Write_At_Pos(" ", 7, 1, Text::BLACK, Text::RED);
    Write_At_Pos(" ", 8, 1, Text::BLACK, Text::RED);
    Write_At_Pos(" ", 9, 1, Text::BLACK, Text::RED);

    Write_At_Pos(" ", 3, 2, Text::BLACK, Text::RED);
    Write_At_Pos(" ", 4, 2, Text::BLACK, Text::RED);
    Write_At_Pos(" ", 5, 2, Text::BLACK, Text::RED);
    Write_At_Pos(" ", 6, 2, Text::BLACK, Text::RED);
    Write_At_Pos(" ", 7, 2, Text::BLACK, Text::RED);
    Write_At_Pos(" ", 8, 2, Text::BLACK, Text::RED);
    Write_At_Pos(" ", 9, 2, Text::BLACK, Text::RED);
    Write_At_Pos(" ", 10, 2, Text::BLACK, Text::RED);
    Write_At_Pos(" ", 11, 2, Text::BLACK, Text::RED);
    Write_At_Pos(" ", 12, 2, Text::BLACK, Text::RED);

    Write_At_Pos(" ", 3, 3, Text::BLACK, Text::BROWN);
    Write_At_Pos(" ", 4, 3, Text::BLACK, Text::BROWN);
    Write_At_Pos(" ", 5, 3, Text::BLACK, Text::BROWN);
    Write_At_Pos(" ", 6, 3, Text::BLACK, Text::BROWN);
    Write_At_Pos(" ", 7, 3, Text::BLACK, Text::PINK);
    Write_At_Pos(" ", 8, 3, Text::BLACK, Text::PINK);
    Write_At_Pos(" ", 9, 3, Text::BLACK, Text::BROWN);
    Write_At_Pos(" ", 10, 3, Text::BLACK, Text::PINK);

    Write_At_Pos(" ", 2, 4, Text::BLACK, Text::BROWN);
    Write_At_Pos(" ", 3, 4, Text::BLACK, Text::BROWN);
    Write_At_Pos(" ", 4, 4, Text::BLACK, Text::PINK);
    Write_At_Pos(" ", 5, 4, Text::BLACK, Text::BROWN);
    Write_At_Pos(" ", 6, 4, Text::BLACK, Text::PINK);
    Write_At_Pos(" ", 7, 4, Text::BLACK, Text::PINK);
    Write_At_Pos(" ", 8, 4, Text::BLACK, Text::PINK);
    Write_At_Pos(" ", 9, 4, Text::BLACK, Text::BROWN);
    Write_At_Pos(" ", 10, 4, Text::BLACK, Text::PINK);
    Write_At_Pos(" ", 11, 4, Text::BLACK, Text::PINK);
    Write_At_Pos(" ", 12, 4, Text::BLACK, Text::PINK);

    Write_At_Pos(" ", 2, 5, Text::BLACK, Text::BROWN);
    Write_At_Pos(" ", 3, 5, Text::BLACK, Text::BROWN);
    Write_At_Pos(" ", 4, 5, Text::BLACK, Text::PINK);
    Write_At_Pos(" ", 5, 5, Text::BLACK, Text::BROWN);
    Write_At_Pos(" ", 6, 5, Text::BLACK, Text::BROWN);
    Write_At_Pos(" ", 7, 5, Text::BLACK, Text::PINK);
    Write_At_Pos(" ", 8, 5, Text::BLACK, Text::PINK);
    Write_At_Pos(" ", 9, 5, Text::BLACK, Text::PINK);
    Write_At_Pos(" ", 10, 5, Text::BLACK, Text::BROWN);
    Write_At_Pos(" ", 11, 5, Text::BLACK, Text::PINK);
    Write_At_Pos(" ", 12, 5, Text::BLACK, Text::PINK);
    Write_At_Pos(" ", 13, 5, Text::BLACK, Text::PINK);

    Write_At_Pos(" ", 2, 6, Text::BLACK, Text::BROWN);
    Write_At_Pos(" ", 3, 6, Text::BLACK, Text::BROWN);
    Write_At_Pos(" ", 4, 6, Text::BLACK, Text::BROWN);
    Write_At_Pos(" ", 5, 6, Text::BLACK, Text::PINK);
    Write_At_Pos(" ", 6, 6, Text::BLACK, Text::PINK);
    Write_At_Pos(" ", 7, 6, Text::BLACK, Text::PINK);
    Write_At_Pos(" ", 8, 6, Text::BLACK, Text::PINK);
    Write_At_Pos(" ", 9, 6, Text::BLACK, Text::BROWN);
    Write_At_Pos(" ", 10, 6, Text::BLACK, Text::BROWN);
    Write_At_Pos(" ", 11, 6, Text::BLACK, Text::BROWN);
    Write_At_Pos(" ", 12, 6, Text::BLACK, Text::BROWN);

    Write_At_Pos(" ", 3, 7, Text::BLACK, Text::PINK);
    Write_At_Pos(" ", 4, 7, Text::BLACK, Text::PINK);
    Write_At_Pos(" ", 5, 7, Text::BLACK, Text::PINK);
    Write_At_Pos(" ", 6, 7, Text::BLACK, Text::PINK);
    Write_At_Pos(" ", 7, 7, Text::BLACK, Text::PINK);
    Write_At_Pos(" ", 8, 7, Text::BLACK, Text::PINK);
    Write_At_Pos(" ", 9, 7, Text::BLACK, Text::PINK);
    Write_At_Pos(" ", 10, 7, Text::BLACK, Text::PINK);
    Write_At_Pos(" ", 11, 7, Text::BLACK, Text::PINK);
    Cursor::Down(1);
    return -1;
}