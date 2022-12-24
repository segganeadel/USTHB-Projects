#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <sys/ipc.h>

void sem_delete(int semid)
{
    if (semctl(semid, 0, IPC_RMID, 0) == -1)
        perror("Erreur dans destruction semaphore");
}

int main(int argc, char const *argv[])
{
    msgctl(18, IPC_RMID, 0);
    shmctl(62, IPC_RMID, 0);
    shmctl(63, IPC_RMID, 0);
    sem_delete(54);
    sem_delete(55);
    sem_delete(56);
    return 0;
}
