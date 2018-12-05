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
    printf("___ MAIN ___ \n");

    BMPPic_ pic = InitPic(pic,"../Images/wiki_2.bmp");
    printf("1 > \n");

    BMPPic_ second = InitPic(second,"../Images/wiki_2.bmp");
    printf("2 > \n");

    pic = end(pic);
    printf("end 1 > \n");

    second = end(second);
    printf("end 2 > \n");

    pic = ApplyRLSA(pic,180,500);
    printf("rlsa > \n");

    pic = Get_Space_Paragraph(pic,second);
    printf("get space paragraph > \n");

    pic = moulinex(pic,second);
    printf("moulinex > \n");

    pic = DetectZones(pic);
    printf("detect zones > \n");

    
    second = cathy(pic,second);
    printf("cathy > \n");

    restructPic(pic,"../result/first.bmp");

    restructPic(second,"../result/second.bmp");

    free_(pic);

    free_(second);

	return 0;
}
