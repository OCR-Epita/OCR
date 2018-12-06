//
// Created by lucas on 06/11/18.
//

#include "Segmentation.h"
#include "Traitement.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


void Color_colomn (BMPPic_ MyPic,size_t line)
{
    size_t i = 0;

    while(i < MyPic.height)
    {
        if(getGray(MyPic,i,line) == 255) {
            setGray(MyPic, i, line, 80);
        }
        i+=1;
    }
}


BMPPic_ Get_Space_Paragraph (BMPPic_ MyPic,BMPPic_ MySecondPic)
{
    size_t i = 0;
    size_t j;
    float res;
    int *collons = malloc(MyPic.width* sizeof(int));
    for (size_t l = 0; l < MyPic.width; ++l) {
        collons[l] = 0;
    }
    int k =0;


    while(i<MyPic.width)
    {
        j = 0;
        res = 0;
        while(j< MyPic.height)
        {
            if(getGray(MyPic,j,i) == 0)
            {
                res +=1;
            }
            j+=1;
        }
        if(res/MyPic.height < 0.1)
        {
            collons[k] = (int)i;
            Color_colomn(MySecondPic,i);
            k+=1;
        }
        i+=1;
    }

    MyPic.last = k-1;
    MyPic.colons_scope = collons;
    return MyPic;

}

void Color_line (BMPPic_ MyPic,size_t line,int debut,int fin)
{
    int i = debut;

    while(i < fin)
    {
        setGray(MyPic, line, (size_t ) i, 80);
        i+=1;
    }

}

BMPPic_ Get_group (BMPPic_ MyPic,const int* list)
{
    int i = 1;
    int* newlist = calloc(MyPic.width,sizeof(int));
    int res =0;
    int k = 0;
    while(list[i] != 0)
    {
        if((float)(list[i-1 ])/list[i] > 0.98)
        {
            res +=1;
        }
        if(res >= 8)
        {

            newlist[k] = list[i];
            k+=1;
            res = 0;
        }
        i+=1;
    }
    MyPic.colons_scope = newlist;
    return MyPic;
}



BMPPic_ Get_horizontal_Paragraph (BMPPic_ MyPic, BMPPic_ MySecondPic,int debut,int fin)
{
    size_t i = 0;
    int j;
    float res;
    int k = 0;
    while(i < MyPic.height)
    {
        j = debut;
        res = 0;
        while(j< fin)
        {
            if(getGray(MyPic,i,(size_t )j) == 0)
            {
                res +=1;
            }
            j+=1;
        }
        if(res/MyPic.width < 0.04)
        {
            Color_line(MySecondPic,i,debut,fin);
            k+=1;
        }
        i+=1;
    }
    return MyPic;
}

/*void freelife (BMPPic_ MyPic)
{
    free(MyPic.colons_scope);
}

BMPPic_ lignes_traitement (BMPPic_ MyPic, BMPPic_ MySecondPic, size_t x_upper,size_t y_upper, size_t x_bottom, size_t y_bottom)
{

    size_t i;
    size_t j = y_upper;

    while(j < y_bottom)
    {
        int res =0;
        i = x_upper;
        while(i < x_bottom)
        {
            if(getGray(MyPic,i,j) == 0)
            {
                res +=1;
            }
            i+=1;
        }
        if((float)res/(x_bottom-x_upper) < 0.06)
        {
            for (size_t k = 0; k < y_bottom; ++k) {
                for (size_t l = 0; l < x_bottom; ++l) {
                    setGray(MySecondPic, l,k, 80);
                }
            }
        }
        j+=1;
    }
    return MyPic;
}
*/
BMPPic_ coloriage (BMPPic_ Mypic, BMPPic_ MySecondPic)
{
    size_t i =0;
    size_t j = 0;


    while (i < Mypic.height)
    {
        j =0;
        while (j < Mypic.width)
        {
            if(getGray(MySecondPic,i,j) != 80)
            {
                Mypic.GREYMATRIX[i][j] = 0;
            }
            else
            {
                Mypic.GREYMATRIX[i][j] = 255;
            }
            j+=1;
        }
        i+=1;
    }
    return Mypic;
}

BMPPic_ moulinex (BMPPic_ MyPic,BMPPic_ MySecondPic)
{

    Color_colomn(MySecondPic,0);
    MyPic = Get_group(MyPic,MyPic.colons_scope);
    MySecondPic.colons_scope = MyPic.colons_scope;
    int* list = MyPic.colons_scope;
    int i = 0;
    MyPic = Get_horizontal_Paragraph(MyPic,MySecondPic,0,list[i]);
    while( list[i] != 0)
    {
        MyPic = Get_horizontal_Paragraph(MyPic,MySecondPic,list[i]+1,(int)MyPic.width);
        i+=1;
    }

    MyPic = coloriage(MyPic,MySecondPic);

    return MyPic;
}

/*BMPPic_ separation (BMPPic_ MyPic,size_t x,size_t y,size_t size)
{
    size_t i = y;

    while(i <= x + size)
    {
        if(getGray(MyPic,i,y) == 255) {
            setGray(MyPic, i, y, 0);
        }
        y+=1;
        i+=1;
    }
    return MyPic;
}

BMPPic_ cathy (BMPPic_ MyPic,BMPPic_ MySecondPic)
{
    size_t nbr_ligne = MyPic.nbZones;
    Zone *lignes = MyPic.TEXTZONE;
    float res = 0;
    size_t k = 0;
    size_t i =0;

    while(i < nbr_ligne)
    {
        for (size_t j = lignes[i].y; j < lignes[i].width ; ++j) {
            res = 0;
            k = lignes[i].x;
            while (k < lignes[i].height){
                if(getGray(MySecondPic,j,k) == 255)
                {
                    res +=1;
                }
                k+=1;
            }
            if ((res/lignes[i].height) < 0.06)
            {
                //separation(MySecondPic,lignes[i].x,lignes[i].y,lignes[i].height);
                Color_colomn(MySecondPic,k);
            }
        }
        i+=1;
    }
    return MySecondPic;
}
 */



