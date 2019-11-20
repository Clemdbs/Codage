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


//messageACoder => le message que l'on va codé (tableau)
//messageCoder => le message une fois codé (tableau)
//matriceH => la matrice d'hadamard qui a été utilisé pour le codage du message
//ligne => ligne de la matrice d'hadamard
//tailleMessage => taille du message codé
//longueur => taille d'une ligne de la matrice d'hadamard utilisé
void coderH(int *messageACoder, int *messageCoder, int **matriceH, int ligne, int tailleMessage, int longueur, int tailleClair){

    int i, k = 0; 
    int tailleChiffreCode = tailleMessage / tailleClair;

    for(i = 0; i < tailleClair; i++){
        for(j = 0; j < tailleChiffreCode; j++, k++){
            messageCoder[k] = messageACoder[i] * matriceH[ligne][j]; 
        }
    }
}



//messageCode => le message codé (tableau)
//messageClair => le message une fois qu'il sera decodé (tableau)
//matriceH => la matrice d'hadamard qui a été utilisé pour le codage du message
//ligne => ligne de la matrice d'hadamard
//tailleMessage => taille du message codé
//longueur => taille d'une ligne de la matrice d'hadamard utilisé
void decoderH(int *messageCode, int *messageClair, int **matriceH, int ligne, int tailleMessage, int longueur, int tailleClair){

    int i, j, k = 0;
    int tailleChiffreCode = tailleMessage / tailleClair;
    int decodage[tailleMessage];
    
    //initialisation du tableau pour le message clair
    for(i = 0; i < tailleMessage; i++){
        messageClair[i] = 0;
    }

    //recopie du message codé dans un autre tableau pour le traitement
    for(i = 0; i < tailleMessage; i++){
        decodage[i] = messageCode[i];
    }

    //traitement de la copie
    for(i = 0; i < tailleClair; i++){//traitement pour un chiffre du message clair qui a été codé
        for(j = 0; j < tailleChiffreCode; j++, k++){//traitement la ligne du message codé correspondant a un chiffre
            //multiplication par la ligne de la matrice utilisée par le user(=ligne)
            decodage[k] *= matriceH[ligne][j];
            //addition des cases pour le traitement pour un chiffre du message clair qui a été codé
            messageClair[i] += decodage[j]; 
        }
        messageClair[i] /= longueur;
    }
}






int main(int argc, const char* argv[]){

    //codage du message
    int messageACoder[tailleClair];
    int tailleMessage =  tailleClair * longueur;
    int messageCoder[tailleMessage];
    coderH(messageACoder, messageCoder, matriceH, ligne, tailleMessage, longueur, tailleClair);

    //decodage du message
    int tailleClair = tailleMessage / longueur;//taille du message a coder
    int messageClair[tailleClair];
    decoderH(messageCode, messageClair, matriceH, ligne, tailleMessage, longueur, tailleClair);
    
    int longueur = atoi(argv[1]);
    int mat[longueur][longueur] = hadamard(longueur);
    affich_hadamard(mat[longueur][longueur]);
}