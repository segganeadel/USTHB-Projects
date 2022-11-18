#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


void p1(int n)
{   
    FILE *fptr;
    char *path = "numbers.txt";
    fptr = fopen(path,"w");
    for(int i=0;i<=n;i++){
    fprintf(fptr,"%d ",i);
    }
        if (!fptr){
        perror(path);}
    fclose(fptr);    
}  

void p2()
{
    FILE *f,*pair;
    f = fopen("numbers.txt","r");
    pair = fopen("numbers_pair.txt","w");
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;


    while ((nread = getline(&line, &len, f)) != -1) {
        if (atoi(line) % 2 == 0){
        fwrite(line, nread, 1, pair);
        }
    }
    fclose(f);
    fclose(pair);
    exit(0);
}

void p3()
{
    FILE *fptr,*impair;
    fptr = fopen("numbers.txt","r");
    impair = fopen("numbers_impair.txt","w");
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;

    while ((nread = getline(&line, &len, fptr)) != -1) {
        if (atoi(line) % 2 == 1){
        fwrite(line, nread, 1, impair);
        }
    }
    fclose(fptr);
    fclose(impair);
    exit(0);
}

void p4(){
    FILE *fptr;
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;
    fptr = fopen("numbers_pair.txt","r");
    while ((nread = getline(&line, &len, fptr)) != -1) {
        fwrite(line, nread, 1, stdout);}
    fclose(fptr);
    exit(0);
}


void p5(){
    FILE *fptr;
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;
    fptr = fopen("numbers_impair.txt","r");
    while ((nread = getline(&line, &len, fptr)) != -1) {
        fwrite(line, nread, 1, stdout);}
    fclose(fptr);
    exit(0);
}

int main(){

    int n;
    int id;

    printf("Donner n: ");
    scanf ( "%d",&n);

    p1(n);
    
    id = fork();
    if (id == 0) {p2();}

    id = fork();
    if (id == 0) {p3();}

    while(wait(NULL) > 0);

    id = fork();
    if (id == 0) {p4();}

    id = fork();
    if (id == 0) {p5();}

    while(wait(NULL) > 0);
};