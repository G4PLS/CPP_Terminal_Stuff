#include "shape.h"

Line::Line(int x0, int y0, int x1, int y1)
{
    this->x0 = x0;
    this->y0 = y0;
    this->x1 = x1;
    this->y1 = y1;
}

void Line::Draw(char draw_char)
{
    this->draw_char[0] = draw_char;
    if(abs(y1 - y0) < abs(x1 - x0))
        x0 > x1 ? Draw_Positive_Slope(x1, y1, x0, y0) : Draw_Positive_Slope(x0, y0, x1, y1);
    else 
        y0 > y1 ? Draw_Negative_Slope(x1, y1, x0, y0) : Draw_Negative_Slope(x0, y0, x1, y1);
}

void Line::Draw_Positive_Slope(int x0, int y0, int x1, int y1)
{
    int dx = x1 - x0;
    int dy = y1 - y0;
    int yi = 1;

    if(dy < 0)
    {
        yi = -1;
        dy = -dy;
    }

    int D = (2 * dy) - dx;
    int y = y0;

    for(int x = x0; x < x1; x++)
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

void Line::Draw_Negative_Slope(int x0, int y0, int x1, int y1)
{
    int dx = x1 - x0;
    int dy = y1 - y0;
    int xi = 1;

    if(dx < 0)
    {
        xi = -1;
        dx = -dx;
    }
    int D = (2 * dx) - dy;
    int x = x0;

    for(int y = y0; y <= y1; y++)
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

