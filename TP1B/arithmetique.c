#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// fait par ordre alpha et nombre par ordre d'apparition
int main(){
    int i, j, k, ci, position;
    char ca;
    char message[10] = "BILL GATES";

    // tableau pour la frequence d'apparition des lettres
    // 27 = 26 lettres + ' '
    float alpha[27];//initialiser toutes les cases du tableau a 0
    for(i = 0; i < 27; i++)
    {
        alpha[i] = 0;
    }

    // compter le nombre d'occurence de chaque lettres du message
    for(i = 0; ca != '\0'; i++)
    {
        ci = atoi(&message[i]);
        position = ci - 'A';
        alpha[position] += 1;//incrémenter la case correspondant au caractere courant
    }
    // transforme frequence (fraction)
    for(j = 0, k = 0; k < 27; k++)
    {
        if(alpha[k] != 0)
        {
            alpha[k] /= i;
            j++;//devient le nombre de caracteres different utilisé
        } 
    }

    // tableau pour les bornes sup
    float inter[j];
    // recopie juste pour les lettres qui ont ete utilisé
    for(j = 0, k = 0; k < 27; k++)
    {
        if(alpha[j] != 0)
        {
            inter[j] = alpha[k];
            j++;//devient le nombre de caracteres different utilisé
        }
    }
    // action pour optenir la borne sup de l'interval (la borne inf c'est la case d'avant)
    for(k = 0; k < j; k++)
    {
        inter[k] += inter[k+1];
    }



    // intervalle de codage final
    float code[2] = {0, 0};
    int dif; // ecart entre les deux bornes de l'intervalle
    // codage
    for(i = 0; ca != '\0'; i++)
    {
        ci = atoi(&message[i]);
        position = ci - 'A';
        dif = code[0] - code[1];
        code[0] = code[1] + ( dif * alpha[position - 1]);
        code[1] = code[1] + ( dif * alpha[position]);
        printf("borne inf : %f\t borne sup : %f", code[0], code[1]);
    }
}