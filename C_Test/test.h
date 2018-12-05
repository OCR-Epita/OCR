#ifndef TEST_H_
#define TEST_H_

typedef struct
{
    float *fini;
    float *valeur;
    float *liste;
}NEURONE;


//NEURONE initNeurone(size_t nbNeuroneCoucheApres, int biais);

NEURONE ** initMatrice(size_t nbNeuroneCouche0,size_t nbNeuroneCouche1 , size_t nbNeuroneCouche2);

void freeMatrix(NEURONE ** matrix);

void printMatrix(NEURONE ** matrix);

// void propagation(NEURONE ** matrix);

// void backprop(NEURONE ** matrix, float laVraiValeur, size_t nombreNeuroneCouche1,size_t  nombreNeuroneCouche2, float pas);

// void affectNeuroneInMatrix(NEURONE ** matrix, unsigned char ** caractere, size_t hauteur, size_t largeur);

void learn(unsigned char *** letres, NEURONE ** matrix, size_t nbLetres, size_t hauteur, size_t largeur,float pas, size_t nombreNeuroneCouche2, size_t  nombreNeuroneCouche1);

void saveMatrix(NEURONE ** matrix, size_t nombreNeuroneCouche1, size_t nombreNeuroneCouche2);

void loadMatrix(NEURONE ** matrix, size_t nombreNeuroneCouche1, size_t nombreNeuroneCouche2);


#endif
