#include<stdio.h>
#include<string.h>
int main()
{
	char a[20];
	printf("请输入需要排序的数字序列:\n");
	gets(a);
	
	int i,j,len,key;
	len = strlen(a);
	
	for(i = 1;i <= len-1;i++)
	{
		key = a[i];
		for(j = i - 1;j >= 0;j--)
		{
			if(a[j] >= key)
			{
				  a[j+1] = a[j];
				  if(j == 0)  a[j] = key;
			}
			else 
			{
				a[j+1] = key;
				break;
			}
		}
	}
	
	for(i = 0;i <= len-1;i++)
	{
		printf("%c",a[i]);
	}
	
	return 0;
}