#include"head.h"
#include<string>

void Compare(HuffmanTree ht,int n, int &p, int &q)///////////运用引用找到两个最小的数
{
	int i = 1; int j = 1;

	int s=9999999, m=99999999;
	for (i; i <= n; i++)///////先找出最小的那个数
	{
		if (ht[i].weight <= s && ht[i].Parent == NULL)
		{
			p = i;
			s = ht[i].weight;
		}
	}
	for (; j <= n; j++)//////////////////////再找出第二个小的数
	{
		if (ht[j].weight <= m && j != p && ht[j].Parent == NULL)
		{
			q = j;
			m = ht[j].weight;
		}
	}
	
}


void CreateHuffmanTree(HuffmanTree ht, int n, int* w)
{
	int m;
	m = 2 * n - 1;
	ht = (HuffmanTree)malloc((m + 1) * sizeof(THNode));
	for (int b = 1; b <= n; b++)
	{
		ht[b] = { w[b-1],0,0,0 };
	}
	for (int j = n + 1; j <= m; j++)
	{
		ht[j] = { 0,0,0,0 };
	}
	int p,q;
	for (int x = n + 1; x <= m; x++)
	{
		Compare(ht, x - 1, p, q);
		ht[p].Parent = x;
		ht[q].Parent = x;
		ht[x].Lchild = p;
		ht[x].Rchild = q;
		ht[x].weight = ht[p].weight + ht[q].weight;
	}/////哈夫曼树的建立
	for (int iii = 1; iii <= m; iii++)
		cout << ht[iii].weight;
	cout << endl;
	char** List;
	List = (HuffmanNode)malloc((n + 1) * sizeof(char*));
	char* Node;
	Node = (char*)malloc((n + 1) * sizeof(char));
	Node[n] = '\0';
	int o = 1;
	int c ;
	int xiancun;
	int sign;
	for (; o <= n; o++)
	{
		sign = n - 1;
		c = o;
		while (ht[c].Parent != NULL)
		{
			xiancun = ht[c].Parent;
			if (ht[xiancun].Lchild == c)
			{
				Node[sign] = '0';
				
			}
			else
			{
				Node[sign] = '1';
			}
			sign--;
			c = ht[c].Parent;
		}
	
		List[o] = (char*)malloc((n - sign + 1) * sizeof(char));
		memcpy(List[o], &Node[sign], n + 1 - sign);
		int h = 1;
		while (List[o][h]!='\0')
		{
			cout << List[o][h];
			h++;
		}
		cout << "----";
	}






















	/*
	char** hcode;
	hcode = (HuffmanNode)malloc((n+1) * sizeof(char*));
	*hcode = (char*)malloc((n + 1) * sizeof(char));
	char* cd;
	cd = (char*)malloc((n + 1) * sizeof(char));

	cd[n] = '\0';
	int start;
	int p1;
	int c;
	for (int i = 1; i <= n; i++)  
	{
		start = n-1; 
		for (c = i, p1 = ht[i].Parent; p1 != 0; c = p1, p1 = ht[p1].Parent)
		{
			if (ht[p1].Lchild == c)
				cd[--start] = '0';
			else
				cd[--start] = '1'; 
			//hcode[i] = cd[start];
			//memcpy(hcode[i], &cd[n-start],start);
			hcode[i] = (char*)malloc((n - start) * sizeof(char)); 
		strcpy(hcode[i], &cd[start]);
		}
		//free(cd);
		
		cd = (char*)malloc((n + 1) * sizeof(char));
	}
	*/
	
}