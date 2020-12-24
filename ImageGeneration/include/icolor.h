#pragma once
#include "bmpheader.h"

class IColor
{
public:
    virtual BGRPalette getcolor(int x, int y) const = 0;
    virtual ~IColor() = default;
};
