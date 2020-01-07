#include <stdio.h>
#include <stdlib.h>
#include "matrice.h"

//Fonction d'affichage d'une matrice
void affich_hadamard(int **mat, int longueur){
    int i, j;
    for(i = 0; i < longueur; i++){
        for(j = 0; j < longueur; j++){
            printf("|");
            printf(" %3d", mat[i][j]);
        }
        printf(" |\n");
    }
}

//Fonction d'initialisation de la matrice
int **initMatrice(int taille){
    int **mat = malloc(sizeof(int *) * taille);
    int i, j;

    //Réservation mémoire à faire

    //malloc chaque case dans les for
    for(i = 0; i < taille; i++){
            mat[i] = malloc(sizeof(int) * taille);
    }

    //Mise à 0 de la matrice (optionnel)
    for(i = 0; i < taille; i++){
        for(j = 0; j < taille; j++){
            mat[i][j] = 0;
        }
    }
    return mat;
}

//Fonction qui inverse la valeur des cases de la matrice passée en paramètre
void inverserMatrice(int **mat, int taille){
    int i, j;
    for(i = 0; i < taille; i++)
        for(j = 0; j < taille; j++)
            mat[i][j] *= -1;
}
