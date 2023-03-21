#include "terminal_utils.h"

#pragma region Cursor
void Cursor::Reset()                      { std::cout << "\033[H"; }
void Cursor::Set(int x, int y)            { std::cout << "\033[" << y << ";" << x << "H"; }
void Cursor::Up(int amount)               { std::cout << "\033[" << amount << "A"; }
void Cursor::Down(int amount)             { std::cout << "\033[" << amount << "B"; }
void Cursor::Right(int amount)            { std::cout << "\033[" << amount << "C"; }
void Cursor::Left(int amount)             { std::cout << "\033[" << amount << "D"; }
void Cursor::Next_Line(int lines_down)    { std::cout << "\033[" << lines_down << "E"; }
void Cursor::Prev_Line(int lines_up)      { std::cout << "\033[" << lines_up << "F"; }
void Cursor::To_X(int x)                  { std::cout << "\033[" << x << "G"; }
void Cursor::Save_Pos()                   { std::cout << "\033[s"; }
void Cursor::Load_Pos()                   { std::cout << "\033[u"; }
void Cursor::Set_Style(Style style)       { std::cout << "\033[" << style << " q"; }
void Cursor::Visible(bool visible)        { visible ? std::cout << "\033[?25h" : std::cout << "\033[?25l"; }

// Starting where the cursor is placed
void Cursor::Erase_To_End_Line()                         { std::cout << "\033[0K"; }
void Cursor::Erase_Lines(int amount)                     { std::cout << "\033[" << amount << "M"; }
void Cursor::Erase_Characters(int amount)                { std::cout << "\033[" << amount << "X"; }
void Cursor::Insert_Lines(int amount)                    { std::cout << "\033[" << amount << "L"; }
void Cursor::Repeat_Character(char character, int amount) { std::cout << character << "\033[" << amount << "b"; }
#pragma endregion

#pragma region Screen
void Screen::Erase_To_End(int x, int y)   { Cursor::Set(x, y); std::cout << "\033[0J"; }
void Screen::Erase_To_Begin(int x, int y) { Cursor::Set(x, y); std::cout << "\033[1J"; }
void Screen::Clear()                      { std::cout << "\033[2J"; }
/// @brief Can switch to an alternate screen. The alternate screen cant save text that got displayed.
/// @param screen 
void Screen::Use_Alternate_Screen(bool use_alternate_screen) { use_alternate_screen ? std::cout << "\033[?47h" : std::cout << "\033[?47l"; }
#pragma endregion

#pragma region Text
void Text::Set_FG_RGB(RGB rgb)                                { std::cout << "\033[38;2;" << (int)rgb.r << ";" << (int)rgb.g << ";" << (int)rgb.b << "m"; }
void Text::Set_BG_RGB(RGB rgb)                                { std::cout << "\033[48;2;" << (int)rgb.r << ";" << (int)rgb.g << ";" << (int)rgb.b << "m"; }
void Text::Set_FG_BG_RGB(RGB fg, RGB bg)                      { Text::Set_FG_RGB(fg); Text::Set_BG_RGB(bg); }
void Text::Set_FG_Pallete(byte id)                            { std::cout << "\033[38;5;" << (int)id << "m"; }
void Text::Set_BG_Pallete(byte id)                            { std::cout << "\033[48;5;" << (int)id << "m"; }
void Text::Set_FG_BG_Pallete(byte id_fg, byte id_bg)          { Text::Set_FG_Pallete(id_fg); Text::Set_BG_Pallete(id_bg); }
void Text::Set_Text_Attribute(Text::Text_Attribute attribute) { std::cout << "\033[" << attribute << "m"; }
void Text::Reset_Color()                                      { std::cout << "\033[39m" << "\033[49m"; }
void Text::Reset_Attributes()                                 { std::cout << "\033[22m\033[23m\033[24m\033[25m\033[26m\033[27m\033[28m\033[29m"; }
void Text::Reset_All()                                        { std::cout << "\033[0m"; }
#pragma endregion

void Write_At_Pos(char message[], int x, int y) 
{
    Cursor::Set(x, y);
    std::cout << message;
}

void Write_At_Pos(char message[], int x, int y, Text::Text_Attribute attr)
{
    Cursor::Set(x, y);
    Text::Set_Text_Attribute(attr);
    std::cout << message;
    Text::Reset_Attributes();
}

void Write_At_Pos(char message[], int x, int y, Text::Text_Attribute attr[])
{
    Cursor::Set(x, y);

    for(int i = 0; i < (sizeof(attr) / sizeof(attr[0])); i++)
        Text::Set_Text_Attribute(attr[i]);

    std::cout << message;
    Text::Reset_Attributes();
}

void Write_At_Pos(char message[], int x, int y, Text::RGB fg)
{
    Cursor::Set(x, y);
    Text::Set_FG_RGB(fg);
    std::cout << message;
    Text::Reset_Color();
}

void Write_At_Pos(char message[], int x, int y, Text::RGB fg, Text::RGB bg)
{
    Cursor::Set(x, y);
    Text::Set_FG_BG_RGB(fg, bg);
    std::cout << message;
    Text::Reset_Color();
}

void Write_At_Pos(char message[], int x, int y, Text::RGB fg, Text::RGB bg, Text::Text_Attribute attr) 
{
    Cursor::Set(x, y);
    Text::Set_FG_BG_RGB(fg, bg);
    Text::Set_Text_Attribute(attr);
    std::cout << message;
    Text::Reset_All();
}

void Write_At_Pos(char message[], int x, int y, Text::RGB fg, Text::RGB bg, Text::Text_Attribute attr[]) 
{
    Cursor::Set(x, y);
    Text::Set_FG_BG_RGB(fg, bg);

    for(int i = 0; i < (sizeof(attr) / sizeof(attr[0])); i++)
        Text::Set_Text_Attribute(attr[i]);

    int z [] = {1, 2, 3, 4, 5};
    int w = sizeof(x);

    std::cout << message;
    Text::Reset_All();
}