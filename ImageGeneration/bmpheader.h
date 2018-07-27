#ifndef BMPHEADER_H
#define BMPHEADER_H

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
    unsigned       compressionType = 0;
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

    tagBGRPalette()  : b(0), g(0), r(0) {};
    tagBGRPalette(unsigned char value) : b(value), g(value), r(value) {};

} BGRPalette;

#pragma pack(pop)

#endif //BMPHEADER_H