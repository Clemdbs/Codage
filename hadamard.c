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

    if(nbUser == 1){
        H[0][0] = 1;
        return H;
    }
    int **Hprec = initMatrice(nbUser/2);
    Hprec = hadamard(nbUser/2);

    int i, j, x, y;
    printf("avant recopie \n");

    //Recopie en haut à gauche
    for(i = 0, x = 0; i < nbUser/2; i++, x++){
        for(j = 0, y = 0; j < nbUser/2; j++, y++){
            H[i][j] = Hprec[x][y];
        }
    }

    //Recopie en haut à droite
    for(i = nbUser/2, x = 0; i < nbUser; i++, x++){
        for(j = 0, y = 0; j < nbUser/2; j++, y++){
            H[i][j] = Hprec[x][y];
        }
    }

    //Recopie en bas à gauche
    for(i = 0, x = 0; i < nbUser/2; i++, x++){
        for(j = nbUser/2, y = 0; j < nbUser; j++, y++){
            H[i][j] = Hprec[x][y];
        }
    }
   
    //Recopie en bas à droite
    for(i = nbUser/2, x = 0; i < nbUser; i++, x++){
        for(j = nbUser/2, y = 0; j < nbUser; j++, y++){
            H[i][j] = -(Hprec[x][y]);
        }
    }
    printf("matrice H\n");
    affich_hadamard(H, nbUser);

    return H;
}

int main() {

    int longueur = 4;
    int **mat = hadamard(longueur);
    //affich_hadamard(mat, longueur);

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