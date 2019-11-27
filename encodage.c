#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "matrice.h"


//messageACoder => le message que l'on va codé (tableau)
//messageCoder => le message une fois codé (tableau)
//matriceH => la matrice d'hadamard qui a été utilisé pour le codage du message
//ligne => ligne de la matrice d'hadamard
//tailleMessage => taille du message codé
//longueur => taille d'une ligne de la matrice d'hadamard utilisé
void coderH(int *messageACoder, int *messageCoder, int **matriceH, int ligne, int tailleMessage, int longueur, int tailleClair){

    int i, j, k = 0; 
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