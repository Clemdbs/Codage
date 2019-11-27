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

int findSize(int nbUser){
    int i, taille = 0;
    for(i = 1; i < nbUser; i++)
        taille = pow(2,i);
    return taille;
}

void initMatrice(int taille, int **mat){
    mat = malloc(sizeof(taille));
    int i, j;
    
    //Réservation mémoire à faire 
   
    //malloc chaque case dans les for
    for(i = 0; i < taille; i++){
            mat[i] = malloc(sizeof(int) * taille);
    }
    
    //Mise à 0 de la matrice (optionnel)
    for(i = 0; i < taille; i++){
        for(i = 0; i < taille; i++){
            mat[i][j] = 0;
        }
    }
}

int **inverserMatrice(int **mat, int taille){
    int i, j;
    for(i = 0; i < taille; i++){
        for(j = 0; j < taille; j++){
            mat[i][j] *= -1;
        }   
    }
    return mat;
}


/*   /!\ Penser à free la matrice en entier /!\   */
int **hadamard(int nbUser){
    int taille;
    int **H;
    initMatrice(nbUser, H);//Matrice d'hadamard
    if(nbUser == 1){
        H[0][0] = 1;
        H[0][1] = 1;
        H[1][0] = 1;
        H[1][1] = -1;
        return H;
    }
    taille = findSize(nbUser-1);
    int **Hprec ;
    initMatrice(taille, Hprec);
    Hprec = hadamard(nbUser-1);


    int i, j;

    //Recopie en haut à gauche
    for(i = 0; i < taille/2; i++){
        for(j = 0; j < taille/2; j++){
            H[i][j] = Hprec[i][j];
        }
    }

    ////Recopie en haut à droite
    for(i = taille/2; i < taille; i++){
        for(j = 0; j < taille/2; j++){
            H[i][j] = Hprec[i][j];
        }
    }

    ////Recopie en bas à gauche
    for(i = 0; i < taille; i++){
        for(j = taille/2; j < taille; j++){
            H[i][j] = Hprec[i][j];
        }
    }
   
    ////Recopie en bas à droite
    for(i = 0; i < taille; i++){
        for(j = taille/2; j < taille; j++){
            H[i][j] = inverserMatrice(Hprec, taille);
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