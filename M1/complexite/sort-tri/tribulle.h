void triBulle(int tab[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (tab[j] > tab[j + 1])
            {
                swap(&tab[j], &tab[j + 1]);
            }
        }
    }
}

/*
tri_à_bulles(Tableau T,Entier Taille_de_T)
Debut
    Pour i allant de 1 à (taille de T)-1 faire
        Pour j allant de 0 à taille de T-i-1 faire
            Si T[j] > T[j+1]  alors
                echanger(T[j+1],T[j]);
            Fsi;
        Fait;
    Fait;
Fin;

echanger(Entier i, Entier j)
Entier x;
Debut
    x = i;
    i = j;
    j = x;
Fin;
*/