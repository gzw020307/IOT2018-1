#include<stdio.h>

void swap(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}

//划分数组的函数
int split(int a[], int low, int high)
{
    int i = low;    //i指向比较元素的期望位置
    int x = a[i];    //将该数组第一个元素设置为比较元素
    //从数组的第二个元素起开始遍历，若找到的元素大于比较元素，则跳过
    for(int j = low+1;j<=high;j++)
        //若找到了小于比较元素的数，则将其与前面较大的数进行交换
        if (a[j] <= x)
        {
            i++;
            swap(a[i], a[j]);
        }
    swap(a[low], a[i]);    //将比较元素交换到期望位置
    return i;
}

//快速排序
void quicksort(int a[], int low, int high)
{
    if (low < high)
    {
        int i = split(a, low, high);    //划分数组并获得比较元素位置
        quicksort(a, low, i - 1);    //对比较元素左边进行排序
        quicksort(a, i + 1, high);    //对比较元素右边进行排序
    }
}

int main()
{
    int a[] = {19,38,12,40,41,39,54,76,35,47,80,14,9,44,19 };
    int length = sizeof(a) / sizeof(a[0]);
    quicksort(a, 0, length - 1);
    for (int i = 0; i < length; i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}
#include <iostream>

using namespace std;

//将子序列归并为一个完整序列
void Merge(int* a, int first, int mid, int last, int* res)
{
    //将a[first mid] a[mid+1 last]排序合并
    int first_start = first, first_end = mid;
    int second_start = mid + 1, second_end = last;
    int res_index = 0;
    while (first_start <= mid && second_start <= last)
    {
        if (a[first_start] < a[second_start])
            res[res_index++] = a[first_start++];
        else
            res[res_index++] = a[second_start++];
    }

    while (first_start <= mid)
        res[res_index++] = a[first_start++];

    while (second_start <= last)
        res[res_index++] = a[second_start++];

    //拷贝回原来的空间
    for (int i = 0; i < res_index; i++)
        a[first + i] = res[i];
}

//递归不断划分区间
void merge_sort(int* a, int first, int last, int* res)
{
    if (first >= last)
        return;

    int mid = (first + last) / 2;
    merge_sort(a, first, mid, res);     //左边有序    
    merge_sort(a, mid + 1, last, res);  //右边有序    
    Merge(a, first, mid, last, res);    //将左右两个有序数列进行排序归并
}


bool MergeSort(int a[], int n)
{
    int *res = new int[n];
    if (res == NULL)
        return false;
    merge_sort(a, 0, n - 1, res);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    delete[] res;
    return true;
}


int main()
{
    int a[] = {19,38,12,40,41,39,54,76,35,47,80,14,9,44,19 };
    MergeSort(a, sizeof(a) / sizeof(a[0]));

    system("pause");
    return 0;
}
