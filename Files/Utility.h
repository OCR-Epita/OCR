#ifndef UTILITY_H
#define  UTILITY_H

#include <stdlib.h>

#include <stdio.h>


typedef struct {
    short bftype;
    int bfSize;
    short bfReserved1;
    short bfReserved2;
    int bfOffBits;
    int biSize;
    int biWidth;
    int biHeight;
    short biPlanes;
    short biBitCount;
    int biCompression;
    int biSizeImage;
    int biXpelsPerMeter;
    int biYpelsPerMeter;
    int biClrUsed;
    int biClrImportant;
} BITMAPHEADER;

typedef struct {
    unsigned char R;
    unsigned char V;
    unsigned char B;
    unsigned char Gris;
    int yes;
} Pixel_;

typedef struct {
    size_t x;
    size_t y;
    size_t height;
    size_t width;
} Zone;

typedef struct {
    unsigned char **matrix;
    size_t height;
    size_t width;
}character;

typedef struct {
    BITMAPHEADER header;
    size_t height;
    size_t width;
    unsigned char *HEADERDATA;
    unsigned char *PIXELDATA;
    unsigned char **GREYMATRIX;
    size_t nbZones;
    Zone *TEXTZONE;
    character *character_list;
    int* colons_scope;
    int last;
} BMPPic_;


BMPPic_ getHeader(char data[],BMPPic_ pic);

BMPPic_ InitGreyMatr(BMPPic_ pic);

Pixel_ getPixel(BMPPic_ pic,size_t i,size_t j);

void restructPic(BMPPic_ pic, char name[]);

BMPPic_ setPixel(BMPPic_ pic,size_t i,size_t j,Pixel_ pixel);

//Same thing for GetPixel but for greyscale image
unsigned char getGray(BMPPic_ myPic,size_t x, size_t y);

//Same thing for SetPixel but for greyscale image
BMPPic_ setGray(BMPPic_ myPic,size_t x, size_t y,unsigned char val);

BMPPic_ InitPic();

#endif
