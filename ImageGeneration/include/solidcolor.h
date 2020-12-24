#pragma once

#include "bmpheader.h"
#include "icolor.h"

class SolidColor : public IColor
{
public:
    SolidColor(BGRPalette color);
    SolidColor(int b, int g, int r);
    BGRPalette getcolor(int, int) const override;

private:
    BGRPalette color_;
};
