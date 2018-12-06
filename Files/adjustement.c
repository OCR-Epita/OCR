//
// Created by lucas on 06/12/18.
//

#include "adjustement.h"



float getByte(int value,int n)
{
    return value >> (n*8) & 0xFF;
}


float lerp(float s, float e, float t){
    return s+(e-s)*t;
}


float blerp(float c00, float c10, float c01, float c11, float tx, float ty){
    return lerp(lerp(c00, c10, tx), lerp(c01, c11, tx), ty);
}

BMPPic_ get_matrix (BMPPic_ Mypic)
{
    size_t k = 0;
    Mypic.character_list = calloc(Mypic.nbZones, sizeof(unsigned char)* sizeof(unsigned char));

    while (k < Mypic.nbZones)
    {

        size_t x = Mypic.TEXTZONE[k].x;
        size_t y = Mypic.TEXTZONE[k].y;

        size_t height = Mypic.TEXTZONE[k].height;
        size_t width = Mypic.TEXTZONE[k].width;

        Mypic.character_list[k].height = height;
        Mypic.character_list[k].width = width;

        Mypic.character_list[k].matrix = calloc(height, sizeof(unsigned char));

        size_t i = x;
        size_t j = y;
        while(i < x+height)
        {
            Mypic.character_list[k].matrix[i] = calloc(width, sizeof(unsigned char));
            j =0;
            while (j < y+width)
            {
                Mypic.character_list[k].matrix[i][j] = Mypic.GREYMATRIX[i][j];
                j+=1;
            }
            i+=1;
        }
        k+=1;
    }
    return Mypic;
}

BMPPic_ resize (BMPPic_ MyPic)
{
    size_t k = 0;
    while (k < MyPic.nbZones) {
        unsigned char **src = MyPic.character_list[k].matrix;

        size_t height = MyPic.character_list[k].height;
        size_t width = MyPic.character_list[k].width;

        size_t newWidth = 28;
        size_t newHeight = 28;

        unsigned char **res = calloc(28, sizeof(unsigned char));
        memset(res,0,28* sizeof(unsigned char));
        size_t x = 0;
        size_t y = 0;

        while (x < newHeight) {
            y = 0;
            res[x] = calloc(28, sizeof(unsigned char));
            memset(res[x],0,28* sizeof(unsigned char));
            while (y < newWidth) {
                float gx = x / (float) (newWidth) * (width - 1);
                float gy = y / (float) (newHeight) * (height - 1);

                int gxi = (int) gx;
                int gyi = (int) gy;

                uint32_t c00;
                uint32_t c10;
                uint32_t c01;
                uint32_t c11;

                if (src[gxi][gyi] == 255)
                {
                    c00 = UINT32_MAX;
                }
                if (src[gxi + 1][gyi] == 255)
                {
                    c10 = UINT32_MAX;
                }
                if (src[gxi][gyi + 1])
                {
                    c01 = UINT32_MAX;
                }
                if (src[gxi + 1][gyi + 1] == 255)
                {
                    c11 = UINT32_MAX;
                }
                u_int32_t result = 0;
                uint8_t i;

                for (i = 0; i < 3; i++) {
                    //((uint8_t*)&result)[i] = blerp( ((uint8_t*)&c00)[i], ((uint8_t*)&c10)[i], ((uint8_t*)&c01)[i], ((uint8_t*)&c11)[i], gxi - gx, gyi - gy); // this is shady
                    result |= (uint8_t) blerp(getByte(c00, i), getByte(c10, i), getByte(c01, i), getByte(c11, i),gx - gxi, gy - gyi) << (8 * i);
                }
                if (result > 0)
                {
                    res[x][y] = 255;
                }
                else
                {
                    res[x][y] = 0;
                }
                y += 1;
            }
            x += 1;
        }
        k+=1;
    }

return MyPic;

}