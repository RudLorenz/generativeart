#pragma once
#include "bmpheader.h"

#include <vector>
#include <string>

class BitmapImg
{
public:
    BitmapImg();
    BitmapImg(size_t width, size_t height);

    void writeToFile(const std::string& filename);

    size_t getWidth() const;
    size_t getHeight() const;

    BGRPalette& operator()(size_t row, size_t col);
    const BGRPalette& operator()(size_t row, size_t col) const;

private:
    size_t width_;
    size_t height_;
    std::vector<BGRPalette> pixels_;
};
