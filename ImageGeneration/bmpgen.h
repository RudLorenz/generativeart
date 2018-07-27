#ifndef BMPGEN_H
#define BMPGEN_H

#include "bmpheader.h"

#include <vector>
#include <string>
#include <cmath>
#include <fstream>

class BitmapImg
{
public:
    BitmapImg();
    BitmapImg(unsigned width, int height);

    int writeToFile(const std::string& filename);

    unsigned getWidth() const;
    int      getHeight() const;

    BGRPalette& operator()(size_t row, size_t column);
    BGRPalette  operator()(size_t row, size_t column) const;

private:
    unsigned width_;
    int      height_;
    std::vector<BGRPalette> pixels_;
};


#endif //BMPGEN_H