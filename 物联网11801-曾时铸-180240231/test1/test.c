#include <stdio.h>
#include "sort.h"

#define N 7

int main()
{
    int a[N] = {-2, 4, 7, -3, 9, 1, 6};
    quickSort(a,N);

    printArray(a,N);

    return 0;
}