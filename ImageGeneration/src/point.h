#ifndef POINT_H
#define POINT_H

#include <vector>
#include <ostream>
#include <cmath>
#include <iostream>

#include "idrawable.h"

class Point : public IDrawable
{
public:
    Point();
    Point(int x, int y);
    Point(const Point& other) = default;
    Point(Point&& other) = default;

    Point& operator=(const Point& other) = default;
    Point& operator=(Point&& other) = default;

    friend std::ostream& operator<<(std::ostream& os, const Point& pt);

    void draw(BitmapImg& canvas, const BGRPalette& color) override;

    double distance(const Point& p) const;

    inline int x() const; // ugly
    inline int y() const;

private:
    int x_;
    int y_;
};


double distance(const Point &p1, const Point &p2)
{
    return p1.distance(p2);
}


Point::Point() : x_(0), y_(0)
{
}


Point::Point(int x, int y) : x_(x), y_(y)
{
}


std::ostream &operator<<(std::ostream &os, const Point &pt)
{
    os << "(" << pt.x_ << ", " << pt.y_ << ") ";
    return os;
}


void Point::draw(BitmapImg& canvas, const BGRPalette& color)
{
    canvas(x_, y_) = color;
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


#endif // POINT_H