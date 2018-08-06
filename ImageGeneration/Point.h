#ifndef POINT_H
#define POINT_H

#include "Drawable.h"

#include <vector>
#include <ostream>

class Point : public Drawable
{
public:
    Point();
    Point(unsigned x, unsigned y);
    Point(const Point& other) = default;
    Point(Point&& other) = default;
    Point(std::initializer_list<unsigned> lst);

    Point& operator=(const Point& other) = default;
    Point& operator=(Point&& other) = default;

    friend std::ostream& operator<<(std::ostream& os, const Point& pt);

    void draw(BitmapImg& canvas, const BGRPalette& color) override;

    unsigned x() const; // ugly
    unsigned y() const;

private:
    unsigned x_;
    unsigned y_;
};


Point::Point() : x_(0), y_(0)
{
}


Point::Point(unsigned x, unsigned y) : x_(x), y_(y)
{
}

Point::Point(std::initializer_list<unsigned> lst)
{
    if (lst.size() == 2)
    {
        x_ = *lst.begin();
        y_ = *(lst.begin()+1);
    }
    else // throw exception?
    {
        x_ = 0;
        y_ = 0;
    }
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

unsigned Point::x() const
{
    return x_;
}

unsigned Point::y() const
{
    return y_;
}


#endif //POINT_H