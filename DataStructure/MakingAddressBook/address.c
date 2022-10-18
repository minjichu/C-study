# include "address.h"
# include <stdio.h>
# include <stdlib.h> 
# include <string.h>

book * tail = NULL;
book * head = NULL;


void clear_book();
void init_book(){
	bookNum = 0;
	last_index = 0;
	clear_book();
}

void view_book(book *a){
	
	printf("name : %s\n",a->name);
	printf("phone : %s\n",a->phoneNum);
	printf("address : %s\n",a->address);
}

void printAll_book(){
	book * temp = head;
		
	if(temp == NULL){
		printf("data 비었음 \n");
		return ;
	}else{
		while(temp != NULL){
			view_book(temp);
			temp = temp->next;
		}
	}
	printf("항목 수 : %ld \n",bookNum);
}

int add_book(book data){
	book * temp ; 
	if(data.index == 0) return 0;
	temp = (book*)malloc(sizeof(book));
	if(temp == NULL){
		printf("Lack of memory ! \n");
		return -1;
	}
	printf("data index : %ld\n",data.index);
	temp->index = data.index;
	strcpy(temp->name, data.name);
	printf("temp->name : %s\n",temp->name);
	strcpy(temp->phoneNum, data.phoneNum);
	strcpy(temp->address, data.address);
	temp->next = NULL;
	if(head == NULL){
		head = tail = temp;
		temp->next = NULL;
	}else{
		tail->next = temp;
		tail = temp;
	}
	return 1;
}


int delete_book(int i){
	book * Prevtemp ;
	book * temp = head;
	while(temp != NULL){
		if(temp->index == i){
			break;
		}
		else{
			Prevtemp = temp;
			temp = temp->next;
		}
	}
	if(temp->next != NULL && temp == head){
		head = temp->next;
		free(temp);
		temp->next = NULL;
		return 1;
	}	
	if(temp->next ==NULL && temp == head){
		head = temp->next;
		free(temp);
		return 1;
	
	}
	if(temp->next ==NULL && temp->index != i){
		printf("index Error \n");
		return -1;
	}

	Prevtemp->next = temp->next;
	temp->next = NULL;
	free(temp);
	bookNum --;
	if(i == last_index){
		last_index --;
	}

	return 1;
}

void clear_book(){
	book * temp1 = head;
	book * temp2 ;
	while(temp1 != NULL){
		temp2 = temp1;
		temp1 = temp1->next;
		printf("free node %ld\n",temp2->index);
		free(temp2);
		bookNum--;


	
	}
	head = NULL;
	tail = NULL;
	if(temp1 == NULL && temp2 == NULL){
		printf("clear ALL! \n");
	}
	if(bookNum <= 0){

		last_index = 0;
	}
}



int search_name(char *name){
	book *temp ;
	temp = head;
	int tempIndex = 1;
	while(temp != NULL){
		if(strcmp(temp->name,name) == 0){
			
			break;
		}
		else{
			
			temp = temp->next;
			tempIndex++;
		}
	}
	if(tempIndex > last_index){
		printf("no mathced name in book ! \n");
		return -1;
	}
	return tempIndex;
}
int search_phoneNum(char *phone){
	book *temp ;
	temp = head;
	int tempIndex = 1;
	while(temp != NULL){
		if(strcmp(temp->phoneNum,phone) == 0){
			
			break;
		}
		else{
			
			temp = temp->next;
			tempIndex++;
		}
	}
	if(tempIndex > last_index){
		printf("no mathced phoneNumber in book ! \n");
		return -1;
	}
	return tempIndex;
}

int search_address(char *add){
	book *temp ;
	temp = head;
	int tempIndex = 1;
	while(temp != NULL){
		if(strcmp(temp->adress,add) == 0){
			
			break;
		}
		else{
			
			temp = temp->next;
			tempIndex++;
		}
	}
	if(tempIndex > last_index){
		printf("no mathced address in book ! \n");
		return -1;
	}
	return tempIndex;
}
