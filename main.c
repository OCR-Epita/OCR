#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "Files/Utility.h"
#include "Files/Traitement.h"
#include "Files/Binary.h"

void free_(BMPPic_ pic){
    free(pic.PIXELDATA);
    free(pic.HEADERDATA);
    for (size_t i = 0; i < pic.height; i++) {
        free(pic.GREYMATRIX[i]);
    }
    free(pic.GREYMATRIX);
}

int main()
{
    BMPPic_ pic;
    pic = InitPic(pic,"Images/wiki.bmp");
    pic = end(pic);
    pic = ApplyRLSA(pic,250,500);
    pic = DetectZones(pic);
    restructPic(pic,"res/res.bmp");
    free_(pic);

    // for (size_t i = 0; i < 1000; i+= 50) {
    //     for (size_t j = 0; j < 1000; j+=50) {
    //         BMPPic_ pic;
    //         pic = InitPic(pic, "Images/wiki.bmp");
    //         pic = end(pic);
    //         pic = ApplyRLSA(pic,i,j);
    //         char a[124] = "res/";
    //         char b[124];
    //         char c[124];
    //         sprintf(b,"%d",i);
    //         sprintf(c,"%d",j);
    //         strcat(a,b);
    //         strcat(a,"-");
    //         strcat(a,c);
    //
    //
    //         strcat(a,".bmp");
    //         restructPic(pic,a);
    //         free_(pic);
    //         printf("%d - %d \n",i,j);
    //     }
    // }

	return 0;
}
