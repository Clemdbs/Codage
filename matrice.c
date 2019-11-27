#include <stdio.h>
#include <stdlib.h>
#include "matrice.h"

void affich_hadamard(int **mat, int longueur){
    int i, j;
    for(i = 0; i < longueur; i++){
        for(j = 0; j < longueur; j++){
            printf("| ");
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}