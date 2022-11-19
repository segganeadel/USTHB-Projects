int partition(int tab[], int debut, int fin)
{
    int pivot = tab[fin];
    int i = (debut - 1);
    for (int j = debut; j <= fin - 1; j++)
    {
        if (tab[j] <= pivot)
        {
            i++;
            swap(&tab[i], &tab[j]);
        }
    }
    swap(&tab[i + 1], &tab[fin]);
    return (i + 1);
}

void triRapide(int tab[], int debut, int fin)
{
    if (debut < fin)
    {
        int pi = partition(tab, debut, fin);
        triRapide(tab, debut, pi - 1);
        triRapide(tab, pi + 1, fin);
    }
}


