#ifndef HELPER_H
#define HELPER_H

#include <iostream>
#include <cstring>

struct FG_Color
{
    static const char BLACK[];
    static const char RED[];
    static const char GREEN[];
    static const char ORANGE[];
    static const char BLUE[];
    static const char MAGENTA[];
    static const char CYAN[];
    static const char LIGHT_GRAY[];
    static const char NONE[];
};

struct BG_Color
{
    static const char BLACK[];
    static const char RED[];
    static const char GREEN[];
    static const char ORANGE[];
    static const char BLUE[];
    static const char MAGENTA[];
    static const char CYAN[];
    static const char LIGHT_GRAY[];
    static const char DARK_GRAY[];
    static const char LIGHT_RED[];
    static const char LIGHT_GREEN[];
    static const char YELLOW[];
    static const char LIGHT_BLUE[];
    static const char LIGHT_PURPLE[];
    static const char TEAL[];
    static const char WHITE[];
    static const char NONE[];
};

void Set_Cursor(int x, int y);
void Move_Up(int amount);
void Move_Down(int amount);
void Move_Forward(int amount);
void Move_Back(int amount);
void Clear();
void Erase_Line();
void Save_Cursor_Pos();
void Load_Cursor_Pos();

void Write_At_Pos(char message[], int x, int y, const char fg[], const char bg[]);
void Delete_At_Pos(int x, int y);
void Delete_Mult_At_Pos(int amount, int x, int y);
void Erase_Line_At_Pos(int y);

#endif