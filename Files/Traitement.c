#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "Traitement.h"

BMPPic_ DetectOutlines(BMPPic_ pic){
    long **DATA = calloc(pic.height*pic.width, sizeof(long));
    long max = 0;
    long min = 999999;
    for (size_t i = 0; i < pic.height; ++i) {
        DATA[i] = calloc(pic.width, sizeof(long));
        for (size_t j = 0; j < pic.width; ++j) {
            DATA[i][j] = (long) sqrt(pow(getGray(pic, i, j - 1) - getGray(pic, i, j + 1), 2) + pow(getGray(pic, i - 1, j) - getGray(pic, i + 1, j), 2));
            if(DATA[i][j] > max)
                max = DATA[i][j];
            if(DATA[i][j] < min)
                min = DATA[i][j];
        }
    }
    float seuil = (float) (min + (0.2 * (max - min)));
    for (size_t k = 0; k < pic.height; ++k) {
        for (size_t i = 0; i < pic.width; ++i) {
            if(DATA[k][i] > seuil)
                setGray(pic,k,i,0);
            else
                setGray(pic,k,i,255);
        }
        free(DATA[k]);
    }
    free(DATA);
    return pic;
}

BMPPic_ ApplyRLSA(BMPPic_ pic,int seuil_x,int seuil_y){
    unsigned char data_x[pic.height][pic.width];
    memset(data_x,255,pic.height * pic.width);
    for (size_t i = 0; i < pic.height; i++) {
        size_t distance = 0;
        int isFirst = 0;
        for (size_t j = 0; j < pic.width; j++) {
            if(isFirst == 1){
                distance += 1;
            }
            if (pic.GREYMATRIX[i][j] == 0) {
                data_x[i][j] = 0;
                if (isFirst == 1 && distance <= seuil_x) {
                    for (size_t k = 0; k < distance; k++) {
                        data_x[i][j-k] = 0;
                    }
                }
                isFirst = 1;
                distance = 0;
            }

        }
    }



    unsigned char data_y[pic.height][pic.width];
    memset(data_y,255,pic.height * pic.width);

    for (size_t i = 0; i < pic.width; i++) {
        size_t distance = 0;
        int isFirst = 0;
        for (size_t j = 0; j < pic.height; j++) {
            if(isFirst == 1){
                distance += 1;
            }
            if (pic.GREYMATRIX[j][i] == 0) {
                data_y[j][i] = 0;
                if (isFirst == 1 && distance <= seuil_y) {
                    for (size_t k = 0; k < distance; k++) {
                        data_y[j-k][i] = 0;
                    }
                }
                isFirst = 1;
                distance = 0;
            }
        }
    }

    for (size_t i = 0; i < pic.height; i++) {
        for (size_t j = 0; j < pic.width; j++) {
            if (data_x[i][j] == 0 /* && data_y[i][j] == 0 */) {
                pic.GREYMATRIX[i][j] = 0;
            }
            else{
                pic.GREYMATRIX[i][j] = 255;
            }
        }
    }

    return pic;
}


BMPPic_ DetectZones(BMPPic_ pic){
    pic.TEXTZONE = malloc(1);
    unsigned char alrdTreat[pic.height][pic.width];
    memset(alrdTreat,0,pic.height * pic.width);
    for (size_t i = 0; i < pic.height; i++) {
        for (size_t j = 0; j < pic.width; j++) {
            if (alrdTreat[i][j] == 0 && pic.GREYMATRIX[i][j] == 0) {
                Zone cur;
                cur.x = i;
                cur.y = j;
                size_t tp_i = i;
                size_t tp_j = j;
                while (tp_i < pic.height && pic.GREYMATRIX[tp_i][j] == 0) {
                    tp_i += 1;
                }
                cur.height = tp_i - i;
                while (tp_j < pic.width && pic.GREYMATRIX[i][tp_j] == 0) {
                    tp_j += 1;
                }
                cur.width = tp_j - j;
                pic.nbZones += 1;
                pic.TEXTZONE = realloc(pic.TEXTZONE,pic.nbZones * sizeof(Zone));
                pic.TEXTZONE[pic.nbZones-1] = cur;
                for (size_t k = i; k < tp_i; k++) {
                     for (size_t l = j; l < tp_j; l++) {
                         alrdTreat[k][l] = 1;
                     }
                }
            }
        }
    }

    for (size_t m = 0; m < pic.nbZones; ++m) {
        for (size_t i = pic.TEXTZONE[m].x; i < pic.TEXTZONE[m].x + pic.TEXTZONE[m].height; ++i) {
            for (size_t j = pic.TEXTZONE[m].y; j < pic.TEXTZONE[m].y + pic.TEXTZONE[m].width; ++j) {
                pic.GREYMATRIX[i][j] = 0;
            }
        }
    }


    return pic;
}


BMPPic_ DivideZone(BMPPic_ pic){
    for (size_t m = 0; m < pic.nbZones; ++m) {
        for (size_t j = pic.TEXTZONE[m].y; j < pic.TEXTZONE[m].y + pic.TEXTZONE[m].width; ++j) {
            int bool = 0;
            for (size_t i = pic.TEXTZONE[m].x; i < pic.TEXTZONE[m].x + pic.TEXTZONE[m].height; ++i) {
                if(pic.GREYMATRIX[i][j] == 0)
                    bool = 1;
            }
            if(bool == 0){
                for (size_t i = pic.TEXTZONE[m].x; i < pic.TEXTZONE[m].x + pic.TEXTZONE[m].height; ++i) {
                    pic.GREYMATRIX[i][j] = 80;
                }
            }
        }

    }

    return pic;
}

BMPPic_ DetectChars(BMPPic_ pic){
    unsigned char alrdTrt[pic.height][pic.width];
    memset(alrdTrt,0,pic.height * pic.width);
    for (size_t i = 0; i < pic.height; ++i) {
        for (size_t j = 0; j < pic.width; ++j) {
            if(alrdTrt[i][j] == 0 && pic.GREYMATRIX[i][j] != 80){
                size_t tp_i = i;
                size_t tp_j = j;
                while(pic.GREYMATRIX[tp_i][j] != 80) {
                    ++tp_i;
                }
                while(pic.GREYMATRIX[i][tp_j] != 80) {
                    ++tp_j;
                }
                Char cur;
                cur.x = i;
                cur.y = j;
                cur.height = tp_i - i;
                cur.width = tp_j - j;
                pic.nbChars += 1;
                pic.CHARS = realloc(pic.CHARS,pic.nbChars * sizeof(Char));
                pic.CHARS[pic.nbChars - 1] = cur;
                for (size_t k = 0; k < tp_i - i; ++k) {
                    for (size_t l = 0; l < tp_j - j; ++l) {
                        alrdTrt[i + k][j + l] = 1;
                    }
                }
                pic.GREYMATRIX[cur.x][cur.y] = 70;
            }
            if(pic.GREYMATRIX[i][j] == 80)
                pic.GREYMATRIX[i][j] = 255;
        }
    }
    return pic;
}

/*
BMPPic_ DetectWords(BMPPic_ pic){
    pic.SPACE = malloc(1024);
    return pic;
}*/
