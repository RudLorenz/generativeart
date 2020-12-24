#pragma once

#include "idrawable.h"
#include "point.h"

class Line : public IDrawable
{
public:
    Line() = default;
    Line(Point  p1, Point  p2);
    Line(int x1, int y1, int x2, int y2);

    void draw(BitmapImg &canvas, const IColor &color) const override;

private:
    static void plotLineLow (const Point& p1, const Point& p2, BitmapImg &canvas, const IColor &color);
    static void plotLineHigh(const Point& p1, const Point& p2, BitmapImg &canvas, const IColor &color);

private:
    Point p1_;
    Point p2_;
};
