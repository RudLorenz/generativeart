#include <utility>

#ifndef POLYGON_H
#define POLYGON_H

#include "drawable.h"
#include "point.h"
#include "line.h"

class Polygon : public Drawable
{
public:

    Polygon() = delete;
    Polygon(std::vector<Point> points);
    Polygon(std::initializer_list<Point> lst);
    Polygon(std::initializer_list<int>   lst);

    void append(std::initializer_list<Point> lst);

    size_t size() const;

    void draw(BitmapImg &canvas, const BGRPalette &color) override;

protected:
    void plotLineLow (const Point& p1, const Point& p2, BitmapImg &canvas, const BGRPalette &color);
    void plotLineHigh(const Point& p1, const Point& p2, BitmapImg &canvas, const BGRPalette &color);
    void plotLine    (const Point& p1, const Point& p2, BitmapImg &canvas, const BGRPalette &color);

private:
    std::vector<Point> points_;
};


Polygon::Polygon(std::vector<Point> points)
    : points_(std::move(points))
{
}


Polygon::Polygon(std::initializer_list<Point> lst)
    : points_(lst)
{
}


Polygon::Polygon(std::initializer_list<int> lst)
{
    auto tail = lst.end();

    if(lst.size() % 2 != 0) {
        tail--;
    }

    for (auto it = lst.begin(); it != tail; it+=2) {
        points_.emplace_back(*it, *(it+1));
    }
}


void Polygon::append(std::initializer_list<Point> lst)
{
    points_.insert(points_.end(), lst.begin(), lst.end());
}


size_t Polygon::size() const
{
    return points_.size();
}


void Polygon::draw(BitmapImg &canvas, const BGRPalette &color)
{
    for (auto it = points_.begin(); it != points_.end()-1; ++it)
    {
        plotLine(*it, *(it+1), canvas, color);
    }
    plotLine(points_.front(), points_.back(), canvas, color);
}


void Polygon::plotLineLow(const Point& p1, const Point& p2, BitmapImg &canvas, const BGRPalette &color)
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
        canvas(x_step, y_step) = color;  // TODO add sign + range check

        if (approx > 0)
        {
            y_step = y_step + y_sign;
            approx = approx - 2 * dx;
        }

        approx = approx + 2 * dy;
    }
}


void Polygon::plotLineHigh(const Point& p1, const Point& p2, BitmapImg &canvas, const BGRPalette &color)
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
        canvas(x_step, y_step) = color;  // TODO add sign + range check

        if (approx > 0)
        {
            x_step = x_step + x_sign;
            approx = approx - 2 * dy;
        }

        approx = approx + 2 * dx;
    }
}


void Polygon::plotLine(const Point &p1, const Point &p2, BitmapImg &canvas, const BGRPalette &color)
{
    if (std::abs(p2.y() - p1.y()) < std::abs(p2.x() - p1.x()))
    {
        if (p1.x() > p2.x()) {
            plotLineLow(p2, p1, canvas, color);
        }
        else {
            plotLineLow(p1, p2, canvas, color);
        }
    }
    else
    {
        if (p1.y() > p2.y()) {
            plotLineHigh(p2, p1, canvas, color);
        }
        else {
            plotLineHigh(p1, p2, canvas, color);
        }
    }
}

#endif // POLYGON_H