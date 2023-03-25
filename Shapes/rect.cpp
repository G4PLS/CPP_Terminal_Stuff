#include "shape.h"

Rect::Rect(Point p, int width, int height)
{
    this->p = p;
    this->temp_p = p;
    this->width = width;
    this->height = height;
    this->temp_width = width;
    this->temp_height = height;

    Generate_Lines();
}

Rect::Rect(Point p, Point p1)
{
    this->p = p;
    this->temp_p = p;

    this->width = p1.Get_X() - p.Get_X();
    this->height = p1.Get_Y() - p.Get_Y();

    Generate_Lines();
}

void Rect::Set_X(int x) { this->temp_p.Set_X(x); }

void Rect::Set_Y(int y) { this->temp_p.Set_Y(y); }

void Rect::Set_Width(int width) { this->temp_width = width; }

void Rect::Set_Height(int height) { this->temp_height = height; }

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
    p = temp_p;
    width = temp_width;
    height = temp_height;
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

void Rect::Generate_Lines()
{
    lines[0] = Line(p, Point(p.Get_X() + width, p.Get_Y())); //TL-TR
    lines[1] = Line(p, Point(p.Get_X(), p.Get_Y() + height)); //TL-BL
    lines[2] = Line(Point(p.Get_X() + width, p.Get_Y()), Point(p.Get_X() + width, p.Get_Y() + height)); //TR-BR
    lines[3] = Line(Point(p.Get_X(), p.Get_Y() + height), Point(p.Get_X() + width, p.Get_Y() + height)); //BL-BR
}



Mid_Point_Rect::Mid_Point_Rect(Point p, int radius)
{
    this->p = p;
    this->radius = radius;
    this->temp_p = p;
    this->temp_r = radius;
}

void Mid_Point_Rect::Set_X(int x) { this->temp_p.Set_X(x); }

void Mid_Point_Rect::Set_Y(int y) { this->temp_p.Set_Y(y); }

void Mid_Point_Rect::Set_Radius(int radius) { this->temp_r = radius; }

void Mid_Point_Rect::Draw()
{
    Text::Set_Text_Attribute(text_attribute);
    Text::Set_FG_BG_RGB(fg, bg);

    Place_Points();

    Text::Reset_All();
}

void Mid_Point_Rect::Redraw()
{
    Delete();
    p = temp_p;
    radius = temp_r;
    Draw();
}

void Mid_Point_Rect::Delete()
{
    Text::Reset_All();

    char temp = draw_char[0];
    draw_char[0] = ' ';
    Place_Points();
    draw_char[0] = temp;
}

void Mid_Point_Rect::Place_Points()
{
    int x = 0;
    int xc = p.Get_X();
    int yc = p.Get_Y();

    while(x <= radius)
    {
        Write_At_Pos(draw_char,  x + xc,  radius + yc);
        Write_At_Pos(draw_char,  x + xc, -radius + yc);
        Write_At_Pos(draw_char, -x + xc, -radius + yc);
        Write_At_Pos(draw_char, -x + xc,  radius + yc);
        Write_At_Pos(draw_char,  radius + xc,  x + yc);
        Write_At_Pos(draw_char,  radius + xc, -x + yc);
        Write_At_Pos(draw_char, -radius + xc, -x + yc);
        Write_At_Pos(draw_char, -radius + xc,  x + yc);
        x++;
    }
}