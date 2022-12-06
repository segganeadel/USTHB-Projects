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
