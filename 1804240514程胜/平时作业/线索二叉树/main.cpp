#include"head.h"
int main()
{
	BiThrTree p,T=NULL;
	printf("��ǰ�����������������\n");
	CreateBiThrTree(T);
	printf("�������������Ϊ��");
	TraverseBT(T);
	InOrderThreading(p, T);
	printf("\n�������ɹ���");
	printf("\n�������Ϊ:");
	//ThreadingThrTree(T);
	//DestoryBiThrTree(T);
	ThreadingThrTree(p);
	return 0;

}