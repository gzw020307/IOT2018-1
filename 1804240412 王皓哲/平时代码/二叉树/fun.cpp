#include"head.h"


void CreateBiTree(BiTree &T)	//先序创建二叉树
{								
    char ch;
    cin>>ch;
    if(ch=='#') T=NULL;
    else{
        T=new BiTNode;
        T->data=ch;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
}

void InOrderTraverse(BiTree T)
{//中序遍历
    if(T)
    {
        InOrderTraverse(T->lchild);
        cout<<T->data;
        InOrderTraverse(T->rchild);
    }
}
void PreOrderTraverse(BiTree T)
{//先序遍历
    if(T)
    {
        cout<<T->data;
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
}
void PostOrderTraverse(BiTree T)
{//后序遍历
    if(T)
    {
        PostOrderTraverse(T->lchild);
        PostOrderTraverse(T->rchild);
        cout<<T->data;
    }
}

Status PrintElement(TElemType e)// 输出结点里面的值
{
        cout << e;
        return OK;
}
Status CreateBiThrTree(BiThrTree &T)// 创建线索二叉树
{
        char ch;
        cin >> ch;
        if (ch == '^')
                 T = NULL;
        else
        {
                 if (!(T = (BiThrNode *)malloc(sizeof(BiThrNode))))
                         exit(OVERFLOW);
                 T->data = ch;
                 T->ltag = Link;
                 T->rtag = Link;
                 CreateBiThrTree(T->lchild);
                 CreateBiThrTree(T->rchild);
        }
        return OK;
}

// T指向头结点，头结点的lchild指向根节点，中序遍历线索二叉树
Status InOrderTraverse_Thr(BiThrTree T, Status(*Visit)(TElemType e))
{
        BiThrTree p = T->lchild;
        while (p&&(p != T))
        {
                 while (p->ltag == Link)
                 {                      
                         p = p->lchild;
                 }
                 Visit(p->data);
                 while (p->rtag == Thread && p->rchild != T)
                 {
                         p = p->rchild;
                         Visit(p->data);
                 }
                 p = p->rchild;
        }
        return OK;
}

void InThreading(BiThrTree p,BiThrTree &pre)// 中序遍历进行二叉树线索化
{
        if (p)
        {
                 InThreading(p->lchild,pre);//左子树线索化
                 if (!p->lchild)
                 {
                         p->ltag = Thread;
                         p->lchild = pre;//前驱线索
                 }
                 if ((!pre->rchild)&&pre->rchild==NULL)
                 {
                         pre->rtag = Thread;
                         pre->rchild = p;//后继线索
                 }
                 pre = p;
                 InThreading(p->rchild, pre);//右子树线索化
        }

}

Status InOrderThreading(BiThrTree &Thrt, BiThrTree T)//中序遍历并线索化二叉树T，Thrt指向头结点
{
        if (!(Thrt = (BiThrTree)malloc(sizeof(BiThrNode))))   //建立头结点
                 exit(OVERFLOW);
        Thrt->ltag = Link;
        Thrt->rtag = Thread;
        Thrt->rchild = Thrt;//右指针回指
        BiThrTree pre;
        if (!T)
             Thrt->lchild = Thrt;//若二叉树为空，则左指针回指
        else
        {
                 Thrt->lchild = T;
                 pre = Thrt;
                 InThreading(T,pre);//中序遍历进行中序线索化
                 pre->rchild = Thrt;//最后一个结点线索化
                 pre->rtag = Thread;
                 Thrt->rchild = pre;
        }
        return OK;
}

HuffmanTree create_HuffmanTree(int *wet, int n)
{
	int total = 2 * n - 1;
	HuffmanTree HT = (HuffmanTree)malloc(total * sizeof(HTNode));
	if (!HT)
	{
		printf("HuffmanTree malloc faild!");
		exit(-1);
	}
	int i;
	for (i = 0; i < n; i++)
	{
		HT[i].parent = -1;
		HT[i].lchild = -1;
		HT[i].rchild = -1;
		HT[i].weight = *wet;
		wet++;
	}

	//HT[n],HT[n+1]...HT[2n-2]中存放的是中间构造出的每棵二叉树的根节点  
	for (; i < total; i++)
	{
		HT[i].parent = -1;
		HT[i].lchild = -1;
		HT[i].rchild = -1;
		HT[i].weight = 0;
	}

	int min1, min2; 
	for (i = n; i < total; i++)
	{
		select_minium(HT, i, min1, min2);
		HT[min1].parent = i;
		HT[min2].parent = i;
		HT[i].lchild = min1;
		HT[i].rchild = min2;
		HT[i].weight = HT[min1].weight + HT[min2].weight;
	}
	return HT;
}

void select_minium(HuffmanTree HT, int k, int &min1, int &min2)
{
	min1 = min(HT, k);
	min2 = min(HT, k);
}

int min(HuffmanTree HT, int k)
{
	int i = 0;
	int min;        //用来存放weight最小且parent为-1的元素的序号  
	int min_weight; //用来存放weight最小且parent为-1的元素的weight值  
	while (HT[i].parent != -1)
		i++;
	min_weight = HT[i].weight;
	min = i;
	for (; i < k; i++)
	{
		if (HT[i].weight < min_weight && HT[i].parent == -1)
		{
			min_weight = HT[i].weight;
			min = i;
		}
	}
	HT[min].parent = 1;

	return min;
}
void HuffmanCoding1(HuffmanTree HT, HuffmanCode &HC, int n)
{
	HC = (HuffmanCode)malloc(n * sizeof(char *));
	if (!HC)
	{
		printf("HuffmanCode malloc faild!");
		exit(-1);
	}
	char *code = (char *)malloc(n * sizeof(char));
	if (!code)
	{
		printf("code malloc faild!");
		exit(-1);
	}

	code[n - 1] = '\0';  
	int i;
	for (i = 0; i < n; i++)
	{
		int current = i;           
		int father = HT[i].parent; 
		int start = n - 1;          
		while (father != -1)
		{
			if (HT[father].lchild == current)   
				code[--start] = '0';
			else                                    
				code[--start] = '1';
			current = father;
			father = HT[father].parent;
		}
		HC[i] = (char *)malloc((n - start) * sizeof(char));
		if (!HC[i])
		{
			printf("HC[i] malloc faild!");
			exit(-1);
		}
		strcpy(HC[i], code + start);
	}
	for (int i = 0; i < n; ++i) {
		printf("%s\n", HC[i]);
	}
	free(code); //释放保存编码串的临时空间
}
void HuffmanCoding2(HuffmanTree HT, HuffmanCode &HC, int n)
{
	//用来保存指向每个赫夫曼编码串的指针  
	HC = (HuffmanCode)malloc(n * sizeof(char *));
	if (!HC)
	{
		printf("HuffmanCode malloc faild!");
		exit(-1);
	} 
	char *code = (char *)malloc(n * sizeof(char));
	if (!code)
	{
		printf("code malloc faild!");
		exit(-1);
	}

	int cur = 2 * n - 2;    //当前遍历到的节点的序号，初始时为根节点序号  
	int code_len = 0;   //定义编码的长度  
	int i;
	for (i = 0; i < cur + 1; i++)
	{
		HT[i].weight = 0;
	}

	//从根节点开始遍历，最后回到根节点结束  
	//当cur为根节点的parent时，退出循环  
	while (cur != -1)
	{
		//左右孩子均未被遍历，先向左遍历  
		if (HT[cur].weight == 0)
		{
			HT[cur].weight = 1;    //表明其左孩子已经被遍历过了  
			if (HT[cur].lchild != -1)
			{   //如果当前节点不是叶子节点，则记下编码，并继续向左遍历  
				code[code_len++] = '0';
				cur = HT[cur].lchild;
			}
			else
			{   //如果当前节点是叶子节点，则终止编码，并将其保存起来  
				code[code_len] = '\0';
				HC[cur] = (char *)malloc((code_len + 1) * sizeof(char));
				if (!HC[cur])
				{
					printf("HC[cur] malloc faild!");
					exit(-1);
				}
				strcpy(HC[cur], code);  //复制编码串  
			}
		}
		else if (HT[cur].weight == 1)
		{
			HT[cur].weight = 2;   //表明其左右孩子均被遍历过了  
			if (HT[cur].rchild != -1)
			{   //如果当前节点不是叶子节点，则记下编码，并继续向右遍历  
				code[code_len++] = '1';
				cur = HT[cur].rchild;
			}
		}

		
		else
		{
			HT[cur].weight = 0;
			cur = HT[cur].parent;
			--code_len;
		}

	}
	for (int i = 0; i < n; ++i) {
		printf("%s\n", HC[i]);
	}
	free(code);
}
int countWPL1(HuffmanTree HT, int n)
{
	int i,countRoads,WPL=0;
	/*
	由creat_huffmanTree（）函数可知，HT[0]、HT[1]...HT[n-1]存放的就是各个叶子结点，
	所以挨个求叶子结点的带权路径长度即可
	*/
	for (i = 0; i < n; i++)
	{
		int father = HT[i].parent; //当前节点的父节点
		countRoads = 0;//置当前路径长度为0
		//从叶子节点遍历赫夫曼树直到根节点
		while (father != -1)
		{
			countRoads++;
			father = HT[father].parent;
		}
		WPL += countRoads * HT[i].weight;
	}
	return WPL;
}

int countWPL2(HuffmanTree HT, int n)
{
	int cur = 2 * n - 2;    //当前遍历到的节点的序号，初始时为根节点序号  
	int countRoads=0, WPL=0;//countRoads保存叶子结点的路径长度
	int visit[maxSize] = { 0 };//visit[]是标注数组,初始化为0

	//从根节点开始遍历，最后回到根节点结束  
	//当cur为根节点的parent时，退出循环  
	while (cur != -1)
	{
		//左右孩子均未被遍历，先向左遍历  
		if (visit[cur]==0)
		{
			visit[cur] = 1;    //表明其左孩子已经被遍历过了  
			if (HT[cur].lchild != -1)
			{   //如果当前节点不是叶子节点，则路径长度+1，并继续向左遍历  
				countRoads++;
				cur = HT[cur].lchild;
			}
			else
			{   //如果当前节点是叶子节点，则计算此结点的带权路径长度，并将其保存起来  
				WPL += countRoads * HT[cur].weight;
			}
		}
		else if (visit[cur]==1)
		{
			visit[cur] = 2;
			if (HT[cur].rchild != -1)
			{  
				countRoads++;
				cur = HT[cur].rchild;
			}
		}
		else
		{
			visit[cur] = 0;
			cur = HT[cur].parent;
			--countRoads;
		}

	}
	return WPL;
}