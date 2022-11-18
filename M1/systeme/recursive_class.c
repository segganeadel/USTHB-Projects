#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

char E[]="((A+B)*(C-(D/E)))";

typedef struct Noeud
{   
    char e[]="";
    int start;
    int stop;
    int op;
    int preced;
} Noeud;

void lire_exp(){

    printf("Ecrire l'expression\n");
    scanf("%s",E);
}

int chercher_opc(char *E){
    int cpt = 0;
    int i = 1;
    int length = strlen(E);
    for(i;i<length;i++){
        if(E[i]=='('){cpt++;}
        if(E[i]==')'){cpt--;}
        if((i!=1)&&(cpt==0)){
            return i;
        }
    }
}

void generer_noeud(int noeud){

}

int nb_op(char *E){

    int cpt = 0 ;
    int end = chercher_opc(E);
    int i;
    for(i;i<=end;i++){
        if(E[i]=='+'||E[i]=='-'||E[i]=='*'||E[i]=='/'){cpt++;}}
}


void generer_tache(char *E,int noeud,int op,int j){

}

void generer_precedence(int noeud,int pere){

}

void genere(char *E,int noeud,int pere){
    int index = chercher_opc(E);
    printf("%d",index);

    int op = -1;
    int ge = 0;
    int de = 0;
    int nopg = 0;
    int dg = -1;
    int fg = -1;
    int dd = -1;
    int fd = -1;
    chercher_op(s,start,end,&op,&ge,&de,&nopg,&dg,&fg,&dd,&fd);
    //printf("%d:%c %d %d %d:%c %d:%c %d:%c %d:%c\n",op,s[op],ge,de,dg,s[dg],fg,s[fg],dd,s[dd],fd,s[fd]);


    if (!ge&&!de){printf("T%d: M%d :=%c%c%c\n",i,i,s[dg],s[op],s[dd]);}
    if (ge&&!de){printf("T%d: M%d :=M%d%c%c\n",i,i,i+1,s[op],s[dd]);}
    if (!ge&&de){printf("T%d: M%d :=%c%cM%d\n",i,i,s[dg],s[op],i+nopg+1);}
    if (ge&&de){printf("T%d: M%d :=M%d%cM%d\n",i,i,i+1,s[op],i+nopg+1);}
    
    if (ge) {genere(s,dg,fg,i+1,i);}
    if (de) {genere(s,dd,fd,i+nopg+1,i);}

    if(j!=0){printf(" T%d<T%d;\n",i,j);}
}


void main(){
    //lire_exp();

    genere(E,1,0);
}

//((A+B)*(C-(D/E)))