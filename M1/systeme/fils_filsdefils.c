#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


void p3( int i , int k)
{   
    printf("je suis le sous fils %d  , du fils %d \n", k, i );
     exit(0);
}  

void p1( int n)
{   
 
    int i;
    for(i=1;i<=n;i++) {wait(0);}    
       printf("je suis le pere\n");   
}  

void p2(int i)
{
    int k ;
    printf ("je suis le fils %d \n",i);

     for(k=1;k<=i;k++) {
        int id =fork();
        if (id == 0) {
          p3(i,k)  ;
        }

     }
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