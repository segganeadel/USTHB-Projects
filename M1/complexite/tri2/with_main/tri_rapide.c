#include <stdio.h>
#include <stdlib.h>


void echanger(int *t, int i,int j){
    int tmp;

    tmp = t[i];
    t[i] = t[j];
    t[j] = tmp;


}

int partition(int *t, int deb , int fin){
    int compt = deb;
    int pivot = t[deb];
    int i;

    for (i= deb+1 ; i <= fin; i++){
        if(t[i] < pivot){
            compt++;
            echanger(t,compt,i);
        }
    }
    echanger(t,compt,deb);
    return compt;
}

void tri_rapide_bis(int *t ,int debut, int fin){
    if (debut<fin){
        int pivot = partition (t,debut,fin);
        tri_rapide_bis(t,debut,pivot-1);
        tri_rapide_bis(t,pivot+1,fin);
        
    }
}

void tri_rapide(int *t, int n){
    tri_rapide_bis(t,0,n-1);
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


        tri_rapide(tab, nb_entiers);


        for (i = 0; i < nb_entiers; i++)
        {
            printf("%3d",tab[i]);
            printf("\n\n");
        }
        
        system("PAUSE");
    return 0;
}
