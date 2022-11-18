#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

void chercher_op(char *s,int start,int end,int *op,int *ge,int *de,int *nopg,int *dg,int *fg,int *dd,int *fd){
    int max_exp = 0;
    int cpt = 0 ;
    int cpt2 = 0;
    int done = 0;
    int i = start;
    i++;
    *dg=i;
    for(i;i<=end;i++){
        if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'){cpt2++;}
        if(s[i]=='('){cpt++;max_exp=cpt;}
        if(s[i]==')'){cpt--;}
        if((i!=1)&&(!done)&&(cpt==0)){
        *fg=i;
        *op=i+1;
        *dd=i+2;
        done++;
        *nopg=cpt2;
        if (max_exp!=0){*ge=1;}
        max_exp=0;
        }
    }
    *fd=end-1;
    if (max_exp!=0){*de=1;}
}

void genere(char *s,int start,int end,int i,int j){

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


int main(){

    char s1[]="((A+B)*(C-(D/E)))";
    char s[]="(((A+B)*C)-(((D-(F/G))*(H+(K*L)))/((M-N)*O)))";
    int start = 0;
    int end = strlen(s)-1;
    
    genere(s,start,end,1,0);
}

//(((A+B)*C)-(((D-(F/G))*(H+(K*L)))/((M-N)*O)));