#include <stdio.h>
#include <unistd.h>
#include "canal.h"
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <signal.h>

int main(){
    int id;
    demande_t demande;
    reponse_t reponse;

    demande.type = TYPE;
    demande.corps.pid_client = getpid();

    if((id = msgget(CLE, 0666))==-1){
        perror("pb recherche file");
        exit(-3);
    }

    do{
        if(msgsnd(id, &demande, sizeof(struct corps), 0) == -1){
            perror("pb msgsnd");
            exit(-4);
        }
        if(msgrcv(id, &reponse, sizeof(???????), getpid(), 0)==-1){
            perror("pb msgrcv");
            exit(-5);
        }
    }while();

}