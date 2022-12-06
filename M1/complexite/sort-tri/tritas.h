
void tamiser(int tab[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && tab[left] > tab[largest])
        largest = left;
    if (right < n && tab[right] > tab[largest])
        largest = right;
    if (largest != i) {
        swap(&tab[i], &tab[largest]);
        tamiser(tab, n, largest);
    }
}

void entasser(int tab[],int n){
    int i;
    for (int i = n / 2 - 1; i >= 0; i--)
        tamiser(tab, n, i);   
}

void triTas(int tab[], int n)
{
    entasser(tab,n);
    for (int i = n - 1; i >= 0; i--) {
        swap(&tab[0], &tab[i]);
        tamiser(tab, i, 0);
    }
}

tamiser2(int *tab){

    int len = sizeof(tab)/sizeof(tab[0]);
    int k,j,tmp;

    for (int i = 0; i < len/2 ; i++)
    {
        k = 2*i;
        if(tab[2*i+1] > tab [i])
        {
            j = k+1;
            while (j>0 && tab[j] > tab(j-1)/2)
            {
                tmp = tab[j];
                tab[j] = tab[(j-1)/2];
                tab[(j-1)/2] = tmp;
                j=(j-1)/2;
            }
            
        }
        if((k+2) < len && tab[2*i+2] > tab [i]){
            j=k+2;
            while (j>0 && tab[j] > tab[(j-1)/2])
            {
                tmp = tab[j];
                tab[j] = tab[(j-1)/2];
                tab[(j-1)/2] = tmp;
                j=(j-1)/2;
            }
            
        }
    }
    
}


