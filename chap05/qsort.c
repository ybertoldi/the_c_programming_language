
void swap(void *v[], int i, int j){
    void *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void qsort(void* v[], int l, int r, int(*comp)(void *, void *)){
    int i, last;
    if (l >= r)
        return;
    swap(v, l, (l+r)/2);
    for (i = l+1; i <= r; i++)
    {
        if ((*comp)(v[i], v[l]) < 0){
            swap(v, ++last, i);
        }
    }

    swap(v, l, last);
    qsort(v, l, last-1, comp);
    qsort(v, last+1, r, comp);
}