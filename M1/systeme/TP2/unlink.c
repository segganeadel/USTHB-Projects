#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/msg.h>
#include <sys/shm.h>
#include <semaphore.h>
#include <fcntl.h> 

int main(int argc, char const *argv[])
{
    sem_unlink("nv");
    sem_unlink("np");
    sem_unlink("mutex");
    return 0;
}
