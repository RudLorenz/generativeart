#include <fstream>
#include <cstddef>
#include <vector>
#include <cstring>
#include <iostream>

#include "bmpgen.h"

int main()
{
    const int WIDTH  = 512;
    const int HEIGHT = 512;

    BitmapImg img(WIDTH, HEIGHT);

    int x_stretch = HEIGHT / 256;
    int y_stretch = WIDTH / 256;

    for (unsigned i = 0; i < HEIGHT; ++i)
    {
        for (unsigned j = 0; j < WIDTH; ++j)
        {
            img(i, j).b = (i / x_stretch) % 256;
            img(i, j).g = ((i + j) / (x_stretch + y_stretch)) % 256;
            img(i, j).r = 255 - (((i + j) / (x_stretch + y_stretch)) % 256);
        }
    }

    img.writeToFile("tst.bmp");
     
    return 0;
}