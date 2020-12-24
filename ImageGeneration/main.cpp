#include "bitmapimg.h"
#include "gradient.h"
#include "gradient3.h"
#include "point.h"
#include "ccs.h"
#include "plotfunction.h"
#include "solidcolor.h"

#include <memory>
#include <iostream>
#include <cmath>

int main()
{
    const int WIDTH  = 1000;
    const int HEIGHT = 1000;

    auto triangle = std::make_unique<BitmapImg>(WIDTH, HEIGHT);

    Gradient3 gr_tri({WIDTH / 2, 10}, {10, HEIGHT-10}, {WIDTH-10, HEIGHT-10},
                     {255, 50, 50}, {50, 255, 50}, {50, 50, 255});

    for (unsigned i = 0; i < HEIGHT; ++i)
    {
        for (unsigned j = 0; j < WIDTH; ++j) {
            (*triangle)(i, j) = gr_tri.getcolor(Point(i, j));
        }
    }

    triangle->writeToFile("tst.bmp");

    auto graph = std::make_unique<BitmapImg>(WIDTH, HEIGHT, BGRPalette {255, 255, 255});
    Gradient gr_1({0, HEIGHT/2}, {512, HEIGHT/2}, {255, 0, 0}, {100, 0, 255});
    const auto ccs = CCS(Point{200, 700}, 50);
    ccs.draw(*graph, gr_1);

    const auto func = [] (double x) -> double {
        return sin(x) * x * x;
    };
    const auto plot = PlotFunction(ccs, func);
    plot.draw(*graph, gr_1);

    graph->writeToFile("graph.bmp");

    std::cout << "Done!" << std::endl;
     
    return 0;
}