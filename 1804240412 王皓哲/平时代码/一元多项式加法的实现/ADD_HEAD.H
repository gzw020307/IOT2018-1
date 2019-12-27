#ifndef ADD
#define ADD
typedef struct {
	float coef;
	int expn;
}Elemtype;
typedef struct Lnode{
	Elemtype data;
	struct Lnode *next;
}Lnode ,*Linklist;
int menu();
void Creatlist(Linklist &Head);
void Print_list(Linklist &Head);
void sort(Linklist &Head);
void Addlist(Linklist &Head);
#endif
