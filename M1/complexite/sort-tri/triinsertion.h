void triInsertion(int tab[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int tmp = tab[i];
        int j = i;
        while (j > 0 && tmp < tab[j-1])
        {
            tab[j] = tab[j-1];
            j--;
        }
        tab[j] = tmp;
    }
}


/*
triInsertion(entier[] tab, entier N)
    Entier i, k;
    Entier tmp;
    Entier k;
    Pour i de 1 à N-1 faire
        tmp <- tab[i];
        j <- i; 
        Tant que (j > 0 et tab[j - 1] > tmp) faire
            tab[j] <- tab[j - 1];
            j <- j - 1;
        Fait;
    tab[j] <- tmp;
    Fait;
Fin;
*/