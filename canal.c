#include <stdio.h>
#include <unistd.h>
#include "canal.h"
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <signal.h>

void hand(int sig){
     continu = 0;
}

int main(){
    int id;
    demande_t demande;
    reponse_t reponse;

    demande.
}