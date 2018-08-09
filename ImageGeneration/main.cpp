#include <memory>
#include <iostream>

#include "src/bitmapimg.h"
#include "src/point.h"
#include "src/line.h"
#include "src/polygon.h"

int main()
{
    const int WIDTH  = 32;
    const int HEIGHT = 32;

    std::unique_ptr<BitmapImg> img(new BitmapImg(WIDTH, HEIGHT));

    for (unsigned i = 0; i < HEIGHT; ++i) {
        for (unsigned j = 0; j < WIDTH; ++j) {
            (*img)(i, j) = 255;
        }
    }

    //Polygon poly {{4, 10}, {12, 2}, {20, 10}, {16, 18}, {8, 18}};

    Polygon poly {4, 10, 12, 2, 20, 10, 16, 18, 8, 18};

    poly.draw(*img, {0, 0, 255});

    img->writeToFile("tst.bmp");
     
    return 0;
}