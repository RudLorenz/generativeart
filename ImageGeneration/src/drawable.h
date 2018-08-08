#ifndef DRAWABLE_H
#define DRAWABLE_H

#include "bitmapimg.h"

class Drawable
{
public:
    virtual void draw(BitmapImg& canvas, const BGRPalette& color) = 0;
};

#endif // DRAWABLE_H