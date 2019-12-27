#include<stdio.h>
int main()
{
	float x ,y,z,t;
	scanf("%f%f%f",&x,&y,&z);
	if(x>=y)
	{
		t=x;x=y;y=t;
	}
	if(x>=z)
	{
		t=x;x=z;z=t;
	}
	if(y>=z)
	{
		t=y;y=z;z=t;
	}
	printf("small to big: %f %f %f",x,y,z);
	printf("\n");
	return 0;
}