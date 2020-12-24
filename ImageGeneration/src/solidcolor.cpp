#include "solidcolor.h"


BGRPalette SolidColor::getcolor(int, int) const {
    return color_;
}

SolidColor::SolidColor(BGRPalette color)
    : color_(color)
{
}
SolidColor::SolidColor(int b, int g, int r)
    : color_(BGRPalette{static_cast<unsigned char>(b), static_cast<unsigned char>(g), static_cast<unsigned char>(r)})
{
}
