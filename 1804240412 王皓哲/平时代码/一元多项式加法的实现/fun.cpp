#include<stdio.h>
#include<stdlib.h>
#include"ADD_HEAD.h"
int menu()
{
	int chioce;
	printf("\n");
	printf("0.exit\n");
	printf("1.creatlist \n");
	printf("2.output \n");
	printf("3.add\n");
	scanf("%d",&chioce);
	return chioce;
}
void Creatlist(Linklist &Head)
{
	Linklist p;
	int i,lenth;
	printf("input the lenth\n");
	scanf("%d",&lenth);
	p=(Linklist)malloc(sizeof(Lnode) );
	if(!p){printf("ÉêÇë¿Õ¼äÊ§°Ü\n");
	exit(-1);
	}
	p->data.coef=0;
	p->data.expn=-1;
	p->next=NULL;
	Head=p;
	
	for(i=0;i<lenth;i++){
		p=(Linklist)malloc(sizeof(Lnode));
		if(!p){printf("ÉêÇë¿Õ¼äÊ§°Ü\n");
		exit(-1);
		}
		printf("input %d coef\n",i+1);
		scanf("%f",&p->data.coef);
		printf("input %d expn\n",i+1);
		scanf("%d",&p->data.expn);
		p->next=Head->next;
		Head->next=p;
	}
	sort(Head);
}
void Print_list(Linklist &Head)
{
	Linklist p;
	p=Head->next;
	if(p){
		printf("%.2f X%d",p->data.coef,p->data.expn);
		for(p=p->next;p;p=p->next){
			printf("+%.2f X%d",p->data.coef,p->data.expn);
		}
	}
	printf("\n");
}
void sort(Linklist &Head)
{
	Linklist p,q,min;
	Elemtype term;
	q=Head->next;
	while(q){
		p=q->next;
		min=q;
		while(p){
			if(p->data.expn < min->data.expn ){
				min=p;
			}
			p=p->next;
		}
		term=min->data;
		min->data=q->data;
		q->data=term;
		q=q->next;
	}
}
int cmp(Linklist a,Linklist b)
{
	if(a->data.expn<b->data.expn) return -1;
	else if(a->data.expn==b->data.expn) return 0;
	else return 1;
}
void Addlist(Linklist &Head)
{
	Linklist Hb,ha,pa,pb,term;
	Creatlist(Hb);
	pa=Head->next;
	pb=Hb->next;
	ha=Head;
	while(pa&&pb){
		switch(cmp(pa,pb)){
			case -1: 
				ha->next=pa;
				ha=ha->next;
				pa=pa->next;
				break;
			case 0:
				ha->next=pa;
				ha->next->data.coef+=pb->data.coef;
				ha=ha->next;
				pa=pa->next;
				pb=pb->next;
			
				break; 
			case 1:
				ha->next=pb;
				ha=ha->next;
				pb=pb->next;
				
				break;
		}
	}
	if(pb){
		ha->next=pb;
	}

}
