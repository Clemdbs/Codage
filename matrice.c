#include <stdio.h>
#include <stdlib.h>
#include "matrice.h"

int creerMatriceH(int longueur){
    int i, j;
    for(i = 0; i < longueur; i++){
        for(j = 0; j < largeur; j++){
            if(i % 2 == 1 && j % 2 == 1)
                mat[i][j] = -1;            
            mat[i][j] = 1;
        }
    }
}

int matriceInverse(int mat[longueur][largeur]){
    int i, j;
    for(i = 0; i < longueur; i++){
        for(j = 0; j < largeur; j++){
            mat[i][j] *= -1;
        }
    }
}