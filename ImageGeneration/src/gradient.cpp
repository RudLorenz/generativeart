#include "gradient.h"

Gradient::Gradient(
    const Point& p1,
    const Point& p2,
    const BGRPalette& start_c,
    const BGRPalette& end_c
    )

    : x_cf_(p2.x() - p1.x())
    , y_cf_(p2.y() - p1.y())
    , c1_(x_cf_ * p1.x() + y_cf_ * p1.y())
    , c2_(x_cf_ * p2.x() + y_cf_ * p2.y())
    , start_(start_c)
    , end_(end_c)
{
}


BGRPalette Gradient::getcolor(int x, int y) const
{
    double result_c = x_cf_ * x + y_cf_ * y;

    if (result_c <= c1_) {
        return start_;
    }
    if (result_c >= c2_) {
        return end_;
    }

    return BGRPalette (
            static_cast<unsigned char>((start_.b * (c2_ - result_c) + end_.b * (result_c - c1_)) / (c2_ - c1_)),
            static_cast<unsigned char>((start_.g * (c2_ - result_c) + end_.g * (result_c - c1_)) / (c2_ - c1_)),
            static_cast<unsigned char>((start_.r * (c2_ - result_c) + end_.r * (result_c - c1_)) / (c2_ - c1_))
    );
}


BGRPalette Gradient::getcolor(const Point &p) const
{
    return getcolor(p.x(), p.y());
}
