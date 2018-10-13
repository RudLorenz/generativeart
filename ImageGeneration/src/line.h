#ifndef LINE_H
#define LINE_H

#include <cmath>
#include <vector>
#include <utility>

#include "idrawable.h"
#include "point.h"

class Line : public IDrawable
{
public:
    Line();
    Line(const Point& p1, const Point& p2);
    Line(int x1, int y1, int x2, int y2);

    void draw(BitmapImg &canvas, const IColor &color) override;

private:

    void plotLineLow (const Point& p1, const Point& p2, BitmapImg &canvas, const IColor &color);
    void plotLineHigh(const Point& p1, const Point& p2, BitmapImg &canvas, const IColor &color);

    Point p1_;
    Point p2_;
};


Line::Line() : p1_(), p2_()
{
}


Line::Line(const Point &p1, const Point &p2)
: p1_(p1), p2_(p2)
{
}


Line::Line(int x1, int y1, int x2, int y2)
: p1_(x1, y1), p2_(x2, y2)
{
}


void Line::draw(BitmapImg &canvas, const IColor &color)
{
    if (std::abs(p2_.y() - p1_.y()) < std::abs(p2_.x() - p1_.x()))
    {
        if (p1_.x() > p2_.x()) {
            plotLineLow(p2_, p1_, canvas, color);
        }
        else {
            plotLineLow(p1_, p2_, canvas, color);
        }
    }
    else
    {
        if (p1_.y() > p2_.y()) {
            plotLineHigh(p2_, p1_, canvas, color);
        }
        else {
            plotLineHigh(p1_, p2_, canvas, color);
        }
    }
}


void Line::plotLineLow(const Point& p1, const Point& p2, BitmapImg &canvas, const IColor &color)
{
    int dx = p2.x() - p1.x();
    int dy = p2.y() - p1.y();

    int y_sign = 1;

    if (dy < 0)
    {
        y_sign = -1;
        dy = -dy;
    }

    int approx = 2 * dy - dx;
    int y_step = p1.y();

    for (int x_step = p1.x(); x_step <= p2.x(); ++x_step)
    {
        canvas(x_step, y_step) = color.getcolor(x_step, y_step);  // TODO add sign + range check

        if (approx > 0)
        {
            y_step = y_step + y_sign;
            approx = approx - 2 * dx;
        }

        approx = approx + 2 * dy;
    }
}


void Line::plotLineHigh(const Point& p1, const Point& p2, BitmapImg &canvas, const IColor &color)
{
    int dx = p2.x() - p1.x();
    int dy = p2.y() - p1.y();

    int x_sign = 1;

    if (dx < 0)
    {
        x_sign = -1;
        dx = -dx;
    }

    int approx = 2 * dx - dy;
    int x_step = p1.x();

    for (int y_step = p1.y(); y_step <= p2.y(); ++y_step)
    {
        canvas(x_step, y_step) = color.getcolor(x_step, y_step);  // TODO add sign + range check

        if (approx > 0)
        {
            x_step = x_step + x_sign;
            approx = approx - 2 * dy;
        }

        approx = approx + 2 * dx;
    }
}


#endif // LINE_H