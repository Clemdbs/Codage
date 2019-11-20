//Ecriture de l’ensemble des fonctions composants la mise en oeuvre du codage deHadamard. Ajout de la technique des séquences d’étalement.
//matrice hadamard : x^n-1 | x^n-1
//                   x^n-1 |-x^n-1
//x[0]=1
//nbUilisateur % 2 tant que c'est possible pour le nb de matrices à faire
//Recopier les matrices d'avant pour éviter les répétitions de calculs
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void hadamard(int longueur){
    int H[][]; //Matrice de hadamard
    int i, j;
    int tempH[][]; //Matrice de save de celle d'hadamard
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
    
}