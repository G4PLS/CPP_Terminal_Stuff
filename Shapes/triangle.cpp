#include "shape.h"

Triangle::Triangle(Point p, Point p1, Point p2)
{
    this->p = p;
    this->p1 = p1;
    this->p2 = p2;
    this->temp_p = p;
    this->temp_p1 = p1;
    this->temp_p2 = p2;
    Generate_Lines();
}

void Triangle::Set_X(int x)
{
    int diffX;

    diffX = p.Get_X() - x;
    temp_p.Set_X(p.Get_X() - diffX);
    temp_p1.Set_X(p1.Get_X() - diffX);
    temp_p2.Set_X(p2.Get_X() - diffX);    
}

void Triangle::Set_Y(int y)
{
    int diffY;

    diffY = p.Get_Y() - y;
    temp_p.Set_Y(p.Get_Y() - diffY);
    temp_p1.Set_Y(p1.Get_Y() - diffY);
    temp_p2.Set_Y(p2.Get_Y() - diffY);
}

void Triangle::Set_P(Point p) { this->temp_p = p; }

void Triangle::Set_P1(Point p1) { this->temp_p1 = p1; }

void Triangle::Set_P2(Point p2) { this->temp_p2 = p2; }

void Triangle::Draw()
{
    Text::Set_Text_Attribute(text_attribute);
    Text::Set_FG_BG_RGB(fg, bg);

    lines[0].Draw(draw_char[0]);
    lines[1].Draw(draw_char[0]);
    lines[2].Draw(draw_char[0]);

    Text::Reset_All();
}

void Triangle::Redraw()
{
    Delete();
    p = temp_p;
    p1 = temp_p1;
    p2 = temp_p2;
    Generate_Lines();
    Draw();
}

void Triangle::Delete()
{
    Text::Reset_All();
    lines[0].Draw(' ');
    lines[1].Draw(' ');
    lines[2].Draw(' ');
}

void Triangle::Generate_Lines()
{
    lines[0] = Line(p, p1);
    lines[1] = Line(p, p2);
    lines[2] = Line(p1, p2);
}