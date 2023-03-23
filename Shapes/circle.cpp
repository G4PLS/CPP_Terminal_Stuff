#include "shape.h"

Circle::Circle(Point p, int radius)
{
    this->p = p;
    this->radius = radius;
    this->temp_p = p;
    this->temp_r = radius;
}

void Circle::Set_X(int x) { this->temp_p.Set_X(x); }

void Circle::Set_Y(int y) { this->temp_p.Set_Y(y); }

void Circle::Set_Radius(int radius) { temp_r = radius; }

void Circle::Draw()
{
    Text::Set_Text_Attribute(text_attribute);
    Text::Set_FG_BG_RGB(fg, bg);

    Place_Points();

    Text::Reset_All();
}

void Circle::Redraw()
{
    Delete();
    this->p = this->temp_p;
    this->radius = temp_r;
    Draw();
}

void Circle::Delete()
{
    Text::Reset_All();

    char temp = draw_char[0];
    draw_char[0] = ' ';
    Place_Points();
    draw_char[0] = temp;
}

void Circle::Place_Points()
{
    int x = 0;
    int y = radius;
    int xc = p.Get_X();
    int yc = p.Get_Y();
    int d = 3 - (2 * radius);

    Write_At_Pos(draw_char,  x + xc,  y + yc);
    Write_At_Pos(draw_char,  x + xc, -y + yc);
    Write_At_Pos(draw_char, -x + xc, -y + yc);
    Write_At_Pos(draw_char, -x + xc,  y + yc);
    Write_At_Pos(draw_char,  y + xc,  x + yc);
    Write_At_Pos(draw_char,  y + xc, -x + yc);
    Write_At_Pos(draw_char, -y + xc, -x + yc);
    Write_At_Pos(draw_char, -y + xc,  x + yc);

    while(x <= y)
    {
        if(d <= 0)
            d += ( 4 * x ) + 6;
        else
        {
            d += (4 * x) - (4 * y) + 10;
            y--;
        }
        x++;
        Write_At_Pos(draw_char,  x + xc,  y + yc);
        Write_At_Pos(draw_char,  x + xc, -y + yc);
        Write_At_Pos(draw_char, -x + xc, -y + yc);
        Write_At_Pos(draw_char, -x + xc,  y + yc);
        Write_At_Pos(draw_char,  y + xc,  x + yc);
        Write_At_Pos(draw_char,  y + xc, -x + yc);
        Write_At_Pos(draw_char, -y + xc, -x + yc);
        Write_At_Pos(draw_char, -y + xc,  x + yc);
    }
}



Ellipse::Ellipse(Point p, int rx, int ry)
{
    this->p = p;
    this->temp_p = p;
    this->rx = rx;
    this->ry = ry;
    this->temp_rx = rx;
    this->temp_ry = ry;
}

void Ellipse::Set_X(int x) { this->temp_p.Set_X(x); }

void Ellipse::Set_Y(int y) { this->temp_p.Set_Y(y); }

void Ellipse::Set_Radius_X(int rx) { temp_rx = rx; }

void Ellipse::Set_Radius_Y(int ry) { temp_ry = ry; }

void Ellipse::Draw()
{
    Text::Set_Text_Attribute(text_attribute);
    Text::Set_FG_BG_RGB(fg, bg);
    Draw_Points();   
    Text::Reset_All();
}

void Ellipse::Redraw()
{
    Delete();
    p = temp_p;
    rx = temp_rx;
    ry = temp_ry;
    Draw();
}

void Ellipse::Delete()
{
    Text::Reset_All();

    char temp = draw_char[0];
    draw_char[0] = ' ';
    Draw_Points();
    draw_char[0] = temp;
}

void Ellipse::Draw_Points()
{
    int x = 0;
    int y = ry;
    int xc = p.Get_X();
    int yc = p.Get_Y();

    int D = (ry * ry) - (rx * rx * ry) + (0.25 * rx * rx);

    do
    {
        Write_At_Pos(draw_char,  x + xc,  y + yc);
        Write_At_Pos(draw_char,  x + xc, -y + yc);
        Write_At_Pos(draw_char, -x + xc,  y + yc);
        Write_At_Pos(draw_char, -x + xc, -y + yc);

        if(D < 0)
        {
            x++;
            D += 2 * ((ry * ry) * x) + (ry * ry);
        }
        else{
            x++;
            y--;
            D += 2 * ((ry * ry) * x) - 2 * ((x * x) * y) + (ry * ry);
        }
    }while(2 * ((ry * ry) * x) < 2 * ((rx * rx) * y));

    D = ((ry * ry) * (x + 0.5) * (x + 0.5)) + ((y - 1) * (y - 1) * (rx * rx) - ((rx * rx) * (ry * ry)));

    do
    {
        Write_At_Pos(draw_char,  x + xc,  y + yc);
        Write_At_Pos(draw_char,  x + xc, -y + yc);
        Write_At_Pos(draw_char, -x + xc,  y + yc);
        Write_At_Pos(draw_char, -x + xc, -y + yc);

        if(D > 0)
        {
            y--;
            D -= 2 * ((rx * rx) * y) + (rx * rx);
        }
        else {
            x++;
            y--;
            D -= 2 * ((rx * rx) * y) + 2 * ((ry * ry) * x) + (rx * rx);
        }
    }while (y >= 0);
}