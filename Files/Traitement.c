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

BMPPic_ ApplyRLSA(BMPPic_ pic,int seuil_a,int seuil_b){
    double seuil = seuil_a;
    char data_x[pic.height][pic.width];
    char data_y[pic.height][pic.width];
    for (size_t i = 0; i < pic.height; ++i) {
        memset(data_x[i],255, sizeof(data_x[i]));
        memset(data_y[i],255, sizeof(data_y[i]));
        int compt = 0;
        for (size_t j = 0; j < pic.width ; ++j) {
            if(getGray(pic,i,j) == 255)
                compt += 1;
            if(getGray(pic,i,j) == 0){
                data_x[i][j] = 0;
                if(compt <= seuil){
                    for (int k = compt; k > 0; --k) {
                        //RLSAPICx = setGray(RLSAPICx,i,j-k,255);
                        data_x[i][j-k] = 0;
                    }
                }
                compt = 0;
            }
        }
    }
    seuil = seuil_b;
    for (size_t j = 0; j < pic.width ; ++j) {
        int compt = 0;
        for (size_t i = 0; i < pic.height; ++i) {
            if(getGray(pic,i,j) == 255) {
                compt += 1;
            }
            if(getGray(pic,i,j) == 0){
                data_y[i][j]=0;
                if(compt <= seuil){
                    for (int k = compt; k > 0; --k) {
                        data_y[i-k][j] = 0;
                    }
                }
                compt = 0;
            }
        }
    }
    for (size_t l = 0; l < pic.height; ++l) {
        for (size_t i = 0; i < pic.width; ++i) {
            int a = data_x[l][i];
            int b = data_y[l][i];
            int res = 255;
            if(a == 0 && b == 0)
                res = 0;

            pic = setGray(pic, (size_t) l, (size_t) i, (unsigned char) res);
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

    printf("nb de zones : %d \n",pic.nbZones);

    for (size_t m = 0; m < pic.nbZones; ++m) {
        for (size_t i = pic.TEXTZONE[m].x; i < pic.TEXTZONE[m].x + pic.TEXTZONE[m].height; ++i) {
            for (size_t j = pic.TEXTZONE[m].y; j < pic.TEXTZONE[m].y + pic.TEXTZONE[m].width; ++j) {
                pic.GREYMATRIX[i][j] = 80;
            }
        }
    }
    
    return pic;
}
