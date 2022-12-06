#include <stdio.h>
#include <stdlib.h>

void tri_insertion(int *t , int n){
    int i, j, p;
    int x;
        for(i=1; i<n ; i++){
            x = t[i];
            p = i-1;
            while (t[p] > x && p-- > 0){}           
            p++;
            for (j = i-1; j >= 0; j--)
            {
                t[j+1] = t[j];
            }

            
            t[p]=x;
            
            
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


        tri_insertion(tab, nb_entiers);


        for (i = 0; i < nb_entiers; i++)
        {
            printf("%3d",tab[i]);
            printf(" ");
        }
        
        system("PAUSE");
    return 0;
}
