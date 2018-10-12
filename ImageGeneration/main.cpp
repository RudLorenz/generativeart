#include <memory>
#include <iostream>

#include "src/bitmapimg.h"
#include "src/point.h"
#include "src/line.h"
#include "src/polygon.h"
#include "src/gradient.h"

int main()
{
    const int WIDTH  = 512;
    const int HEIGHT = 512;

    std::unique_ptr<BitmapImg> img(new BitmapImg(WIDTH, HEIGHT));

    Gradient gr_1({0, HEIGHT/2}, {512, HEIGHT/2}, {255, 0, 0}, {100, 0, 255});


    for (unsigned i = 0; i < HEIGHT; ++i)
    {
        for (unsigned j = 0; j < WIDTH; ++j) {
            (*img)(i, j) = gr_1.getcolor(Point(i, j));
        }
    }

    img->writeToFile("tst.bmp");
     
    return 0;
}