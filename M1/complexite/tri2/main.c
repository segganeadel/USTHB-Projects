#include <stdio.h>
#include <stdlib.h>

#include <math.h>
#include <time.h> 
#include "tri_insertion.h"
#include "tri_bulle.h"
#include "tri_rapide.h"
#include "tri_fusion.h"
#include "tri_tas.h"


void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}

int *ran(int* arr, int n){

    for (int i = 0; i < n; i++)
    {
        arr[i] = rand();
    }
    return arr;
}

int *croissant(int* arr, int n){

    for (int i = 0; i < n; i++)
    {
        arr[i] = i;
    }
    return arr;
}

int *decroissant(int* arr,int n){

    for (int i = 0; i < n; i++)
    {
        arr[i] = n-i;
    }
    return arr;
}

int main()
{
    clock_t start_t, end_t, total_t;

	//int *arr;
	
    long int n = 6;//1*pow(10,2);

    //arr = (int*)malloc(n*sizeof(int));
    int arr[]={65,70,9,16,24,65};
    

    //arr = croissant(arr,n);
    //arr = decroissant(arr,n);
    //arr = ran(arr,n);

    printArray(arr, n);
    
    printf("\n\n");

    start_t = clock();

    //tri_a_bulle(arr, n);
    //tri_rapide(arr,n);
    //tri_insertion(arr,n);//nw
    //tri_fusion(arr,n);//nw
    tri_par_tas(arr, n);

    end_t = clock();

    total_t = (end_t - start_t) / CLOCKS_PER_SEC;

    printArray(arr, n);

    printf("\nThe elapsed time is %f seconds\n", (double)(total_t));

    return 0;
}
