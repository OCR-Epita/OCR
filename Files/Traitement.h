#include "Utility.h"

#ifndef TRAITEMENT_H
#define  TRAITEMENT_H

BMPPic_ DetectOutlines(BMPPic_ pic);

BMPPic_ ApplyRLSA(BMPPic_ pic,int seuil_a,int seuil_b);

void PrintZone(Zone zone);

BMPPic_ DetectZones(BMPPic_ pic);

BMPPic_ DivideZone(BMPPic_ pic);

BMPPic_ DetectChars(BMPPic_ pic);

/*BMPPic_ DetectWords(BMPPic_ pic);*/

#endif
