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
    pic = InitPic(pic,"Images/square.bmp");
    pic = end(pic);
    pic = ApplyRLSA(pic,250,500);
    pic = DetectZones(pic);
    restructPic(pic,"res/res.bmp");
    free_(pic);
	return 0;
}
