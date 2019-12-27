#include <stdio.h>
int merge(int r[],int s[],int x1,int x2,int x3)   
{
    int i,j,k;
    i=x1;    
    j=x2+1; 
    k=x1;
    while((i<=x2)&&(j<=x3))   
        if(r[i]<=r[j])  
        {
            s[k] = r[i];
            i++;
            k++;
        }
        else
        {
            s[k]=r[j];
            j++;
            k++;
        }
        while(i<=x2) 
            s[k++]=r[i++];
        while(j<=x3) 
            s[k++]=r[j++];
    return 0;
}

int merge_sort(int r[],int s[],int m,int n)
{
    int p;
    int t[20];
    if(m==n)
        s[m]=r[m];
    else
    {
        p=(m+n)/2;
        merge_sort(r,t,m,p); 
        merge_sort(r,t,p+1,n);
        merge(t,s,m,p,n); 
    }
    return 0;
}

int main()
{
    int a[11];
    int i;
    printf("请输入10个数：\n");
    for(i=1;i<=10;i++)
        scanf("%d",&a[i]); 
    merge_sort(a,a,1,10);  
    printf("排序后的顺序是：\n");
    for(i=1;i<=10;i++)
        printf("%5d",a[i]); 
    printf("\n");
    return 0;
}