#pragma once

#include "idrawable.h"
#include "point.h"
#include "line.h"

class Polygon : public IDrawable
{
public:

    Polygon() = delete;
    Polygon(std::vector<Point> points);
    Polygon(std::initializer_list<Point> lst);
    Polygon(std::initializer_list<int>   lst);

    void append(std::initializer_list<Point> lst);

    size_t size() const;

    void draw(BitmapImg &canvas, const IColor &color) const override;

protected:
    static void plotLine    (const Point& p1, const Point& p2, BitmapImg &canvas, const IColor &color);
    static void plotLineLow (const Point& p1, const Point& p2, BitmapImg &canvas, const IColor &color);
    static void plotLineHigh(const Point& p1, const Point& p2, BitmapImg &canvas, const IColor &color);

private:
    std::vector<Point> points_;
};
