#include "bitmapimg.h"

#include <fstream>

BitmapImg::BitmapImg(size_t width, size_t height)
    : width_(width)
    , height_(height)
    , pixels_( 3 * ( ( (4 - ( width % 4 ) ) % 4 ) + width) * height, 0 )
// Don't forget the padding declared in bmp file format:
// "Each row in the Pixel array is padded to a multiple of 4 bytes in size "
{
}


BitmapImg::BitmapImg(size_t width, size_t height, BGRPalette bg_color)
    : width_(width)
    , height_(height)
    , pixels_( 3 * ( ( (4 - ( width % 4 ) ) % 4 ) + width) * height, bg_color )
{
}


void BitmapImg::writeToFile(const std::string &filename)
{
    BitmapHeader bmp_header;

    const auto padding = (4 - (width_ % 4)) % 4;

    bmp_header.fileSize = static_cast<unsigned int>(54 + pixels_.size());
    bmp_header.offset = 54;

    bmp_header.width           = width_;
    bmp_header.height          = height_;
    bmp_header.bitPerPixel     = 24;
    bmp_header.bitmapSize      = 0;
    bmp_header.ppmX            = 0;
    bmp_header.ppmY            = 0;
    bmp_header.colorsUsed      = 0;
    bmp_header.colorsImportant = 0;

    std::ofstream out_f(filename, std::ios::out | std::ofstream::binary);

    if (!out_f) {
        std::string err_message = "Unable to open file " + filename;
        throw std::runtime_error(err_message);
    }

    out_f.write(reinterpret_cast<char *>(&bmp_header), sizeof(bmp_header));
    out_f.write(reinterpret_cast<char *>(pixels_.data()), 3 * (width_ + padding) * height_);
    out_f.close();
}


size_t BitmapImg::getWidth() const
{
    return width_;
}


size_t BitmapImg::getHeight() const
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
    if (row >= height_ || col >= width_) { throw std::out_of_range("Index out of bounds"); }

    // turn the image upside down so (0,0) is in left top counter
    return pixels_[(height_ - col - 1) * width_ + row];
}

const BGRPalette &BitmapImg::operator()(size_t row, size_t col) const
{
    // don't allow user to access "padded" pixels
    if (row >= height_ || col >= width_) { throw std::out_of_range("Index out of bounds"); }

    // turn the image upside down so (0,0) is in left top counter
    return pixels_[(height_ - col - 1) * width_ + row];
}
