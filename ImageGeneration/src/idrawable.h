#ifndef IDRAWABLE_H
#define IDRAWABLE_H

#include "bitmapimg.h"

class IDrawable
{
public:
    virtual void draw(BitmapImg& canvas, const BGRPalette& color) = 0;
    virtual ~IDrawable() {};
};

#endif // IDRAWABLE_H