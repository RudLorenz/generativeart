#pragma once

#include "idrawable.h"
#include "point.h"

class CCS : public IDrawable
{
public:
    CCS(Point center, size_t scale);

    void draw(BitmapImg& canvas, const IColor& color) const override;

    Point center() const;
    size_t scale() const;

private:
    Point center_;
    size_t scale_;
};
