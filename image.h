#ifndef IMAGE_H
#define IMAGE_H

#include <fstream>
#include <sstream>
#include <string>
#include "terminal_utils.h"
#include "Shapes/shape.h"

//ONLY PPM P6 SUPPORTED
class Image
{
    private:
    const char *path;
    Point p;
    Point temp_p;
    int width;
    int height;
    int temp_w;
    int temp_h;
    bool image_loaded;
    Text::RGB *image_data;

    public:
    Image(const char *path, Point p, int width, int height);
    void Set_X(int x);
    void Set_Y(int y);
    void Set_Width(int width);
    void Set_Height(int height);
    void Load();
    void Draw();
    void Redraw();
    void Delete();
};

#endif