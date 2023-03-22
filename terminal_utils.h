#ifndef TERMINAL_HELPER_H
#define TERMINAL_HELPER_H

#include <iostream>

// https://gist.github.com/fnky/458719343aabd01cfb17a3a4f7296797
// https://invisible-island.net/xterm/ctlseqs/ctlseqs.html#h3-Functions-using-CSI-_-ordered-by-the-final-character_s_    

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
    void Repeat_Character(char character, int amount);

} // namespace Cursor

namespace Screen
{
    void Erase_To_End(int x, int y);
    void Erase_To_Begin(int x, int y);
    void Use_Alternate_Screen(bool use_alternate_screen);
    void Clear();
}

namespace Text
{
    typedef unsigned char byte;

    struct RGB
    {
        byte r = 0;
        byte g = 0;
        byte b = 0;

        RGB(byte r, byte g, byte b) : r(r), g(g), b(b)
        {}
        RGB() {}
    };

    enum Text_Attribute
    {
        // \033[#m
        DEFAULT = 0,
        BOLD = 1,
        FAINT = 2,
        ITALIC = 3,
        UNDERLINED = 4,
        BLINK = 5,
        INVERSE = 7,
        INVISIBLE = 8,
        CROSSED = 9,
        DOUBLE_UNDERLINE = 21
    };

    #pragma region RGB Constants
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

    const RGB BROWN(160, 82, 45);
    const RGB DARK_BROWN(101, 67, 33);
    const RGB LIGHT_BROWN(181, 101, 29);
    #pragma endregion

    void Set_FG_RGB(RGB rgb);
    void Set_BG_RGB(RGB rgb);
    void Set_FG_BG_RGB(RGB fg, RGB bg);
    void Set_FG_Pallete(byte id);
    void Set_BG_Pallete(byte id);
    void Set_FG_BG_Pallete(byte id_fg, byte id_bg);
    void Set_Text_Attribute(Text_Attribute attribute);
    void Reset_Color();
    void Reset_Attributes();
    void Reset_All();
}

void Write_At_Pos(char message[], int x, int y);
void Write_At_Pos(char message[], int x, int y, Text::Text_Attribute attr);
void Write_At_Pos(char message[], int x, int y, Text::Text_Attribute attr[]);
void Write_At_Pos(char message[], int x, int y, Text::RGB fg);
void Write_At_Pos(char message[], int x, int y, Text::RGB fg, Text::RGB bg);
void Write_At_Pos(char message[], int x, int y, Text::RGB fg, Text::RGB bg, Text::Text_Attribute attr);
void Write_At_Pos(char message[], int x, int y, Text::RGB fg, Text::RGB bg, Text::Text_Attribute attr[]);

void Repeat_Char_At_Pos(int x, int y, int amount);


#endif