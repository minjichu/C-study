# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "address.h"


void menu_add(){
	book data;
	data.index = last_index + 1;
	do{
		printf("add New name,number,address \n");
		printf("name : \n");
		scanf(" %s",data.name);
		printf("phone num : \n");
		scanf(" %s",data.phoneNum);
		printf("address : \n");
		scanf(" %s",data.address);
		printf("last index : %ld",last_index);

	}while(strlen(data.name) <=0 || strlen(data.phoneNum) <=0 || strlen(data.address) <=0);
	if(add_book(data)==1){
		printf("Success new data ! \n");
		last_index ++;
		bookNum++;
	}
	else{
		printf("fail to add data \n");
		return;
	}
}


