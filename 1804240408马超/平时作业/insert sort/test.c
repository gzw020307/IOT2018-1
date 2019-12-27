#include <stdio.h>
#define N 8
int main(int argc, char const *argv[])
{
    int a[N] = {6, 3, 7, 9,2, 1, 5, 4};     //把全部分成两块，一个为有序块，一个为无序块，有序块在前面，无序块在后面

    for (int i = 1; i < N; i++)
    {
        int j = i - 1, key = a[i];          //key保存当前值
        while (j >= 0 && a[j] > key)        //循环j使得有序块扩大
        {
            a[j+1] = a[j];                  //使得有序块有序
            j--;
        }        
    
        a[j+1] = key;                       //增加有序块
    }
    
    for (int i = 0; i < N; i++)             //输出
    {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}
