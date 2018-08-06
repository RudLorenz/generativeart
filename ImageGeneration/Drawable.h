#ifndef POLYGON_H
#define POLYGON_H

#include "bitmapimg.h"

#include <vector>

class Drawable
{
public:
    virtual void draw(BitmapImg& canvas, const BGRPalette& color) = 0;
};

#endif //POLYGON_H