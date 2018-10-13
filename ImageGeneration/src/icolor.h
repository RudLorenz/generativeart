#ifndef GENERATIVEART_ICOLOR_H
#define GENERATIVEART_ICOLOR_H

#include "bmpheader.h"

class IColor
{
public:
    virtual BGRPalette getcolor(int x, int y) const = 0;
    virtual ~IColor() {};
};

#endif //GENERATIVEART_ICOLOR_H
