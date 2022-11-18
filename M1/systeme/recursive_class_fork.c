#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

char E[100];
//"(((A+B)*C)-(((D-(F/G))*(H+(K*L)))/((M-N)*O)))";
//"((A+B)*(C-(D/E)))";

char* substr(const char *src, int m, int n)
{
    int len = n - m;
    char *dest = (char*)malloc(sizeof(char) * (len + 1));
    for (int i = m; i < n && (*(src + i) != '\0'); i++)
    {*dest = *(src + i);dest++;    }
    *dest = '\0';
    return dest - len;
}

void lire_exp(){
    printf("Ecrire l'expression : ");
    scanf("%s",E);
}

int chercher_opc(char *E){
    int cpt = -1;
    int i=0;
    int length = strlen(E);
    for(i;i<length;i++){
        if(E[i]=='(') cpt++;
        if(E[i]==')') cpt--;
        if((i!=0)&&(cpt==0)){
            return i+1;
        }
    }
}

int nb_op(char *E){

    int cpt = 0 ;
    int end = chercher_opc(E);
    int i;
    for(i=0;i<end;i++){if(E[i]=='+'||E[i]=='-'||E[i]=='*'||E[i]=='/'){cpt++;}}
    return cpt;
}

void generer_noeud(int noeud){
    printf("T%d: ", noeud);
}

void generer_tache(char *E,int noeud,int opc,int nopg){
    int ge=0;
    int de=0;

    if (E[opc-1]==')') ge=1;
    if (E[opc+1]=='(') de=1;

    if (!ge&&!de){printf("M%d :=%c%c%c\n",noeud,E[opc-1],E[opc],E[opc+1]);}
    if (ge&&!de){printf("M%d :=M%d%c%c\n",noeud,noeud+1,E[opc],E[opc+1]);}
    if (!ge&&de){printf("M%d :=%c%cM%d\n",noeud,E[opc-1],E[opc],noeud+nopg+1);}
    if (ge&&de){printf("M%d :=M%d%cM%d\n",noeud,noeud+1,E[opc],noeud+nopg+1);}
}

void generer_precedence(int noeud,int pere){

    if(pere!=0){printf(" T%d<T%d;\n",noeud,pere);}
}

void genere(char *E,int noeud,int pere){

    int ge=0;
    int de=0;
    
    int id;
    int opc = chercher_opc(E);
    //printf("%d\n",opc);
    int nopg = nb_op(E);
    //printf("%d\n",nopg);

    generer_noeud(noeud); 
    generer_tache(E, noeud, opc, nopg); 
    generer_precedence(noeud, pere); 

    if (E[opc-1]==')') ge=1;
    if (E[opc+1]=='(') de=1;

    
    id = fork();
    if (id !=0){ 
        if (ge) {
            printf("        1ID = %d\n",id);
            genere(substr(E,1,opc),noeud+1,noeud); 
            }
    }


    if (id ==0){   
        if (de) {
          
            printf("        2ID = %d\n",id);
            genere(substr(E,opc+1,strlen(E)-1),noeud+nopg+1,noeud);
            }
        }
 
}

void main(){
    lire_exp();
    genere(E,1,0);

}

//((A+B)*(C-(D/E)))