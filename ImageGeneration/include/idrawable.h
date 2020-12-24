#pragma once
#include "bitmapimg.h"
#include "icolor.h"

class IDrawable
{
public:
    virtual void draw(BitmapImg &canvas, const IColor& color) const = 0;
    virtual ~IDrawable() = default;
};
