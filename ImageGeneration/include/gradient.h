#pragma once

#include "bmpheader.h"
#include "icolor.h"
#include "point.h"

class Gradient : public IColor
{
public:
    Gradient() = delete;

    Gradient(
        const Point& p1,
        const Point& p2,
        const BGRPalette& start_c,
        const BGRPalette& end_c
    );

    BGRPalette getcolor(int x, int y) const override;
    BGRPalette getcolor(const Point& p) const;

private:
    double x_cf_;
    double y_cf_;
    double c1_;
    double c2_;
    BGRPalette start_;
    BGRPalette end_;
};
