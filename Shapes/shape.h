#ifndef SHAPE_H
#define SHAPE_H

#include "../terminal_utils.h"

class Shape
{
    protected:
    int x = 1;
    int y = 1;
    char draw_char[2] = {' ', '\0'};
    Text::RGB fg = Text::WHITE;
    Text::RGB bg = Text::BLACK;
    Text::Text_Attribute text_attribute = Text::DEFAULT;

    public:
    void Set_X(int x) { this->x = x; }
    void Set_Y(int y) { this->y = y; }
    void Set_Draw_Char(char draw_char) { this->draw_char[0] = draw_char; }
    void Set_FG(Text::RGB fg) { this->fg = fg; }
    void Set_BG(Text::RGB bg) { this->bg = bg; }
    void Set_Text_Attribute(Text::Text_Attribute attribute) { this->text_attribute = attribute; }
    virtual void Draw() = 0;
    virtual void Redraw() = 0;
    virtual void Delete() = 0;
};

class Line
{
    private:
    int x0;
    int y0;
    int x1;
    int y1;
    char draw_char[2] = {' ', '\0'};

    void Draw_Positive_Slope(int, int, int, int);
    void Draw_Negative_Slope(int, int, int, int);

    public:
    Line(){}
    Line(int x0, int y0, int x1, int y1);

    void Draw(char draw_char);
    void Delete();
};

class Rect : public Shape
{
    private:
    int width;
    int height;
    Line lines[4];

    public:
    Rect(int x, int y, int width, int height);
    void Generate_Lines();
    void Draw() override;
    void Redraw() override;
    void Delete() override;
};

class Mid_Point_Rect : public Shape
{
    private:
    int radius = 1;
    int xc;
    int yc;
    int temp_x = -1;
    int temp_y = -1;
    int temp_r = -1;
    void Place_Points();

    public:
    Mid_Point_Rect(int x, int y, int radius);
    void Set_X(int x);
    void Set_Y(int y);
    void Set_Radius(int radius);
    void Draw() override;
    void Redraw() override;
    void Delete() override;
};

class Circle : public Shape
{
    private:
    int radius;
    int xc;
    int yc;
    int temp_x;
    int temp_y;
    int temp_r;
    void Place_Points();

    public:
    Circle(int xc, int yc, int radius);
    void Set_X(int x);
    void Set_Y(int y);
    void Set_Radius(int radius);
    void Draw() override;
    void Redraw() override;
    void Delete() override;

};

class Ellipse : public Shape
{
    private:
    int rx;
    int ry;
    int xc;
    int yc;
    int temp_x;
    int temp_y;
    int temp_rx;
    int temp_ry;
    void Draw_Points();

    public:
    Ellipse(int xc, int yc, int rx, int ry);
    void Set_X(int x);
    void Set_Y(int y);
    void Set_Radius_X(int rx);
    void Set_Radius_Y(int ry);

    void Draw() override;
    void Redraw() override;
    void Delete() override;
 
};

#endif