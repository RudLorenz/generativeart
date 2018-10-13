#ifndef GENERATIVEART_GRADIENT3_H
#define GENERATIVEART_GRADIENT3_H

#include "bmpheader.h"
#include "icolor.h"
#include "point.h"

class Gradient3 : public IColor
{
public:
    Gradient3() = delete;

    Gradient3(const Point &p1, const Point &p2, const Point &p3,
              const BGRPalette &color1, const BGRPalette &color2, const BGRPalette &color3);

    BGRPalette getcolor(int x, int y)   const override;
    BGRPalette getcolor(const Point &p) const;

private:
    double sign(const Point &p1, const Point &p2, const Point &p3) const;
    bool inside(const Point &p) const;

    Point p1_;
    Point p2_;
    Point p3_;
    BGRPalette color1_;
    BGRPalette color2_;
    BGRPalette color3_;
};


Gradient3::Gradient3(const Point &p1, const Point &p2, const Point &p3, const BGRPalette &color1,
                     const BGRPalette &color2, const BGRPalette &color3)
        : p1_(p1), p2_(p2), p3_(p3), color1_(color1), color2_(color2), color3_(color3)
{
}


BGRPalette Gradient3::getcolor(const Point &p) const
{
    if (!inside(p)) {
        return {0, 0, 0};
    }

    BGRPalette result;

    double tri_area_1 = ((p.x() - p3_.x()) * (p2_.y() - p3_.y()) -
                         (p2_.x() - p3_.x()) * (p.y() - p3_.y()));
    double tri_area_2 = ((p.x() - p3_.x()) * (p1_.y() - p3_.y()) -
                         (p1_.x() - p3_.x()) * (p.y() - p3_.y()));
    double tri_area_3 = ((p.x() - p2_.x()) * (p1_.y() - p2_.y()) -
                         (p1_.x() - p2_.x()) * (p.y() - p2_.y()));

    tri_area_1 = std::abs(tri_area_1 / 2.);
    tri_area_2 = std::abs(tri_area_2 / 2.);
    tri_area_3 = std::abs(tri_area_3 / 2.);

    result.b = static_cast<unsigned char>((color1_.b * tri_area_1 + color2_.b * tri_area_2 + color3_.b * tri_area_3) /
                                          (tri_area_1 + tri_area_2 + tri_area_3));
    result.g = static_cast<unsigned char>((color1_.g * tri_area_1 + color2_.g * tri_area_2 + color3_.g * tri_area_3) /
                                          (tri_area_1 + tri_area_2 + tri_area_3));
    result.r = static_cast<unsigned char>((color1_.r * tri_area_1 + color2_.r * tri_area_2 + color3_.r * tri_area_3) /
                                          (tri_area_1 + tri_area_2 + tri_area_3));

    return result;
}


BGRPalette Gradient3::getcolor(int x, int y) const {
    return getcolor(Point(x, y));
}


double Gradient3::sign(const Point &p1, const Point &p2, const Point &p3) const
{
    return (p1.x() - p3.x()) * (p2.y() - p3.y()) - (p2.x() - p3.x()) * (p1.y() - p3.y());
}


bool Gradient3::inside(const Point &p) const
{
    bool b1, b2, b3;
    b1 = sign(p, p1_, p2_) < 0.0f;
    b2 = sign(p, p2_, p3_) < 0.0f;
    b3 = sign(p, p3_, p1_) < 0.0f;

    return ((b1 == b2) && (b2 == b3));
}

#endif //GENERATIVEART_GRADIENT3_H
