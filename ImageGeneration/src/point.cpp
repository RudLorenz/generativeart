#include "point.h"

#include <cmath>


Point::Point(int x, int y) : x_(x), y_(y)
{
}


std::ostream &operator<<(std::ostream &os, const Point &pt)
{
    os << "(" << pt.x_ << ", " << pt.y_ << ") ";
    return os;
}


void Point::draw(BitmapImg &canvas, const IColor &color) const
{
    canvas(x_, y_) = color.getcolor(x_, y_);
}


int Point::x() const
{
    return x_;
}


int Point::y() const
{
    return y_;
}


double Point::distance(const Point &p) const
{
    return std::sqrt( (x_ - p.x_) * (x_ - p.x_) +  (y_ - p.y_) * (y_ - p.y_) );
}


double distance(const Point &p1, const Point &p2)
{
    return p1.distance(p2);
}
