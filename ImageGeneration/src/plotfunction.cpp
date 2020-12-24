#include "plotfunction.h"

#include "line.h"

#include <utility>

PlotFunction::PlotFunction(CCS ccs, std::function<double(double)> func)
    : ccs_(std::move(ccs))
    , func_(std::move(func))
{
}

void PlotFunction::draw(BitmapImg& canvas, const IColor& color) const
{
    const double height = canvas.getHeight();
    const double width  = canvas.getWidth();

    const auto clamp = [](auto val, auto limit) {
        if (val < 0) { return 0; }
        if (val > limit) { return static_cast<int>(limit-1); }
        return val;
    };

    const double MINX = static_cast<double>(-ccs_.center().x()) / static_cast<double>(ccs_.scale());
    const double MINY = (ccs_.center().y() - height) / ccs_.scale();
    const double MAXX = (width - ccs_.center().x()) / ccs_.scale();
    const double MAXY = ccs_.center().y() / ccs_.scale();
    const double dx_rate = 0.01;

    std::vector<Point> result;
    result.reserve((MAXX - MINX) / dx_rate);

    for (double dx = MINX; dx < MAXX; dx += dx_rate) {
        int res_x = static_cast<int>((dx - MINX) / (MAXX - MINX) * width);
        int res_y = height - static_cast<int>((func_(dx) - MINY) / (MAXY - MINY) * height);

        auto rslt = Point{clamp(res_x, width), clamp(res_y, height)};

        result.emplace_back(rslt);
    }

    // TODO draw arcs with help of Bezier curves instead of this
    for (auto i = 1; i < result.size(); i++) {
        const auto ln = Line(result[i-1], result[i]);
        ln.draw(canvas, color);
    }

}
