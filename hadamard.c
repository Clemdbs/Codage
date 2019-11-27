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
#include "encodage.h"

void initMatrice(int **mat){
    int i, j;
    for(i = 0; i < )
}

/*   /!\ Penser à free la matrice en entier /!\   */
int **hadamard(int nbUser){
    int largeur = nbUser, longueur = nbUser;
    int **H = malloc(sizeof(longueur));//Matrice d'hadamard
    H[0][0] = 1;
    int i, j, k;
    int nbBoucle = 0;
    int truc = longueur;

    while(truc != 1){
        truc /= 2;
        nbBoucle++;
    }
   
   
    for (k = 0; k < nbBoucle; k++){
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
    }
    return H;
}


int main(int argc, const char* argv[]){

    int longueur = atoi(argv[1]);
    int mat[longueur][longueur] = hadamard(longueur);
    affich_hadamard(mat[longueur][longueur]);

    //codage du message
    int tailleClair = atoi(argv[2]);
    int messageACoder[tailleClair];
    int tailleMessage =  tailleClair * longueur;
    int messageCoder[tailleMessage];
    coderH(messageACoder, messageCoder, matriceH, ligne, tailleMessage, longueur, tailleClair);

    //decodage du message
    tailleClair = tailleMessage / longueur;//taille du message a coder
    int messageClair[tailleClair];
    decoderH(messageCode, messageClair, matriceH, ligne, tailleMessage, longueur, tailleClair);
}