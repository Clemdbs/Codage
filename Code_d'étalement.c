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

//renvoyer une matrice et pas un int, faire une structure
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
            H[i][j] = 1;
        }   
    }

    return **H;
}







//messageCode => le message codé
//messageClair => matrice pour le message une fois qu'il sera decodé
//ligne => ligne de la matrice d'hadamard
//matriceH => la matrice d'hadamard qui a été utilisé pour le codage du message
//tailleMessage => taille du message codé
//longueur => taille d'une ligne de la matrice d'hadamard utilisé
void decodeH(int *messageCode, int *messageClair, int matriceH, int ligne, int tailleMessage, int longueur){
    int i, j, k = 0;
    int tailleClair = tailleMessage / longueur;
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

    //decodage du message
    int tailleClair = tailleMessage / longueur;//taille du message a coder
    int messageClair[tailleClair];
    decodeH(messageCode, messageClair, matriceH, ligne, tailleMessage, longueur);
    
    int longueur = atoi(argv[1]);
    int mat[longueur][longueur] = hadamard(longueur);
}