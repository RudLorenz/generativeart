#pragma once

#include "bmpheader.h"
#include "icolor.h"
#include "point.h"

class Gradient3 : public IColor
{
public:
    Gradient3() = delete;

    Gradient3(
        Point p1,
        Point p2,
        Point p3,
        const BGRPalette &color1,
        const BGRPalette &color2,
        const BGRPalette &color3
    );

    BGRPalette getcolor(int x, int y)   const override;
    BGRPalette getcolor(const Point &p) const;

private:
    double sign(const Point &p1, const Point &p2, const Point &p3) const;
    bool inside(const Point &p) const;

private:
    Point p1_;
    Point p2_;
    Point p3_;
    BGRPalette color1_;
    BGRPalette color2_;
    BGRPalette color3_;
};
