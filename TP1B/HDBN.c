#include <stdio.h>
#include <stdlib.h>

#define TAILLE_MAX 128

//Prends en pramaètre un int qui définira quel type d'encodage on utilisera, et un message sous forme de chaine de caractère
void HDBN(int data, char* messageChaine){
  //hdbn
  int i = 0, j = 0;
  int dernierUn = -1;
  int dernierViol = -1;
  int message[TAILLE_MAX];
  //On transforme la chaine en tableau d'entiers quand c'est un 1 ou un 0 seulement
  while(messageChaine[i] != '\0'){
    switch(messageChaine[i]){
      case 0:
        message[j] = 0;
        break;
      case 1:
        message[j] = 1;
        break;
      default:
        j--;
    }
    i++;
    j++;
  }

  /*Il y a plus de "data" chiffre 0 d'affilée
  *Et application de l'algo du cours
  *Si c'est un 1 alors on le met à l'inverse du dernier 1
  *Si c'est un 0 alors on regarde si il y a data 0 qui se suivent
  *Si non, on ne touche pas aux 0 
  *SI oui, on fait le codage bipolaire simple
  */
  if(i > j + data){
      i = 0;
      if(dernierViol == 1){
          if(dernierUn == 1){
              message[j] = -1;
              while(i++ < data - 1)
                message[++j] = 0;
              message[++j] = -1;
          }
          else {
              while(i++ < data - 1)
                 message[++j] = 0;
              message[++j] = -1;
          }
          dernierViol = -1;
          dernierUn = -1;
      }
      else {
          if(dernierUn == 1){
              message[j] = -1;
              while(i++ < data - 1)
                 message[++j] = 0;
              message[++j] = 1;
          }
          else {
              while(i++ < data - 1)
                 message[++j] = 0;
              message[++j] = 1;
          }
          dernierViol = 1;
          dernierUn = 1;
      }
  }

}
