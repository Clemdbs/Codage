//Ecriture de l’ensemble des fonctions composants la mise en oeuvre du codage deHadamard. Ajout de la technique des séquences d’étalement.
//matrice hadamard : x^n-1 | x^n-1
//                   x^n-1 |-x^n-1
//x[0]=1
//nbUilisateur % 2 tant que c'est possible pour le nb de matrices à faire
//Recopier les matrices d'avant pour éviter les répétitions de calculs
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matrice.h"
#include "encodage.h"

#define TAILLE_SEQ 3

//SEGfault sur la 4eme boucle

typedef struct etalement_s{
  int* sequence3Bits;//Tableau qui stocke la séquence aléatoire des bits pour le calcul de la séquence
  int* ligneHadamard;//Tableau qui stocke la ligne qui correspond à l'utilisateur
  int* sequence;//Tableau qui stocke la séquence après les calculs
}etalement_t;

/*Retourne un tableau de binaire*/
void etalement(int longueur, int **matrice){

  srand (time (NULL));

  etalement_t hadamarddd;

  int sequence3Bits[TAILLE_SEQ];
  int sequenceFinale[longueur * TAILLE_SEQ];

  int i,j,k,l,m,n;
  int o;
  hadamarddd.sequence3Bits = malloc(sizeof(int));
  hadamarddd.ligneHadamard = malloc(sizeof(int));
  hadamarddd.sequence = malloc(sizeof(int));

  //initialisation du tableau qui va stocker le résultat final
  for(i = 0; i < longueur * TAILLE_SEQ; i++)
    sequenceFinale[i] = 0;

  for(i = 0; i < longueur; i++){
    printf("Ligne de la matrice pour l'utilisateur %d : ",i);
    for(j = 0; j < longueur; j++){
      printf("%d\n", matrice[i][j]);
      hadamarddd.ligneHadamard[j] = matrice[i][j];
    }

    printf("Séquence de 3 bits aléatoires : ");

    for(k = 0; k < TAILLE_SEQ; k++){
      sequence3Bits[k] = rand() & 1;
      printf("%d\n", sequence3Bits[k]);
      hadamarddd.sequence3Bits[k] = sequence3Bits[k];
      // fprintf(stderr, "ici, j : %d, tableau struct sequence3bits : %d\n", j, hadamarddd.sequence3Bits[k]);
    }

    //Pour chaque bit de la séquence 3 bits faire
    for(l = 0; l < TAILLE_SEQ; l++){
      //Si le bit vaut 0
      if(hadamarddd.sequence3Bits[l] == 0){
        //multiplier toute la séquence correspondante par -1
        for(m = 0; m < longueur; m++){
          // fprintf(stderr, "ici, j : %d, tableau struct lignehadamard : %d\n", j, hadamarddd.ligneHadamard[m]);
          hadamarddd.sequence[m] = hadamarddd.ligneHadamard[m] *= -1;
          // fprintf(stderr, "\n\nici, j : %d, tableau struct lignehadamard : %d\n", j, hadamarddd.ligneHadamard[m]);
        }
      }
      else{
        for(m = 0; m < longueur; m++){
          hadamarddd.sequence[m] = hadamarddd.ligneHadamard[m];
          // fprintf(stderr, "ici, j : %d, tableau struct sequence : %d\n", j, hadamarddd.sequence[m]);
        }
      }
    }

    for(n = 0; n < longueur * TAILLE_SEQ; n++){
      sequenceFinale[n] += hadamarddd.sequence[n];
      //Débugage
      //fprintf(stderr, "sequenceFinale : %d\n", sequenceFinale[n]);
      //printf("Séquence finale après étalement : %d\n", sequenceFinale[n]);
    }
    fprintf(stderr,"\n");
  }
  //Débugage
  // for(o = 0; o < longueur * TAILLE_SEQ; o++)
  //   fprintf(stderr, "sequenceFinale FIN: %d\n", sequenceFinale[o]);

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
    /*printf("avant recopie \n");*/

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

int main(int argc, char* argv[]) {

    int longueur = 4;
    int **mat = hadamard(longueur);
    etalement(longueur, mat);

    //codage du message
    // int tailleClair = atoi(argv[2]);
    // int messageACoder[tailleClair];
    // int tailleMessage =  tailleClair * longueur;
    // int messageCoder[tailleMessage];
    // int ligne = 1;//Ligne de la matrice hadamard
    // coderH(messageACoder, messageCoder, mat, ligne, tailleMessage, longueur, tailleClair);
    //
    // // //decodage du message
    // tailleClair = tailleMessage / longueur;//taille du message a coder
    // int messageClair[tailleClair];
    // decoderH(messageCoder, messageClair, mat, ligne, tailleMessage, longueur, tailleClair);
    return 0;
}
