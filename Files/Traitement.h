#include "Utility.h"

#ifndef TRAITEMENT_H
#define  TRAITEMENT_H

struct Zone{
    unsigned char ** data;
    size_t height;
    size_t width;
    void* next;
};

BMPPic_ DetectOutlines(BMPPic_ pic);

BMPPic_ ApplyRLSA(BMPPic_ pic,int seuil_a,int seuil_b);

BMPPic_ DetectZones(BMPPic_ pic);

#endif
