#include <stdio.h>
#include <stdlib.h>

#define TRUE 1 ;
#define FALSE 0 ;

void tri_a_bulle(int *t,int n){

    int j;
    int tmp = 0;
    int en_desordre = 1 ;
    
    while (en_desordre)
    {
        en_desordre = FALSE ;
        for (j = 0; j < n-1 ; j++)
        {
            if(t[j]>t[j+1]){
                tmp = t[j+1];
                t[j+1] = t[j];
                t[j] = tmp;

                en_desordre = TRUE;
            }
        }
        
    }
    
}


int main(int argc, char const *argv[])
{
    int nb_entiers;
    int *tab;
    int i;

    printf("Donner le nombre d'entiers que vous voulez trier: ");
    scanf("%d",&nb_entiers);


    tab = (int *)malloc(nb_entiers*sizeof(int));


    printf("\n");

        for (i=0; i < nb_entiers ;i++){
            printf("Donner l'entier %d: ",i+1);
            scanf("%d",&tab[i]);
        }


        tri_a_bulle(tab, nb_entiers);


        for (i = 0; i < nb_entiers; i++)
        {
            printf("%3d",tab[i]);
            printf("\n\n");
        }
        
        system("PAUSE");
    return 0;
}