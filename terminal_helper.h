#ifndef TERMINAL_HELPER_H
#define TERMINAL_HELPER_H

#include <iostream>

typedef bool bit;

namespace Cursor
{
    enum Style
    {
        DEFAULT = 1,
        BLINK = 0,
        STEADY = 2,
        BLINK_UNDERSCORE = 3,
        STEADY_UNDERSCORE = 4,
        BLINK_BAR = 5,
        STEADY_BAR = 6
    };

    void Reset();
    void Set(int x, int y);
    void Up(int amount);
    void Down(int amout);
    void Right(int amount);
    void Left(int amount);
    void Next_Line(int lines_down);
    void Prev_Line(int lines_up);
    void To_X(int x);
    void Save_Pos();
    void Load_Pos();
    void Set_Style(Style style);
    void Visible(bool visible);

    void Erase_To_End_Line();
    void Erase_Lines(int amount);
    void Insert_Lines(int amount);
    void Erase_Characters(int amount);
    void Repeat_Character(int amount);

} // namespace Cursor

namespace Screen
{
    void Erase_To_End(int x, int y);
    void Erase_To_Begin(int x, int y);
    void Switch_Screen(bit screen);
    void Clear();
}

namespace Color
{
    typedef unsigned char byte;

    struct RGB
    {
        byte r;
        byte g;
        byte b;

        RGB(byte r, byte g, byte b) : r(r), g(g), b(b)
        {}
    };

    const RGB BLACK(0, 0, 0);
    const RGB WHITE(255, 255, 255);
    const RGB GRAY(128, 128, 128);
    const RGB RED(255, 0, 0);
    const RGB ORANGE(255, 128, 0);
    const RGB YELLOW(255, 255, 0);
    const RGB GREEN(0, 255, 0);
    const RGB CYAN(0, 255, 255);
    const RGB BLUE(0, 0, 255);
    const RGB PURPLE(127, 0, 255);
    const RGB PINK(255, 0, 255);
    const RGB DARK_GRAY(64, 64, 64);
    const RGB DARK_RED(153, 0, 0);
    const RGB DARK_ORANGE(153, 76, 0);
    const RGB DARK_YELLOW(153, 153, 0);
    const RGB DARK_GREEN(0, 153, 0);
    const RGB DARK_CYAN(0, 153, 153);
    const RGB DARK_BLUE(0, 0, 153);
    const RGB DARK_PURPLE(76, 0, 153);
    const RGB DARK_PINK(153, 0, 153);
    const RGB LIGHT_GRAY(192, 192, 192);
    const RGB LIGHT_RED(255, 102, 102);
    const RGB LIGHT_ORANGE(255, 178, 102);
    const RGB LIGHT_YELLOW(255, 255, 102);
    const RGB LIGHT_GREEN(102, 255, 102);
    const RGB LIGHT_CYAN(102, 255, 255);
    const RGB LIGHT_BLUE(102, 102, 255);
    const RGB LIGHT_PURPLE(178, 102, 255);
    const RGB LIGHT_PINK(255, 102, 255);

    void Set_FG_RGB(RGB rgb);
    void Set_BG_RGB(RGB rgb);
    void Set_FG_Pallete(byte id);
    void Set_BG_Pallete(byte id);
}

enum Character_Attributes
    {
        // \033[#m
        DEFAULT = 0,
        BOLD = 1,
        FAINT = 2,
        ITALIC = 3,
        UNDERLINED = 4,
        INVERSE = 7,
        INVISIBLE = 8,
        CROSSED = 9,
        DOUBLE_UNDERLINE = 21
    };

#endif