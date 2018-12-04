#include "Utility.h"

#ifndef TRAITEMENT_H
#define  TRAITEMENT_H

typedef struct{
    size_t x;
    size_t y;
} Point;

typedef struct {
    void* next;
    Point a;
    Point b;
    Point c;
    Point d;
} Zone;



BMPPic_ DetectOutlines(BMPPic_ pic);

BMPPic_ ApplyRLSA(BMPPic_ pic,int seuil_a,int seuil_b);

void PrintZone(Zone zone);

BMPPic_ DetectZones(BMPPic_ pic);

#endif
