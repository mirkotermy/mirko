
/*
    Nella funzione max calcolo il massimo ogni volta eliminando l'ultima cella dell'array
    in cui ci avevo posizionato il massimo precedentemente.
    Ogni volta che viene trovato il massimo, ritorna nella funzine quick_sort e che richiama la funzione swap
    che scambia il massimo trovato con l'ultimo elemento dell'array, e l'ultimo elemento dell'array lo mette
    nella posizione dove stava il massimo, per poi incrementare low.
*/
//calcola il massimo di ogni elemento
int max(int *n_max, int h, int array[],int low)
{
    int pos = 0;
    for (int i = 0; i < h+1-low; i++)
    {
        if(*n_max < array[i])
        {
            *n_max = array[i];
            pos = i;
        }
    }
  return pos;
}

//scambia la posizione attuale del massimo con l'ultima
void swap(int *high,int array[], int pos,int *low)
{    
        int temp = array[(*high)-(*low)];
        array[(*high)-(*low)] = array[pos];
        array[pos] = temp;
        (*low)++;
}
//effettua una ricorsione e va avanti finchè low non è maggiore di high
void quick_sort(int array[], int low, int high)
{
    int n_max;
    if(low < high)
    {
        n_max = array[0];
        int pos = max(&n_max, high, array,low);
        swap(&high, array,pos, &low);
        quick_sort(array, low, high);
    }
}
