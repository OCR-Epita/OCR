#include <stdio.h>
#include <stdlib.h>

#include "Utility.h"
#include "Traitement.h"

BMPPic_ getHeader(char data[],BMPPic_ pic){
    pic.header.bftype = *((short *) (data + 0));
    pic.header.bfSize = *((int *) (data + 2));
    pic.header.bfReserved1 = *((short *) (data + 6));
    pic.header.bfReserved2 = *((short *) (data + 8));
    pic.header.bfOffBits = *((data + 10));
    pic.header.biSize = *((int *) (data + 14));
    pic.header.biWidth = *((int *) (data + 18));
    pic.header.biHeight = *((int *) (data + 22));
    pic.header.biSize = *((short *) (data + 26));
    pic.header.biBitCount = *((short *) (data + 28));
    pic.header.biCompression = *((int *) (data + 30));
    pic.header.biSizeImage = *((int *) (data + 34));
    pic.header.biXpelsPerMeter = *((int *) (data + 38));
    pic.header.biYpelsPerMeter = *((int *) (data + 42));
    pic.header.biClrUsed = *((int *) (data + 46));
    pic.header.biClrImportant = *((int *) (data + 50));

    pic.height = pic.header.biHeight;
    pic.width = pic.header.biWidth;

    return pic;
}

BMPPic_ InitGreyMatr(BMPPic_ pic){
    pic.GREYMATRIX = malloc(pic.height * pic.width*sizeof(char));
    for (size_t i = 0; i < pic.height; ++i) {
        pic.GREYMATRIX[i]=malloc(pic.width * sizeof(char));
        for (size_t j = 0; j < pic.width; ++j) {
            Pixel_ tp = getPixel(pic,i,j);
            unsigned char a = (unsigned char) ((tp.B + tp.V + tp.R) / 3);
            pic.GREYMATRIX[i][j]=a;
        }
    }
    return pic;
}


Pixel_ getPixel(BMPPic_ pic,size_t i,size_t j){
    Pixel_ cur;
    cur.R = pic.PIXELDATA[i*pic.width*3 + j*3 + 0];
    cur.V = pic.PIXELDATA[i*pic.width*3 + j*3 + 1];
    cur.B = pic.PIXELDATA[i*pic.width*3 + j*3 + 2];
    return cur;
}

BMPPic_ setPixel(BMPPic_ pic,size_t i,size_t j,Pixel_ pixel){
    pic.PIXELDATA[i*pic.width*3 + j*3 + 0] = pixel.R;
    pic.PIXELDATA[i*pic.width*3 + j*3 + 1] = pixel.V;
    pic.PIXELDATA[i*pic.width*3 + j*3 + 2] = pixel.B;
    return pic;
}

//Same thing for GetPixel but for greyscale image
unsigned char getGray(BMPPic_ myPic,size_t x, size_t y){
    unsigned char res = 0;
    if(x < myPic.height && y < myPic.width)
        res = myPic.GREYMATRIX[x][y];
    return res;
}

//Same thing for SetPixel but for greyscale image
BMPPic_ setGray(BMPPic_ myPic,size_t x, size_t y,unsigned char val){
    //printf("%d \n", myPic.height);
    myPic.GREYMATRIX[x][y] = val;
    return myPic;
}

void restructPic(BMPPic_ pic, char name[]){

    for (size_t i = 0; i < pic.height; ++i) {
        for (size_t j = 0; j < pic.width; ++j) {
            Pixel_ cur;
            cur.R = pic.GREYMATRIX[i][j];
            cur.V = pic.GREYMATRIX[i][j];
            cur.B = pic.GREYMATRIX[i][j];
            pic = setPixel(pic,i,j,cur);
        }
    }
    FILE *ok;
    ok = fopen(name,"w+");
    fwrite(pic.HEADERDATA,(size_t) pic.header.bfOffBits,1,ok);
    fwrite(pic.PIXELDATA,(size_t) pic.header.bfSize - pic.header.bfOffBits,1,ok);
    fclose(ok);
}

BMPPic_ InitPic(BMPPic_ pic,char *path){
    FILE *file = fopen(path,"a+");
    char headerRead[128];
    fread(headerRead, 128, 1, file);
    pic = getHeader(headerRead,pic);
    fseek(file,0,SEEK_SET);
    pic.HEADERDATA = calloc((size_t) pic.header.bfOffBits, sizeof(char));
    fread(pic.HEADERDATA,(size_t) pic.header.bfOffBits,1,file);
    fseek(file,pic.header.bfOffBits,SEEK_SET);
    pic.PIXELDATA = calloc((size_t) pic.header.bfSize - pic.header.bfOffBits, sizeof(char));
    fread(pic.PIXELDATA,(size_t) pic.header.bfSize - pic.header.bfOffBits,1,file);
    pic = InitGreyMatr(pic);
    pic.nbZones = 0;
    return pic;
}
