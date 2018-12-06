//
// Created by lucas on 06/12/18.
//
#include <stdint.h>

#include "adjustement.h"
#include "Utility.h"

float lerp(float s, float e, float t){
    return s+(e-s)*t;
}


float blerp(float c00, float c10, float c01, float c11, float tx, float ty){
    return lerp(lerp(c00, c10, tx), lerp(c01, c11, tx), ty);
}

**char resize (**char Mymatrix,int height,int width)
{
    size_t newWidth = 28;
    size_t newHeight= 28;

    **char result = calloc(height*width, sizeof(char));
    size_t x=0;
    size_t y =0;

    while(y < newHeight)
{
        if(x > newWidth){
            x = 0; y++;
        }

        float g_x = x/ (float)(newWidth) * (width-1);
        float g_y = y/ (float)(newHeight) * (height-1);

        int gxi = (int) g_x;
        int gyi = (int) g_y;

        u_int32_t result = 0;
        uint32_t c00 = getpixel(src, gxi, gyi);
        uint32_t c10 = getpixel(src, gxi+1, gyi);
        uint32_t c01 = getpixel(src, gxi, gyi+1);
        uint32_t c11 = getpixel(src, gxi+1, gyi+1);
        uint8_t i;

        for(i = 0; i < 3; i++){
        //((uint8_t*)&result)[i] = blerp( ((uint8_t*)&c00)[i], ((uint8_t*)&c10)[i], ((uint8_t*)&c01)[i], ((uint8_t*)&c11)[i], gxi - gx, gyi - gy); // this is shady
        result |= (uint8_t)blerp(getByte(c00, i), getByte(c10, i), getByte(c01, i), getByte(c11, i), gx - gxi, gy -gyi) << (8*i);
        }

        putpixel(dst,x, y, result);

    }

}