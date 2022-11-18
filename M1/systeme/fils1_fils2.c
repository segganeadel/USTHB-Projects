#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int a = 5;

void p1()
{   
    printf("je suis le pere\n");
    wait(0);
    wait(0);
}  


void p2()
{
    printf ("je suis le fils1 \n");
    exit(0);
}

void p3()
{
    printf ("je suis le fils2 \n");
    exit(0);
} 


int main(){
    int id =fork();
    if (id == 0) {p2();}
    id = fork();
    if (id == 0) {p3();}
    p1();
    
};