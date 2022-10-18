# include "address.h"
# include "menu.h"
# include <stdio.h>

int main(){
		
	init_book();
//	printAll_book();
	for(int i=0; i<3; i++){

		menu_add();
	}	
	printAll_book();
	//clear_book()
	printf("delete what? input index \n");
	int k=0;
	scanf("%d",&k);
	delete_book(k);
	printAll_book();
	clear_book();
	printAll_book();
	menu_add();
	printAll_book();
	return 0;
}

