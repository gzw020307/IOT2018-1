#include<stdio.h>
#define MaxSize 20                  //线性表长度
typedef struct
{
    int key;
}RecordType;
 
typedef struct
{
    int length;
    RecordType r[MaxSize + 1];       
}RecordList;
 
int SeqSearch(RecordList l, int key)
{
    int i;
    l.r[0].key = key;                    //将要查找的值赋给监视哨
    i = l.length;
    while (l.r[i].key != key)              
    {
        i--;
    }
    return i;                             //当l.r[i].key == key时返回下标
}
 
int main()
{
    RecordList L = { 6, 0, 12, 15, 20, 25, 45, 50 };
 
    printf("%d\n", SeqSearch(L, 20));            //输出元素20所在的下标
 
    return 0;
}
