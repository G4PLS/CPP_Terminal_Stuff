#include "shape.h"

Rect::Rect(int x, int y, int width, int height)
{
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;

    Generate_Lines();
}

void Rect::Generate_Lines()
{
    lines[0] = Line(x, y, x + width, y); //TL-TR
    lines[1] = Line(x, y, x, y + height); //TÖ-BL
    lines[2] = Line(x + width, y, x + width, y + height); //TR-BR
    lines[3] = Line(x, y + height, x + width, y + height); //BL-BR
}

void Rect::Draw()
{
    Text::Set_Text_Attribute(text_attribute);
    Text::Set_FG_BG_RGB(fg, bg);

    lines[0].Draw(draw_char[0]);
    lines[1].Draw(draw_char[0]);
    lines[2].Draw(draw_char[0]);
    lines[3].Draw(draw_char[0]);

    Text::Reset_All();
}

void Rect::Redraw()
{
    Delete();
    Generate_Lines();
    Draw();
}

void Rect::Delete()
{
    Text::Reset_All();
    lines[0].Draw(' ');
    lines[1].Draw(' ');
    lines[2].Draw(' ');
    lines[3].Draw(' ');
}

Mid_Point_Rect::Mid_Point_Rect(int x, int y, int radius)
{
    this->xc = x;
    this->yc = y;
    this->radius = radius;
    this->temp_x = xc;
    this->temp_y = yc;
    this->temp_r = radius;
}

void Mid_Point_Rect::Set_X(int x)
{
    this->temp_x = x;
}

void Mid_Point_Rect::Set_Y(int y)
{
    this->temp_y = y;
}

void Mid_Point_Rect::Set_Radius(int radius)
{
    this->temp_r = radius;
}

void Mid_Point_Rect::Draw()
{
    Text::Set_Text_Attribute(text_attribute);
    Text::Set_FG_BG_RGB(fg, bg);

    x = 0;

    while(x <= radius)
    {
        Place_Points(draw_char, x, radius);
        x++;
    }

    Text::Reset_All();
}

void Mid_Point_Rect::Redraw()
{
    Delete();
    xc = temp_x;
    yc = temp_y;
    radius = temp_r;
    Draw();
}

void Mid_Point_Rect::Delete()
{
    Text::Reset_All();

    x = 0;

    while(x <= radius)
    {
        Place_Points(" ", x, radius);
        x++;
    }
}

void Mid_Point_Rect::Place_Points(char draw_char[2], int x, int y)
{
    Write_At_Pos(draw_char,  x + xc,  y + yc);
    Write_At_Pos(draw_char,  x + xc, -y + yc);
    Write_At_Pos(draw_char, -x + xc, -y + yc);
    Write_At_Pos(draw_char, -x + xc,  y + yc);
    Write_At_Pos(draw_char,  y + xc,  x + yc);
    Write_At_Pos(draw_char,  y + xc, -x + yc);
    Write_At_Pos(draw_char, -y + xc, -x + yc);
    Write_At_Pos(draw_char, -y + xc,  x + yc);
}