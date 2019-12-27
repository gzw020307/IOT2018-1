#include <stdio.h>  
#include <string.h>  
#include <string>  
#include <iostream>  
#include <stack>  
#include <queue>  
#include <vector>  
#include <algorithm>  
#define mem(a,b) memset(a,b,sizeof(a))  
using namespace std;  
const int inf=1<<29;  
int main()  
{  
    int map[10][10],n,m,t1,t2,t3;  
    scanf("%d%d",&n,&m);//n表示顶点个数，m表示边的条数  
    //初始化  
    for(int i=1; i<=n; i++)  
        for(int j=1; j<=n; j++)  
            if(i==j)  
                map[i][j]=0;  
            else  
                map[i][j]=inf;  
    //读入边  
    for(int i=1; i<=m; i++)  
    {  
        scanf("%d%d%d",&t1,&t2,&t3);  
        map[t1][t2]=t3;  
    }  
    //弗洛伊德(Floyd)核心语句  
    for(int k=1; k<=n; k++)  
        for(int i=1; i<=n; i++)  
            for(int j=1; j<=n; j++)  
                if(map[i][k]+map[k][j]<map[i][j])  
                    map[i][j]=map[i][k]+map[k][j];  
    for(int i=1; i<=n; i++)  
    {  
        for(int j=1; j<=n; j++)  
            printf("%10d",map[i][j]);  
        printf("\n");  
    }  
    return 0;  
}  

