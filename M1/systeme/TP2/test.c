#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <sys/ipc.h>

#ifdef __linux
#define MSG_R 0400
#define MSG_W 0200
#endif


int msqid;

typedef struct
{
    long mtype;
    int type;
    int filiere;
} reponse;

void proc1()
{
    reponse rep;
    rep.mtype = 2;
    rep.filiere= 2;
    rep.type = 3;
    msgsnd(msqid, &rep, sizeof(reponse), 0);
    exit(0);
}

void proc2()
{
    reponse rep;

    msgrcv(msqid, &rep, sizeof(reponse), 2, 0);
    printf("filiere: %d, type: %d", rep.filiere, rep.type);
    exit(0);
}

int main(int argc, char const *argv[])
{
    char *path = "systemV.c";

    if ((msqid = msgget(ftok(path, (key_t)10),
                        IPC_CREAT | IPC_EXCL | MSG_R | MSG_W)) == -1)
    {
        perror("Echec de msgget");
        exit(1);
    }
    int id;
    id = fork();
    if (id == 0)
    {
        proc1();
    }

    id = fork();
    if (id == 0)
    {
        proc2();
    }

    wait(0);
    wait(0);

    msgctl(msqid, IPC_RMID, 0);
    return 0;
}
