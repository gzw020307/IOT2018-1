#include"hash.h"

int main()
{
    ElemType r[N] = {
        {17,1},{60,2},{29,3},{38,4},{1,5},
        {2,6},{3,7},{4,8},{60,9},{13,10}
    };
    HashTable h;
    int i, j, p;
    KeyType k;
    
    InitHashTable(&h);
    for(i=0;i<N-1;i++)
    {
        // 插入前N-1个记录 
        j=InsertHash(&h,r[i]);
        if(j==DUPLICATE)
        printf("表中已有关键字为%d的记录，无法再插入记录(%d,%d)\n",
        r[i].key,r[i].key,r[i].ord);
    }
    printf("按哈希地址的顺序遍历哈希表:\n");
    TraverseHash(h,print);
    printf("请输入待查找记录的关键字: ");
    scanf("%d",&k);
    j=Find(h,k,&p);
    if(j==SUCCESS)
        print(p,h.elem[p]);
    else
        printf("没找到\n");
    j=InsertHash(&h,r[i]); // 插入第N个记录 
    if(j==0)               // 重建哈希表 
        j=InsertHash(&h,r[i]); // 重建哈希表后重新插入第N个记录 
    printf("按地址顺序遍历重建后的哈希表:\n");
    TraverseHash(h,print);
    printf("请输入关键字: ");
    scanf("%d",&k);
    j=Find(h,k,&p);
    if(j==SUCCESS)
        print(p,h.elem[p]);
    else
        printf("没找到\n");
    DestroyHashTable(&h);
    
    system("pause");
    return 0; 
}