#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "test.h"

NEURONE initNeurone(size_t nbNeuroneCoucheApres, int biais)
{

    NEURONE  neurone;
    neurone.fini = calloc(1, sizeof(float));
    neurone.valeur = calloc(1 , sizeof(float));
    if (biais == -500)
    {
        neurone.fini[0] = -500;
        neurone.valeur[0] = -500;
    }
    else if(biais == 1)
    {
        neurone.valeur[0] = 1;
        neurone.fini[0] = -500;
    }
    else if(biais == -40)
    {
        int num = rand();
        while (num == 1)
        {
            num = rand();
        }
        neurone.valeur[0] = (float) num;
    } else { neurone.valeur[0] = biais;}
    neurone.liste = calloc(nbNeuroneCoucheApres, sizeof(float));
    if(biais == -40)
    {
        size_t i = 0;
        while (i <nbNeuroneCoucheApres)
        {
            neurone.liste[i] = (float) rand();
            i += 1;
        }
    }

    return neurone;
}

// void affectNeuroneInMatrix(NEURONE ** matrix, unsigned char ** caractere, size_t hauteur, size_t largeur)
// {
//     for (size_t i = 0; i < hauteur; i++) {
//         for (size_t j = 0; j < largeur; j++) {
//             matrix[0][largeur*i + j].valeur[0] = (float)caractere[i][j];
//         }
//     }

// }

NEURONE ** initMatrice( size_t nbNeuroneCouche0,size_t nbNeuroneCouche1 ,size_t nbNeuroneCouche2)
{
    NEURONE ** matrix;

    matrix = calloc(3, sizeof(struct NEURONE *));

    matrix[0] = calloc(nbNeuroneCouche0+2, sizeof(NEURONE));

    for (size_t i = 0; i < nbNeuroneCouche0; ++i) {
        matrix[0][i] = initNeurone(nbNeuroneCouche1,-40);
    }

    matrix[0][nbNeuroneCouche0+1] = initNeurone(nbNeuroneCouche1,1);
    matrix[0][nbNeuroneCouche0] = initNeurone(nbNeuroneCouche1,-500);


    matrix[1] = calloc(nbNeuroneCouche1+2, sizeof(NEURONE));

    for (size_t i = 0; i < nbNeuroneCouche1; ++i) {
        matrix[1][i] = initNeurone(nbNeuroneCouche2,0);
    }
    matrix[1][nbNeuroneCouche1+1] = initNeurone(nbNeuroneCouche2,1);
    matrix[1][nbNeuroneCouche1] = initNeurone(nbNeuroneCouche2,-500);


    matrix[2] = calloc(nbNeuroneCouche2+1, sizeof(NEURONE));

    for (size_t i = 0; i < nbNeuroneCouche2; ++i) {
        matrix[2][i] = initNeurone(0,0);
    }
    matrix[2][nbNeuroneCouche2] = initNeurone(0,-500);
    return matrix;
}


void freeNeuronne(NEURONE neurone)
{
    if(neurone.valeur != NULL)
    {
        free(neurone.valeur);
    }
    if(neurone.fini != NULL)
    {
        free(neurone.fini);
    }
    if(neurone.liste != NULL)
    {
        free(neurone.liste);
    }

}

void freeMatrix(NEURONE ** matrix)
{
    size_t i = 0;
    size_t j = 0;
    while (i < 2)
    {
        j = 0;
        while (matrix[i][j].valeur[0] != -500)
        {
            freeNeuronne(matrix[i][j]);
            j +=1;
        }
        freeNeuronne(matrix[i][j]);
        freeNeuronne(matrix[i][j+1]);
        if (matrix[i] != NULL)
        {
            free(matrix[i]);
        }
        i += 1;
    }
    j=0;
    while (matrix[i][j].valeur[0] !=-500)
    {
        freeNeuronne(matrix[i][j]);
        j +=1;
    }
    freeNeuronne(matrix[2][j]);
    free(matrix[2]);
    if (matrix != NULL)
    {
        free(matrix);
    }
}

void printMatrix(NEURONE ** matrix)
{
    size_t i = 0;
    size_t j = 0;
    while (i < 3)
    {
        printf("%zu(",i);

        j = 0;

        while ( matrix[i][j].fini[0] != -500)
        {
            printf(" %f",matrix[i][j].valeur[0]);
            j += 1;
        }
        printf(")\n");
        i +=1;
    }
}

float sigmoide(float net)
{
    return 1/(1+expf(-net));
}

void valActivation( NEURONE n, NEURONE * coucheDavant, size_t nRang)
{
    size_t i = 0;
    float sum = 0;
    while (coucheDavant[i].valeur[0] != -500)
    {
        sum += coucheDavant[i].valeur[0] * coucheDavant[i].liste[nRang];
//        printf("\n%zu,%zu)%f--%f--%f\n", nRang,i,coucheDavant[i].valeur[0],coucheDavant[i].liste[nRang],sum);
        i +=1;
    }
    n.valeur[0] = sigmoide(sum);
//    printf("\n(%f)\n",sigmoide(sum));
}

void propagation(NEURONE ** matrix)
{
    size_t i = 1;
    while (i<3)
    {
        size_t j = 0;
        while (matrix[i][j].fini[0] != -500)
        {
            valActivation(matrix[i][j],matrix[i-1],j);
            j +=1;
        }
        i+=1;
    }
}

void correction(NEURONE ** matrix, float laVraiValeur)
{
    size_t i = 0;
    while (matrix[2][i].fini[0] != -500)
    {
        matrix[2][i].valeur[0] = (laVraiValeur-matrix[2][i].valeur[0])*(matrix[2][i].valeur[0]*(1-matrix[2][i].valeur[0]));
        i+=1;
    }
}

void changePoid(NEURONE ** matrix, size_t numCoucheJ , size_t nombreNeuroneCoucheK, float pas)
{
    size_t  i = 0;
    while (matrix[numCoucheJ][i].valeur[0] != -500)
    {
        size_t j = 0;
        while (j<nombreNeuroneCoucheK)
        {
            matrix[numCoucheJ][i].liste[j] += pas * matrix[numCoucheJ+1][j].valeur[0] * matrix[numCoucheJ][i].valeur[0];
            j += 1;
        }
        i += 1;
    }
}

float sumTransition(NEURONE ** matrix,size_t onEstOu)
{
    float sum = 0;
    size_t i = 0;
    while (matrix[2][i].fini[0] != -500)
    {
        sum += matrix[2][i].valeur[0]* matrix[1][onEstOu].liste[i];
        i +=1;
    }
    return sum;
}

void correctionPartie2(NEURONE ** matrix)
{
    size_t i = 0;
    while (matrix[1][i].fini[0] != -500)
    {
        matrix[1][i].valeur[0] = matrix[1][i].valeur[0]*(1-matrix[1][i].valeur[0])*sumTransition(matrix,i);
        i+=1;
    }
}



void backprop(NEURONE ** matrix, float laVraiValeur, size_t nombreNeuroneCouche2,size_t  nombreNeuroneCouche1, float pas)
{
    propagation(matrix);
    correction(matrix,laVraiValeur);
    changePoid(matrix,1,nombreNeuroneCouche2,pas);
    correctionPartie2(matrix);
    changePoid(matrix,0,nombreNeuroneCouche1,pas);
    propagation(matrix);
}

char exitMatrix(NEURONE ** matrix)
{
    size_t i = 0;
    size_t tmp = 0;
    float max = matrix[2][0].valeur[0];
    while (matrix[2][i].fini[0] != -500)
    {
        if (max< matrix[2][i].valeur[0]) {
            max = matrix[2][i].valeur[0];
            tmp = i;
        }
        i +=1;
    }
    return tmp + 33;
}

//void saveMatrix(NEURONE ** matrix)
//{
//
//}


void initLetreInMatrix(unsigned char ** letres, NEURONE ** matrix, size_t hauteur, size_t largeur)
{
	size_t i = 0;
	while(i < hauteur)
	{
		size_t j = 0;
		while(j < largeur)
		{
			matrix[0][i*hauteur+j].valeur[0] = (float) letres[i][j];
			j += 1;
		}
		i += 1;
	}
}

void learn(unsigned char *** letres, NEURONE ** matrix, size_t nbLetres, size_t hauteur, size_t largeur,float pas, size_t nombreNeuroneCouche2, size_t  nombreNeuroneCouche1)
{
	for (int i = 0; i < 20000; ++i)
	{
		size_t j = 0;
		while(j < nbLetres)
		{
			initLetreInMatrix(letres[j],matrix,hauteur,largeur);
			backprop(matrix,i,nombreNeuroneCouche2,nombreNeuroneCouche1,pas);
		}
		j += 1;
	}
}