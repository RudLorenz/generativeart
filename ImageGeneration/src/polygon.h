#ifndef POLYGON_H
#define POLYGON_H

#include "drawable.h"
#include "point.h"
#include "line.h"

class Polygon : public Drawable
{
public:

    Polygon() = delete;
    Polygon(const std::vector<Point>& points);
    Polygon(std::initializer_list<Point> lst);
    Polygon(std::initializer_list<unsigned>   lst);

    void append(std::initializer_list<Point> lst);

    size_t size() const;

    void draw(BitmapImg &canvas, const BGRPalette &color) override;

private:
    std::vector<Point> points_;
};


Polygon::Polygon(const std::vector<Point>& points)
    : points_(points)
{
}


Polygon::Polygon(std::initializer_list<Point> lst)
    : points_(lst)
{
}


Polygon::Polygon(std::initializer_list<unsigned> lst)
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
    for (unsigned i = 0; i < points_.size()-1; ++i)
    {
        // bad design. Should probably add a method to Point class to draw line to another point
        // or create a separate function that will do the job.
        Line ln(points_[i], points_[i+1]);
        ln.draw(canvas, color);
    }
    Line ln(points_.front(), points_.back());
    ln.draw(canvas, color);
}

#endif // POLYGON_H