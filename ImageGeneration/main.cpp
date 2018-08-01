#include <memory>
#include <iostream>

#include "bmpgen.h"

int main()
{
    const int WIDTH  = 512;
    const int HEIGHT = 512;

    std::unique_ptr<BitmapImg> img(new BitmapImg(WIDTH, HEIGHT));

    int x_stretch = WIDTH  / 256;
    int y_stretch = HEIGHT / 256;

    for (unsigned i = 0; i < HEIGHT; ++i)
    {
        for (unsigned j = 0; j < WIDTH; ++j)
        {
            (*img)(i, j).b = (i / y_stretch) % 256;
            (*img)(i, j).g = ((i + j) / (x_stretch + y_stretch)) % 256;
            (*img)(i, j).r = 255 - (((i + j) / (x_stretch + y_stretch)) % 256);
        }
    }

    std::unique_ptr<BitmapImg> img_2(new BitmapImg(WIDTH, HEIGHT));

    for (unsigned i = 0; i < HEIGHT; ++i)
    {
        for (unsigned j = 0; j < WIDTH; ++j)
        {
            (*img_2)(i, j).r = 0;
            (*img_2)(i, j).g = 0;
            (*img_2)(i, j).b = 0;
        }
    }

     
    return 0;
}