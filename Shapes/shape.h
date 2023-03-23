#ifndef SHAPE_H
#define SHAPE_H

#include "../terminal_utils.h"

class Point
{
    int x = 0;
    int y = 0;

    public:
    Point(int x, int y) { this->x = x; this->y = y; }
    Point() {}
    void Set_X(int x) { this->x = x; }
    void Set_Y(int y) { this->y = y; }
    int Get_X() { return x; }
    int Get_Y() { return y; }
};

class Shape
{
    protected:
    Point p = Point(0, 0);
    char draw_char[2] = {' ', '\0'};
    Text::RGB fg = Text::WHITE;
    Text::RGB bg = Text::BLACK;
    Text::Text_Attribute text_attribute = Text::DEFAULT;

    public:
    void Set_X(int x) { this->p.Set_X(x); }
    void Set_Y(int y) { this->p.Set_Y(y); }
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
    Point p;
    Point p2;
    char draw_char[2] = {' ', '\0'};
    void Draw_Positive_Slope(Point p, Point p2);
    void Draw_Negative_Slope(Point p, Point p2);

    public:
    Line(){}
    Line(Point p1, Point p2);
    void Draw(char draw_char);
    void Delete();
};

class Rect : public Shape
{
    private:
    Point temp_p;
    int width = 1;
    int height = 1;
    int temp_width;
    int temp_height;
    Line lines[4];

    public:
    Rect(Point p, int width, int height);
    void Set_X(int x);
    void Set_Y(int y);
    void Set_Width(int widht);
    void Set_Height(int height);
    void Generate_Lines();
    void Draw() override;
    void Redraw() override;
    void Delete() override;
};

class Mid_Point_Rect : public Shape
{
    private:
    Point temp_p;
    int radius = 1;
    int temp_r;
    void Place_Points();

    public:
    Mid_Point_Rect(Point p, int radius);
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
    Point temp_p;
    int radius;
    int temp_r;
    void Place_Points();

    public:
    Circle(Point p, int radius);
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
    Point temp_p;
    int rx;
    int ry;
    int temp_rx;
    int temp_ry;
    void Draw_Points();

    public:
    Ellipse(Point p, int rx, int ry);
    void Set_X(int x);
    void Set_Y(int y);
    void Set_Radius_X(int rx);
    void Set_Radius_Y(int ry);
    void Draw() override;
    void Redraw() override;
    void Delete() override;
 
};

class Triangle : public Shape
{
    private:
    Point p1;
    Point p2;
    Point temp_p;
    Point temp_p1;
    Point temp_p2;
    Line lines[3];
    void Generate_Lines();

    public:
    Triangle(Point p, Point p1, Point p2);
    void Set_X(int x);
    void Set_Y(int y);
    void Set_P(Point p);
    void Set_P1(Point p1);
    void Set_P2(Point p2);
    void Draw() override;
    void Redraw() override;
    void Delete() override;
};

#endif