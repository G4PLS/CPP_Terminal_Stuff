#include "image.h"
#include <curses.h>

Image::Image(const char *path, Point p, int width, int height)
{
    this->p = p;
    this->width = width;
    this->height = height;
    this->path = path;

    this->temp_p = p;
    this->temp_w = width;
    this->temp_h = height;
}

void Image::Set_X(int x) { temp_p.Set_X(x); }

void Image::Set_Y(int y) { temp_p.Set_Y(y); }

void Image::Set_Width(int width) { temp_w = width; }

void Image::Set_Height(int height) { temp_h = height; }

void Image::Load()
{
    std::ifstream image(path, std::ios::binary | std::ios::ate); // Open file in binary mode and go to end of stream

    if(!image.is_open())
        return;

    std::streamsize size = image.tellg(); // Get the stream size
    image.seekg(0, std::ios::beg);

    unsigned char buffer[size];
    image.read((char*)buffer, size);
    this->image_data = new Text::RGB[size]();

    std::stringstream file_format;

    file_format << std::hex << (int)buffer[0] << (int)buffer[1];

    if(file_format.str() != "5036")
        return;

    bool comment = false;
    bool readRestHeader = true;
    bool readImageData = false;

    std::string width;
    std::string height;
    std::string color;

    int ri;
    int gi;
    int bi;

    for(int i = 2; i < (int)(size / 3); i++)
    {
        if(readImageData)
        {
            Text::RGB rgb((int)buffer[ri], (int)buffer[gi], (int)buffer[bi]);

            image_data[i] = rgb;

            ri += 3;
            gi += 3;
            bi += 3;
        }
        else if((int)buffer[i] == 0x0A)
        {
            comment = false;
            continue;
        }
        else if((int)buffer[i] == 0x23)
        {
            comment = true;
            continue;
        }
        else if(comment)
            continue;
        else if(readRestHeader)
        {
            image.seekg(i);
            image >> width;
            image >> height;
            image >> color;
            readRestHeader = false;
            i = image.tellg();
            ri = i + 1;
            gi = i + 2;
            bi = i + 3;
            i = 0;
            readImageData = true;
        }
    }

    image_loaded = true;
}

void Image::Draw()
{
    if(!image_loaded)
        return;
    for(int y = p.Get_Y(); y < height + p.Get_Y(); y++)
    {
        for(int x = p.Get_X(); x < width + p.Get_X(); x++)
        {
            Write_At_Pos(" ", x, y, image_data[x + y * width], image_data[x + y * width]);
        }
    }
}

void Image::Redraw()
{
    if(!image_loaded)
        return;

    Delete();
    p = temp_p;
    width = temp_w;
    height = temp_h;
    Draw();
}

void Image::Delete()
{
    if(!image_loaded)
        return;

    Text::Reset_All();
    for(int y = 0; y < height; y++)
    {
        for(int x = 0; x < width; x++)
        {
            Write_At_Pos(" ", x, y);
        }
    }
}
