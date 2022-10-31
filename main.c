# include "address.h"
# include "menu.h"
# include <stdio.h>
# include "store_data.h"
int main(){
		
	init_book();
//	printAll_book();

	load_book();
	search_address();
	//printAll_book();
	menu_delete();
	menu_add();
	store_book();
	
	init_book();
	load_book();
	printAll_book();
	return 0;
}

