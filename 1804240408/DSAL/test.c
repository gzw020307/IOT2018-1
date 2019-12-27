#include <stdio.h>

#include "sort.h"

#define N 8
int main(int argc, char const *argv[])
{
    int a[N] = {6, 10, 13, 5, 8, 3, 2, 11};
    quickSort(a, N);

    printArray(a, N);

    return 0;
}
