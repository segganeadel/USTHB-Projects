#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

#include <math.h>
#include <time.h> 
#include "triinsertion.h"
#include "tribulle.h"
#include "trirapide.h"
#include "trifusion.h"
#include "tritas.h"



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

	int *arr;
	
    long int n = 1*pow(10,2);

    arr = (int*)malloc(n*sizeof(int));

    

    //arr = croissant(arr,n);
    //arr = decroissant(arr,n);
    arr = ran(arr,n);

    printArray(arr, n);
    
    printf("\n\n");

    start_t = clock();

    //triInsertion(arr,n);
    //triBulle(arr, n);
    //triRapide(arr,0,n-1);
    //triFusion(arr,0,n-1);
    triTas(arr, n);

    end_t = clock();

    total_t = (end_t - start_t) / CLOCKS_PER_SEC;

    printArray(arr, n);

    printf("\nThe elapsed time is %f seconds\n", (double)(total_t));

    return 0;
}
