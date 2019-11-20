//Ecriture de l’ensemble des fonctions composants la mise en oeuvre du codage deHadamard. Ajout de la technique des séquences d’étalement.
//matrice hadamard : x^n-1 | x^n-1
//                   x^n-1 |-x^n-1
//x[0]=1
//nbUilisateur % 2 tant que c'est possible pour le nb de matrices à faire
//Recopier les matrices d'avant pour éviter les répétitions de calculs
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "matrice.h"

//Penser à free la matrice en entier /!\
int **hadamard(int longueur){
    int largeur = longueur;
    int **H = malloc(sizeof(longueur));//Matrice d'hadamard
    H[0][0] = 1;
    int i, j;
    int **tempH = malloc(sizeof(longueur));//Matrice de save de celle d'hadamard au cas où
    tempH = H;


    //malloc chaque case dans les for
    for(i = 0; i < longueur/2; i++){
        for(j = 0; j < longueur/2; j++){
            H[i][j] = malloc(sizeof(int));
            H[i][j] = 1;
        }   
    }
    //Histoire du renversement de la matrice préenregistré
    for(i = longueur/2; i < longueur; i++){
        for(j = longueur/2; j < longueur; j++){
            H[i][j] = malloc(sizeof(int));
            H[i][j] = -1;
        }   
    }

    return **H;
}











int main(int argc, const char* argv[]){
    int longueur = atoi(argv[1]);
    int mat[longueur][longueur] = hadamard(longueur);
    affich_hadamard(mat[longueur][longueur]);
}