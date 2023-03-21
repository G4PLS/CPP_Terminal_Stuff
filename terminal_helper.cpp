#include "terminal_helper.h"

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
void Cursor::Visible(bool visible) { visible ? std::cout << "\033[?25h" : std::cout << "\033[?25l"; }

// Starting where the cursor is placed
void Cursor::Erase_To_End_Line()          { std::cout << "\033[0K"; }
void Cursor::Erase_Lines(int amount)      { std::cout << "\033[" << amount << "M"; }
void Cursor::Erase_Characters(int amount) { std::cout << "\033[" << amount << "X"; }
void Cursor::Insert_Lines(int amount)     { std::cout << "\033[" << amount << "L"; }
void Cursor::Repeat_Character(int amount) { std::cout << "\033[" << amount << "b"; }

void Screen::Erase_To_End(int x, int y)   { Cursor::Set(x, y); std::cout << "\033[0J"; }
void Screen::Erase_To_Begin(int x, int y) { Cursor::Set(x, y); std::cout << "\033[1J"; }
void Screen::Switch_Screen(bit screen)    { screen == 0 ? std::cout << "\033[?47l" : std::cout << "\033[?47h"; }
void Screen::Clear()                      { std::cout << "\033[2J"; }

void Color::Set_FG_RGB(RGB rgb) { std::cout << "\033[38;2;" << (int)rgb.r << ";" << (int)rgb.g << ";" << (int)rgb.b << "m"; }
void Color::Set_BG_RGB(RGB rgb) { std::cout << "\033[48;2;" << (int)rgb.r << ";" << (int)rgb.g << ";" << (int)rgb.b << "m"; }
void Color::Set_FG_Pallete(byte id) { std::cout << "\033[38;5;" << (int)id << "m"; }
void Color::Set_BG_Pallete(byte id) { std::cout << "\033[48;5;" << (int)id << "m"; }