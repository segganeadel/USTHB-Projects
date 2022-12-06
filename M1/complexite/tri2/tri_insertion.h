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
            for (j = i-1; j >= p; j--)
            {
                t[j+1] = t[j];
            }
            t[p]=x;
               
        }
}
