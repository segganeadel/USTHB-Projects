#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int a = 5;

void p1(n)
{   
    printf("je suis le pere\n");
    int i;
    for(i=1;i<=n;i++) {wait(0);}       
}  

void p2(int n)
{
    printf ("je suis le fils %d \n",n);
    exit(0);
}

int main(){
    int n ;
    int i;
    int id;
    printf("Donner n");
    scanf ( "%d",&n);

    for(i=1;i<=n;i++) {
        id =fork();
        if (id == 0) {p2(i);}     
    }
    p1(n);
};