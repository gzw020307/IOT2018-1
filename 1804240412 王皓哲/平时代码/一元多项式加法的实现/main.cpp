#include<stdio.h>
#include<stdlib.h>
#include"ADD_HEAD.h"
int main()
{
	Linklist p;
	for(;;){
		switch(menu() ){
			case 0:exit(0);
			case 1:Creatlist(p);break;
			case 2:Print_list(p);break;
			case 3:Addlist(p);break;
			default :printf(" ‰»Î”–ŒÛ\n");break;
				
		} 
	}
	return 0;
}
