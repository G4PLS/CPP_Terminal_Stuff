#include "helper.h"

const char FG_Color::BLACK[]       = "\033[30m";
const char FG_Color::RED[]         = "\033[31m";
const char FG_Color::GREEN[]       = "\033[32m";
const char FG_Color::ORANGE[]      = "\033[33m";
const char FG_Color::BLUE[]        = "\033[34m";
const char FG_Color::MAGENTA[]     = "\033[35m";
const char FG_Color::CYAN[]        = "\033[36m";
const char FG_Color::LIGHT_GRAY[]  = "\033[37m";
const char FG_Color::NONE[]        = "\033[39m";

const char BG_Color::BLACK[]        = "\033[40m";
const char BG_Color::RED[]          = "\033[41m";
const char BG_Color::GREEN[]        = "\033[42m";
const char BG_Color::ORANGE[]       = "\033[43m";
const char BG_Color::BLUE[]         = "\033[44m";
const char BG_Color::MAGENTA[]      = "\033[45m";
const char BG_Color::CYAN[]         = "\033[46m";
const char BG_Color::LIGHT_GRAY[]   = "\033[47m";
const char BG_Color::NONE[]         = "\033[49m";
const char BG_Color::DARK_GRAY[]    = "\033[100m";
const char BG_Color::LIGHT_RED[]    = "\033[101m";
const char BG_Color::LIGHT_GREEN[]  = "\033[102m";
const char BG_Color::YELLOW[]       = "\033[103m";
const char BG_Color::LIGHT_BLUE[]   = "\033[104m";
const char BG_Color::LIGHT_PURPLE[] = "\033[105m";
const char BG_Color::TEAL[]         = "\033[106m";
const char BG_Color::WHITE[]        = "\033[107m";

void Set_Cursor(int x, int y)  { std::cout << "\033[" << y << ";" << x << "f"; }
void Move_Up(int amount)       { std::cout << "\033[" << amount << "A"; }
void Move_Down(int amount)     { std::cout << "\033[" << amount << "B"; }
void Move_Forward(int amount)  { std::cout << "\033[" << amount << "C"; }
void Move_Back(int amount)     { std::cout << "\033[" << amount << "D"; }
void Clear()                   { std::cout << "\033[2J"; }
void Erase_Line()          { std::cout << "\033[K"; }
void Save_Cursor_Pos()         { std::cout << "\033[s"; }
void Load_Cursor_Pos()         { std::cout << "\033[u"; }

void Write_At_Pos(char message[], int x, int y, const char fg[], const char bg[])
{
    Set_Cursor(x, y);
    std::cout << fg << bg << message << FG_Color::NONE << BG_Color::NONE;
}

void Delete_At_Pos(int x, int y)
{
    Set_Cursor(x, y);
    std::cout << FG_Color::NONE << BG_Color::NONE << " ";
}

void Delete_Mult_At_Pos(int amount, int x, int y)
{
    Set_Cursor(x, y);
    char filler[amount];
    std::memset(&filler, ' ', sizeof(filler));
    filler[amount - 1] = '\0';
    std::cout << filler;
}

void Erase_Line_At_Pos(int y)
{
    Set_Cursor(0, y);
    Erase_Line();
}