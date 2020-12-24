#include <memory>
#include <iostream>

#include "bitmapimg.h"
#include "gradient.h"
#include "gradient3.h"
#include "line.h"
#include "point.h"
#include "polygon.h"


int main()
{
    const int WIDTH  = 512;
    const int HEIGHT = 512;

    std::unique_ptr<BitmapImg> img(new BitmapImg(WIDTH, HEIGHT));

    Gradient gr_1({0, HEIGHT/2}, {512, HEIGHT/2}, {255, 0, 0}, {100, 0, 255});

    Gradient3 gr_tri({WIDTH / 2, 10}, {10, HEIGHT-10}, {WIDTH-10, HEIGHT-10},
                     {255, 50, 50}, {50, 255, 50}, {50, 50, 255});

    for (unsigned i = 0; i < HEIGHT; ++i)
    {
        for (unsigned j = 0; j < WIDTH; ++j) {
            (*img)(i, j) = gr_tri.getcolor(Point(i, j));
        }
    }

    img->writeToFile("tst.bmp");
    std::cout << "Done!" << std::endl;
     
    return 0;
}