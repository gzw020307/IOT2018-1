#include<iostream>

#include<cstring>

#define OK 1

#define ERROR 0

#define OVERFLOW -1

using namespace std;

typedef int Elemtype;

typedef struct LNode {

Elemtype date;

struct LNode *next;

} LNode,*linkList;

int inti(linkList &l) {

l= new LNode;

l->next=NULL;

return OK;

}

void creat(linkList &l) {

int n;

linkList p;

printf("2. 请输入链表的长度：");

scanf("%d",&n);

cout<<"  请输入值：";

for(int i=0; i<n; i++) {

p = new LNode;

cin>>p->date;

p->next=l->next;

l->next=p;

}

}

 

void trave (linkList l) {

linkList p;

int len=0;

p=l->next;

cout<<"  链表的值为：";

while(p!=NULL) {

cout<<p->date<<"  ";

p=p->next;

len++;

}

cout<<endl<<"  链表的长度为："<<len<<endl;

}

 

void getelem(linkList l) {

linkList p;

int temp;

int flag=0;

int len=1;

printf("3. 请输入您想要读取的值：");

scanf("%d",&temp);

p=l->next;

while(p!=NULL) {

if(p->date==temp) {

flag=1;

cout<<"数字"<<temp<<"在第"<<len<<"位"<<endl;

break;

}

p=p->next;

len++;

}

if(flag==0)

printf("  此值在链表中不存在\n");

}

 

void insert(linkList l) {

linkList p,temp;

p=l;

temp = new LNode;

int in;

cout<<"4. 请输入要插入的位置：";

cin>>in;

 

cout<<"  请输入插入的数字：";

cin>>temp->date;

for(int i=0; i<in-1; i++) {

p=p->next;

if(p==NULL) {

printf("  错误 \n");

return ;

}

}

temp->next = p->next;

p->next=temp;

}

 

 

void dele(linkList &l) {

linkList p,temp;

int n;

cout<<"5. 请输入你想要删除的元素：";

cin>>n;

p=l;

while(p->next->date!=n ) {

p=p->next;

if(p->next==NULL) {

cout<<"元素不存在"<<endl;

return ;

}

}

temp=p->next;

p->next=p->next->next;

delete[] temp;

}

 

void merge(linkList &la,linkList &lb,linkList &lc) {

linkList pa,pb,pc;

pa=la->next;

pb=lb->next;

lc=la;

pc = lc;

while(pa && pb) {

if(pa->date<=pb->date) {

pc->next =pa;

pc=pa;

pa=pa->next;

} else {

pc->next=pb;

pc=pb;

pb=pb->next;

}

}

pc->next=pa? pa:pb;

delete lb;

}

int main() {

linkList la,lb,lc;

if(inti(la))

cout<<"1. 初始化成功"<<endl<<endl;

creat(la);

trave(la);

cout<<endl;

getelem(la);

cout<<endl;

insert(la);

trave(la);

cout<<endl;

dele(la);

trave(la);

cout<<endl;

inti(lb);

creat(lb);

cout<<endl;

merge(la,lb,lc);

cout<<"6. 归并排序："<<endl;

trave(lc);

cout<<endl;

return 0;

}
