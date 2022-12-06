



void tamiser(int *tab,int len){

    int k,j,tmp;

    for (int i = 0; i < len/2 ; i++)
    {
        k = 2*i;
        if(tab[2*i+1] > tab [i])
        {
            j = k+1;
            while (j>0 && tab[j] > tab[(j-1)/2])
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

void tri_par_tas(int *tab,int len){
    int tmp,k;
    int j=0;

    tamiser(tab,len);

    while (len > 1)
    {
        tmp=tab[0];
        tab[0]=tab[len-1];
        tab[len-1]=tmp;
        len--;
        j=0;

        while (2*j+1 < len)
        {
            k=2*j;
            if (k+2 < len)
            {
                if (tab[k+1] > tab[k+2] && tab[j] < tab[k+1])
                {
                    tmp = tab[k+1];
                    tab[k+1] = tab[j];
                    tab[j] = tmp;
                    j=k+1;
                }
                else if (tab[j] < tab [k+2])
                {
                    tmp = tab[k+2];
                    tab[k+2] = tab[j];
                    tab[j] = tmp;
                    j=k+2;
                }
                else
                    break;
                
            }
            else if(k+1 < len)
            {
                if(tab[j] < tab[k+1])
                {
                    tmp = tab[k+1];
                    tab[k+1] = tab[j];
                    tab[j] = tmp;
                }
                break;
            }
            else
                break;
        }
        
    }
    
}