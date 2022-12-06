#include <stdio.h>
#include <stdlib.h>

void fusion(int tab[], int debut, int milieu, int fin){
    int i, j, k;
    int n1 = milieu - debut + 1;
    int n2 = fin - milieu;
    int GAUCHE[n1], DROIT[n2];
    for (i = 0; i < n1; i++)
        GAUCHE[i] = tab[debut + i];
    for (j = 0; j < n2; j++)
        DROIT[j] = tab[milieu + 1 + j];
    i = 0;
    j = 0;
    k = debut;
    while (i < n1 && j < n2)
    {
        if (GAUCHE[i] <= DROIT[j])
        {
            tab[k] = GAUCHE[i];
            i++;
        }
        else
        {
            tab[k] = DROIT[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        tab[k] = GAUCHE[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        tab[k] = DROIT[j];
        j++;
        k++;
    }    
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
