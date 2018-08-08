#include <memory>
#include <iostream>

#include "src/bitmapimg.h"
#include "src/point.h"
#include "src/line.h"

int main()
{
    const int WIDTH  = 16;
    const int HEIGHT = 16;

    std::unique_ptr<BitmapImg> img(new BitmapImg(WIDTH, HEIGHT));

    for (unsigned i = 0; i < HEIGHT; ++i) {
        for (unsigned j = 0; j < WIDTH; ++j) {
            (*img)(i, j) = 255;
        }
    }

    std::vector<Line> lines;

    for (unsigned i = 1; i < HEIGHT; ++i) {
        lines.push_back({1, 1, i, HEIGHT-1});
    }

    unsigned dc = 256 / lines.size();
    unsigned color = 0;

    for (auto &item : lines)
    {
        item.draw(*img, color);
        color = (color + dc) % 256; // %256 - overflow protection
    }

    img->writeToFile("tst.bmp");
     
    return 0;
}