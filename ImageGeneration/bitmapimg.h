#ifndef BITMAPIMG_H
#define BITMAPIMG_H

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

    BGRPalette& operator()(size_t row, size_t col);
    const BGRPalette& operator()(size_t row, size_t col) const;

private:
    unsigned width_;
    int      height_;
    std::vector<BGRPalette> pixels_;
};


BitmapImg::BitmapImg() : width_(0), height_(0), pixels_(0)
{
}


BitmapImg::BitmapImg(unsigned width, int height) : width_(width), height_(height),
                                                   pixels_(3 * (((4 - (width % 4)) % 4) + width) * std::abs(height), 0)
// a bit too complicated maybe? calculations needed to add padding
// declared in bmp file format:
// "Each row in the Pixel array is padded to a multiple of 4 bytes in size "
{
}


int BitmapImg::writeToFile(const std::string &filename)
{
    BitmapHeader bmp_header;

    auto abs_height = std::abs(height_);

    auto padding = (4 - (width_ % 4)) % 4;

    bmp_header.fileSize = 54 + pixels_.size();
    bmp_header.offset = 54;

    bmp_header.width           = width_;
    bmp_header.height          = height_;
    bmp_header.bitPerPixel     = 24;               //true color
    bmp_header.bitmapSize      = 0;
    bmp_header.ppmX            = 0;
    bmp_header.ppmY            = 0;
    bmp_header.colorsUsed      = 0;
    bmp_header.colorsImportant = 0;

    std::ofstream out_f(filename, std::ios::out | std::ofstream::binary);

    if (!out_f) {
        std::string err_message = "file ";
        err_message += filename;
        err_message += " not found\n";
        throw std::runtime_error(err_message);
    }

    out_f.write(reinterpret_cast<char *>(&bmp_header), sizeof(bmp_header));
    out_f.write(reinterpret_cast<char *>(pixels_.data()), 3 * (width_ + padding) * abs_height);
    out_f.close();

    return 0;
}


unsigned BitmapImg::getWidth() const
{
    return width_;
}


int BitmapImg::getHeight() const
{
    return height_;
}

/*    rows
 *  c  ---→
 *  o|
 *  l|
 *  s↓
 */

BGRPalette &BitmapImg::operator()(size_t row, size_t col)
{
    // don't allow user to access "padded" pixels
    if (row >= std::abs(height_) || col >= width_) { throw std::out_of_range("Index out of bounds"); }

    // turn the image upside down so (0,0) is in left top counter
    return pixels_[(height_ - col - 1) * width_ + row];
}

const BGRPalette &BitmapImg::operator()(size_t row, size_t col) const
{
    // don't allow user to access "padded" pixels
    if (row >= std::abs(height_) || col >= width_) { throw std::out_of_range("Index out of bounds"); }

    // turn the image upside down so (0,0) is in left top counter
    return pixels_[(height_ - col - 1) * width_ + row];
}


#endif //BITMAPIMG_H