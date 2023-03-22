#include "shape.h"

Circle::Circle(int xc, int yc, int radius)
{
    this->xc = xc;
    this->yc = yc;
    this->radius = radius;
    this->temp_x = xc;
    this->temp_y = yc;
    this->temp_r = radius;
}

void Circle::Set_X(int x)
{
    this->temp_x = x;
}

void Circle::Set_Y(int y)
{
    this->temp_y = y;
}

void Circle::Set_Radius(int radius)
{
    temp_r = radius;
}

void Circle::Draw()
{
    Text::Set_Text_Attribute(text_attribute);
    Text::Set_FG_BG_RGB(fg, bg);

    x = 0;
    y = radius;
    int d = 3 - (2 * radius);
    Place_Points(draw_char, x, y);

    while(x <= y)
    {
        if(d <= 0)
            d = d + ( 4 * x ) + 6;
        else
        {
            d = d + (4 * x) - (4 * y) + 10;
            y--;
        }
        x++;
        Place_Points(draw_char, x, y);
    }

    Text::Reset_All();
}

void Circle::Redraw()
{
    Delete();
    this->xc = temp_x;
    this->yc = temp_y;
    this->radius = temp_r;
    Draw();
}

void Circle::Delete()
{
    Text::Reset_All();

    x = 0;
    y = radius;
    int d = 3 - (2 * radius);
    Place_Points(" ", x, y);

    while(x <= y)
    {
        if(d <= 0)
            d = d + ( 4 * x ) + 6;
        else
        {
            d = d + (4 * x) - (4 * y) + 10;
            y--;
        }
        x++;
        Place_Points(" ", x, y);
    }
}

void Circle::Place_Points(char draw_char[2], int x, int y)
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