#include "shape.h"

Line::Line(Point p1, Point p2)
{
    this->p = p1;
    this->p2 = p2;
}

void Line::Draw(char draw_char)
{
    this->draw_char[0] = draw_char;
    if(abs(p2.Get_Y() - p.Get_Y()) < abs(p2.Get_X() - p.Get_X()))
        p.Get_X() > p2.Get_X() ? Draw_Positive_Slope(p2, p) : Draw_Positive_Slope(p, p2);
    else 
        p.Get_Y() > p2.Get_Y() ? Draw_Negative_Slope(p2, p) : Draw_Negative_Slope(p, p2);
}

void Line::Delete()
{
    Text::Reset_All();
    
    this->draw_char[0] = ' ';
    if(abs(p2.Get_Y() - p.Get_Y()) < abs(p2.Get_X() - p.Get_X()))
        p.Get_X() > p2.Get_X() ? Draw_Positive_Slope(p2, p) : Draw_Positive_Slope(p, p2);
    else 
        p.Get_Y() > p2.Get_Y() ? Draw_Negative_Slope(p2, p) : Draw_Negative_Slope(p, p2);
}

void Line::Draw_Positive_Slope(Point p, Point p2)
{
    int dx = p2.Get_X() - p.Get_X();
    int dy = p2.Get_Y() - p.Get_Y();
    int yi = 1;

    if(dy < 0)
    {
        yi = -1;
        dy = -dy;
    }

    int D = (2 * dy) - dx;
    int y = p.Get_Y();

    for(int x = p.Get_X(); x <= p2.Get_X(); x++)
    {
        Write_At_Pos(draw_char, x, y);

        if(D > 0)
        {
            y += yi;
            D += (2 * (dy - dx));
        }
        else
            D += 2 * dy;
    }
}

void Line::Draw_Negative_Slope(Point p, Point p2)
{
    int dx = p2.Get_X() - p.Get_X();
    int dy = p2.Get_Y() - p.Get_Y();
    int xi = 1;

    if(dx < 0)
    {
        xi = -1;
        dx = -dx;
    }
    int D = (2 * dx) - dy;
    int x = p.Get_X();

    for(int y = p.Get_Y(); y <= p2.Get_Y(); y++)
    {    
        Write_At_Pos(draw_char, x, y);

        if(D > 0)
        {
            x += xi;
            D += (2 * (dx - dy));
        }
        else 
            D += 2 * dx;
    }
}
