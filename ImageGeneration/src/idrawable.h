#ifndef IDRAWABLE_H
#define IDRAWABLE_H

#include "bitmapimg.h"
#include "icolor.h"

class IDrawable
{
public:
    virtual void draw(BitmapImg &canvas, const IColor& color) = 0;
    virtual ~IDrawable() {};
};

#endif // IDRAWABLE_H