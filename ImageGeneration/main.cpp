#include <fstream>
#include <cstddef>
#include <vector>
#include <cstring>
#include <iostream>

#include "bmpgen.h"

int main()
{
    const int HEIGHT = 512;
    const int WIDTH  = 512;

    auto padding = (4 - (WIDTH % 4)) % 4;

    std::vector<BGRPalette> clr((WIDTH + padding) * HEIGHT);

    int x_stretch = HEIGHT / 256;
    int y_stretch = WIDTH / 256;

    for (unsigned i = 0; i < HEIGHT; ++i)
    {
        for (unsigned j = 0; j < WIDTH; ++j)
        {
            clr[i*WIDTH + j].b = 255;
            clr[i*WIDTH + j].g = ((i + j) / (x_stretch + y_stretch)) % 256;
            clr[i*WIDTH + j].r = 255 - (((i + j) / (x_stretch + y_stretch)) % 256);
        }
    }

    bmp_generator("tst.bmp", WIDTH, HEIGHT, clr);
     
    return 0;
}