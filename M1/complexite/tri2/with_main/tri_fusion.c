#include <stdio.h>
#include <stdlib.h>

void fusion(int *t, int deb1, int fin1, int fin2){
    int *table1 ;
    int deb2 = fin1 +1 ;
    int compt1 = deb1;
    int compt2 = deb2;
    int i;

    table1 = (int *)malloc((fin1-deb1+1)*sizeof(int));
        for (i = deb1; i < fin1; i++)
            table1[i-deb1]=t[i];


        for (i = deb1; i < fin2; i++)
        {
            if(compt1 == deb2 ) 
            break;

            else if (compt2 == fin2+1){
                t[i] = table1[compt1-deb1];
                compt1++;
            }
            else if(table1[compt1-deb1]<t[compt2]){
               
                t[i] = table1[compt1 - deb1];
                compt1++;
            }
            else{
                t[i]=t[compt2];
                compt2++;
            }
        }
    free(table1);    
}

void tri_fusion_bis(int *t, int deb, int fin){
    if (deb!=fin){
            int milieu = (fin+deb)/2;
            tri_fusion_bis(t,deb,milieu);
            tri_fusion_bis(t,milieu+1,fin);
            fusion(t,deb,milieu,fin);
    }


}

void tri_fusion(int *t, int n){
    tri_fusion_bis(t,0,n-1);
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


        tri_fusion(tab, nb_entiers);


        for (i = 0; i < nb_entiers; i++)
        {
            printf("%3d",tab[i]);
            printf("\n\n");
        }
        
        system("PAUSE");
    return 0;
}
