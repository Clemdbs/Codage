//Ecriture de l’ensemble des fonctions composants la mise en oeuvre du codage deHadamard. Ajout de la technique des séquences d’étalement.
//matrice hadamard : x^n-1 | x^n-1
//                   x^n-1 |-x^n-1
//x[0]=1
//nbUilisateur % 2 tant que c'est possible pour le nb de matrices à faire
//Recopier les matrices d'avant pour éviter les répétitions de calculs
#include <stdio.h>
#include <stdlib.h>
#include "matrice.h"
#include "encodage.h"

// int puissance(int nb, int puiss){
//     int i, res;
//     for(i = 0; i < puiss; i++)
//         res = nb * nb;
//     return res;
// }

// int findSize(int nbUser){
//     int i, taille = 0;
//     for(i = 1; i < nbUser; i++)
//         taille = puissance(2,nbUser);
//     return taille;
// }

int **initMatrice(int taille){
    int **mat = malloc(sizeof(int *) * taille);
    int i, j;
    
    //Réservation mémoire à faire 
   
    //malloc chaque case dans les for
    for(i = 0; i < taille; i++){
            mat[i] = malloc(sizeof(int) * taille);
            printf(" pt : %p\n", mat[i]);
    }
    
    //Mise à 0 de la matrice (optionnel)
    for(i = 0; i < taille; i++){
        for(j = 0; j < taille; j++){
            mat[i][j] = 0;
        }
    }
    return mat;
}

void inverserMatrice(int **mat, int taille){
    int i, j;
    for(i = 0; i < taille; i++)
        for(j = 0; j < taille; j++)
            mat[i][j] *= -1;
}


/*   /!\ Penser à free la matrice en entier /!\   */
int **hadamard(int nbUser){
    int **H = initMatrice(nbUser);//Matrice d'hadamard
    // printf(" 2pt : %p\n", H[0]);
    // printf(" 2pt : %p\n", H[1]);
    if(nbUser == 1){
        H[0][0] = 1;
        // H[0][1] = 1;
        // H[1][0] = 1;
        // H[1][1] = -1;
        return H;
    }
    //int taille;//nombre de matrice qu'il va falloir faire avant d'arriver a celle pour coder
    // taille = findSize(nbUser-1);
    int **Hprec = initMatrice(nbUser-1);
    Hprec = hadamard(nbUser-1);


    int i, j;

    //Recopie en haut à gauche
    for(i = 0; i < nbUser/2; i++){
        for(j = 0; j < nbUser/2; j++){
            H[i][j] = Hprec[i][j];
        }
    }

    //Recopie en haut à droite
    for(i = nbUser/2; i < nbUser; i++){
        for(j = 0; j < nbUser/2; j++){
            H[i][j] = Hprec[i][j];
        }
    }

    //Recopie en bas à gauche
    for(i = 0; i < nbUser/2; i++){
        for(j = nbUser/2; j < nbUser; j++){
            H[i][j] = Hprec[i][j];
        }
    }
   
    //Recopie en bas à droite
    for(i = nbUser/2; i < nbUser; i++){
        for(j = nbUser/2; j < nbUser; j++){
            inverserMatrice(Hprec, nbUser);
            H[i][j] = Hprec[i][j];
        }
    }

    return H;
}

int main() {

    int longueur = 2;
    int **mat = hadamard(longueur);
    affich_hadamard(mat, longueur);

    //codage du message
    // int tailleClair = atoi(argv[2]);
    // int messageACoder[tailleClair];
    // int tailleMessage =  tailleClair * longueur;
    // int messageCoder[tailleMessage];
    // coderH(messageACoder, messageCoder, matriceH, ligne, tailleMessage, longueur, tailleClair);

    // //decodage du message
    // tailleClair = tailleMessage / longueur;//taille du message a coder
    // int messageClair[tailleClair];
    // decoderH(messageCode, messageClair, matriceH, ligne, tailleMessage, longueur, tailleClair);
    return 0;
}