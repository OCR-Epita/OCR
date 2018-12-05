#include <stdio.h>
#include "test.h"


int main()
{
    size_t nombreNeuroneCouche0 = 6*5;
    size_t nombreNeuroneCouche1 = 12;
    size_t nombreNeuroneCouche2 = 90;

    NEURONE ** test = initMatrice(nombreNeuroneCouche0,nombreNeuroneCouche1,nombreNeuroneCouche2);

    // unsigned char *** listeChar;


    // printMatrix(test);

    // printf("\n");

    // affectNeuroneInMatrix(test,listeChar,6,5);


    // for (size_t i = 0; i < 20000; ++i) {
    //
    // }


    // test[0][0].liste[0] = 2556;

    // saveMatrix(test,nombreNeuroneCouche1,nombreNeuroneCouche2);

    printf("%f\n",test[0][0].liste[0]);

    loadMatrix(test,nombreNeuroneCouche1,nombreNeuroneCouche2);

    // printMatrix(test);

    printf("%f\n",test[0][0].liste[0]);


    printf("\n");


    freeMatrix(test);

//    char test = 70;
//    printf("%c\n",test);

    return 0;
}
