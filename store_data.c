# include <stdio.h>
# include "address.h"
# include "store_data.h"

void load_book(){
	book data;
	FILE *fp;
	
	fp = fopen("book_data.txt","r");
	if(fp == NULL){
		fputs("file open err ! \n",stdout);
		return;
	}
	while(!feof(fp)){
		data.index = 0;
		if(fread(&data,sizeof(book),1,fp)){
			add_book(data);
		}
	}
	fclose(fp);
	last_index = data.index;
	printf("load successfully\n");
}

void store_book(){
	book * temp;
	FILE *fp ;
	fp = fopen("book_data.txt","w");
	if(fp == NULL){
		fputs("file open err!",stdout);
		return;
	}
	temp = head;
	while(temp != NULL){
		fwrite(temp,sizeof(book),1,fp);
		temp = temp->next;
	}
	fclose(fp);
	printf("store scueessfully! \n");
	clear_book();
}

	


