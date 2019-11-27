#include <stdlib.h>

#define CLE 10
#define TYPE 1

typedef struct corps{
    pid_t pid_client;
    char msg[256];
}corps_t;

typedef struct demande{
    long type;
    corps_t corps;
}demande_t;

typedef struct reponse{
    long type;
    char msg[256];
}reponse_t;