#include "Utility.h"
#include "Traitement.h"

#ifndef BINARY_H
#define BINARY_H

typedef struct {

    size_t size;
    size_t nbr_greyscales;
    unsigned char * greyscales;

    double weight;
    double mean_pixel;


    int x;
    int y;


} window;


typedef struct {


    window scope;

    double mean;
    double variance;

    int *nbr;
    unsigned char **GREYMATRIX;
    size_t height;
    size_t width;

    int Bimodal;
} histogram;

BMPPic_ end (BMPPic_ pic);




#endif //PROJECT2_BINARY_H
