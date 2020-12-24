#pragma once

#include "idrawable.h"
#include "icolor.h"

#include <ostream>

class Point : public IDrawable
{
public:
    Point() = default;
    Point(int x, int y);
    Point(const Point& other) = default;
    Point(Point&& other) = default;

    Point& operator=(const Point& other) = default;
    Point& operator=(Point&& other) = default;

    friend std::ostream& operator<<(std::ostream& os, const Point& pt);

    void draw(BitmapImg &canvas, const IColor &color) const override;

    double distance(const Point& p) const;

    int x() const;
    int y() const;

private:
    int x_;
    int y_;
};
