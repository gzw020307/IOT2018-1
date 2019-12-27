int partition(int a[], int p, int q)
{
    int x = a[p];
    int i = p, tmp;
    for (int j = p+1; j <= q; j++)
    {
        if (a[j] <= x)
        {
            i++;
            tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
        }        
    }
    tmp = a[i];
    a[i] = a[p];
    a[p] = tmp;   

    return i; 

}

void qSort(int a[], int p, int q)
{
    int r;
    if(p < q)
    {
      r = partition(a, p , q);
      printArray(a, q - p + 1);
      qSort(a, p, r-1);
      qSort(a, r+1, q);
    }
}

void quickSort(int a[], int n)
{
    qSort(a, 0, n-1);
}

void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}