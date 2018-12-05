#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "Files/Utility.h"
#include "Files/Traitement.h"
#include "Files/Segmentation.h"
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
    BMPPic_ pic = InitPic(pic,"Images/wiki_2.bmp");

    BMPPic_ second = InitPic(second,"Images/wiki_2.bmp");

    pic = end(pic);

    second = end(second);

    pic = ApplyRLSA(pic,200,500);

    pic = ApplyRLSA(pic,180,500);

    pic = Get_Space_Paragraph(pic,second);

    pic = moulinex(pic,second);

    pic = DetectZones(pic);

    restructPic(pic,"../result/first.bmp");

    restructPic(second,"../result/second.bmp");
    
    second = cathy(pic,second);

    restructPic(pic,"result/first.bmp");
    restructPic(second,"result/second.bmp");



    free_(pic);

    free_(second);

	return 0;
}
