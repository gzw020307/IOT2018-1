
#include "stdio.h"
#include "sqhead.h"
//合并(忽略)
void Mergelist_Sq(SqList La,SqList Lb,SqList &Lc)//已知顺序线性表La和Lb的元素按值非递减排列
                                                 //归并La和Lb得到的新的顺序线性表Lc，Lc的元素也按值非递减排列
{
	int *pa,*pb,*pa_last,*pb_last,*pc;
     pa=La.elem;
	 pb=Lb.elem;
	 Lc.listsize=Lc.length=La.length+Lb.length;
	 pc=Lc.elem=(ElemType*)malloc(Lc.listsize*sizeof(ElemType));
	 if(!Lc.elem)
		 exit(OVERFLOW);//存储分配失败
	 pa_last=La.elem+La.length-1;
     pb_last=Lb.elem+Lb.length-1;
	 while(pa<=pa_last&&pb<=pb_last)
	 {
	      if(*pa<=*pb)
			  *pc++=*pa++; 
		  else
			  *pc++=*pb++;
	 }
	 while(pa<=pa_last)
		 *pc++=*pa++;//插入La的剩余元素
	 while(pb<=pb_last)//插入Lb的剩余元素
		 *pc++=*pb++;
}


//删除
Status ListDelete_Sq(SqList &L,int i,ElemType &e)
{
	int *p,*q;
     if((i<1)||(i>L.length))
		 return ERROR;//i值不合法
	 p=&(L.elem[i-1]);//p为被删除元素的位置
	 e=*p;//被删除元素的值赋给e
	 q=L.elem+L.length-1;//表尾元素的位置
	 for(++p;p<=q;++p)*(p-1)=*p;//被删除元素之后的元素左移
	  --L.length;
	  return OK;//表长减一
}


//插入
Status ListInsert_Sq(SqList &L,int i,ElemType e)//在顺序表L中第i个位置之前插入新的元素e  //i的合法值为1<=i<=ListLength_Sq(L)+1
{
     int *newbase,*q,*p;
    if(i<1||i>L.length+1)
		return ERROR;
	if(L.length>=L.listsize)
	{
	    newbase=(ElemType*)realloc(L.elem,(L.listsize+LISTINCREMENT)*sizeof(ElemType));
		if(!newbase)
			exit(OVERFLOW);//存储分配失败
		L.elem=newbase;//新基址
		L.listsize+=LISTINCREMENT;//增加储存容量	
	}
	q=&(L.elem[i-1]);
	for(p=&(L.elem[L.length-1]);p>=q;--p)
		*(p+1)=*p;//插入位置及之后的元素后移
	*q=e;//插入e
	++L.length;//表长增1
    return OK;
}


//查找
Status LocateElem_Sq(SqList La,ElemType i)
{
    ElemType*pa,*pa_last;
	ElemType k=0;
	pa=La.elem;
	pa_last=La.elem+La.length-1;
	while(pa<pa_last)
	{
	   if(*pa==i)
	   {
	       printf("第%d个数是%d",k+1,i);
		   return OK;
	   	   
	   }
	   else
		   *pa++;
	   k++;
	   
	}
	printf("NO Found!!!");
	return FALSE;


}



//构建空线性表
Status InitList_Sq(SqList &L)
{
  
   L.elem=(ElemType*)malloc(LIST_INIT_SIZE*sizeof(ElemType));
   if(!L.elem)
	   exit (OVERFLOW);//存储分配失败
   L.length=0;//空表长度为0
   L.listsize=LIST_INIT_SIZE;//初始存储容量
   return OK;
}


//按顺序从最后输入数据
void InputList(SqList &L)
{
	int n = -1, i, m;
	ElemType e;

	while (n) {								//键入准备输入的元素个数
		printf("请首先键入准备输入的元素个数(最多还能输入%d个元素)，输入0退出:", L.listsize - L.length);
		scanf("%d", &n);
		fflush(stdin);

		if (n > L.listsize - L.length)		//判断输入值可执行性
			printf("线性表容量不足，请重新输入。\n");

		    else if (n < 0)
			    printf("输入非法！");

	       	else if (n == 0)
		     	break;

		else {								//进行循环插入
			printf("请键入要输入的值（共%d个）：", n);
			m = L.length + n;
			for (i = L.length + 1; i <= m; i++) {
					scanf("%d", &e);
					L.elem[i-1] = e;
					L.length++;
			}
			printf("输入完成！\n");
			break;
		}
	}
}
//打印表中元素


//主菜单
void menu(int choose)
{
    ElemType e;
	int i;
   switch(choose)
   {
   case(1):
       InitList_Sq(La);
       InputList(La);
	   for(i=0;i<La.length;i++)
		   printf("%d",La.elem[i]);
	   printf("\n");
	   break;//构建La
   case(2):
	    InitList_Sq(Lb);
       InputList(Lb);
	   for(i=0;i<Lb.length;i++)
		   printf("%d",Lb.elem[i]);
	    printf("\n");
	   break;//构建Lb
   case(3):
	   Mergelist_Sq(La,Lb,Lc);
	   for(i=0;i<Lc.length;i++)
		   printf("%d",Lc.elem[i]);
	   printf("\n");
	   break;//合并
   case(4):
	   printf("Enter：");
	   scanf("%d",&i);
	   LocateElem_Sq(Lc,i);
       printf("\n");
	   break;//查找


   case(5):
       printf("位置和数字：");
	   scanf("%d%d",&i,&e);
       ListInsert_Sq(Lc,i,e);
	   
       for(i=0;i<Lc.length;i++)
		   printf("%d",Lc.elem[i]);
	   printf("\n");
	   break;//插入

   case(6):
       printf("位置和数字：");
	   scanf("%d%d",&i,&e);
       ListDelete_Sq(Lc,i,e);
       for(i=0;i<Lc.length;i++)
		   printf("%d",Lc.elem[i]);
	   printf("\n");
	   break;//删除	   
   }

}
