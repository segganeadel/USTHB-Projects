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

int main()
{
	
	
    long int n = 5*pow(10,4);
    int arr[n+1];

    for (size_t i = 0; i < n; i++)
    {
        arr[i] = rand();
    }
    
    time_t begin = time(NULL);

    triInsertion(arr,n);
    //triBulle(arr, n);
    //triRapide(arr,0,n-1);
    //triFusion(arr,0,n-1);
    //triTas(arr, n-1);

    time_t end = time(NULL);

    printArray(arr, n);

    printf("\nThe elapsed time is %ld seconds\n", (end - begin));

    return 0;
}
