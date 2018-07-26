#ifndef BMPGEN_H
#define BMPGEN_H

#include <cstdio>
#include <cstddef>
#include <cmath>
#include <string>
#include <vector>
#include <fstream>

#pragma pack(push, 1)
typedef struct tagBitmapHeader
{
    unsigned short fileType  = 0x4D42; //BM from standart
    unsigned       fileSize;
    unsigned short reserved1 = 0;
    unsigned short reserved2 = 0;
    unsigned       offset    = 54;   //was 1078

    //Info header
    unsigned       size = 40;        //info header size
    unsigned       width;
    int            height;           //according to specs height can be negative
    unsigned short colorPlanes = 1;  //always 1
    unsigned short bitPerPixel;
    unsigned       compressionType;
    unsigned       bitmapSize;       //0 if uncompressed
    unsigned       ppmX;             //horizontal resolution in pixels per meter
    unsigned       ppmY;             //vertical   resolution
    unsigned       colorsUsed;
    unsigned       colorsImportant;
} BitmapHeader;

typedef struct tagBGRPalette
{
    unsigned char b;
    unsigned char g;
    unsigned char r;

    tagBGRPalette() : b(0), g(0), r(0) {};

} BGRPalette;

#pragma pack(pop)


int bmp_generator(const std::string& filename, unsigned width, int height, std::vector<BGRPalette>& data)
{
    BitmapHeader bmp_header;

    auto abs_height = std::abs(height);

    auto padding = (4 - (width % 4)) % 4;

    bmp_header.fileSize = 54 + 3 * (width + padding) * abs_height;
    bmp_header.offset = 54;

    bmp_header.width           = width;
    bmp_header.height          = height;
    bmp_header.bitPerPixel     = 24; //true color
    bmp_header.compressionType = 0;
    bmp_header.bitmapSize      = 0;
    bmp_header.ppmX            = 0;
    bmp_header.ppmY            = 0;
    bmp_header.colorsUsed      = 0;
    bmp_header.colorsImportant = 0;

    std::ofstream out_f(filename, std::ios::out | std::ofstream::binary);

    if (!out_f.is_open()) {
        return -1;
    }

    out_f.write(reinterpret_cast<char *>(&bmp_header), sizeof(bmp_header));
    out_f.write(reinterpret_cast<char *>(data.data()), 3 * (width + padding) * abs_height);
    out_f.close();

    return 0;
}




#endif //BMPGEN_H