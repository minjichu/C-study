# include "address.h"
# include <stdio.h>
# include <stdlib.h> 
# include <string.h>



void clear_book();
int count_book();

void init_book(){
	head = NULL;
	tail = NULL;
	bookNum = 0;
	last_index = 0;
	clear_book();
}

void view_book(book *a){
	printf("=========== view book ========\n");	
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
	printf("항목 수 : %d \n",count_book());
}

int add_book(book data){
	book * temp ; 
	if(data.index == 0) return 0;
	temp = (book*)malloc(sizeof(book));
	if(temp == NULL){
		printf("Lack of memory ! \n");
		return -1;
	}
	temp->index = data.index;
	strcpy(temp->name, data.name);
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

void delete_book(int node_num){
	book * temp = head;
	book * prev = NULL;
	

	if(head == NULL){
		printf("no data \n");
		return ;
	}

	if(node_num == temp->index){
		head = temp->next;
	}
		
	while(temp){
		if(temp->index == node_num){
			break;
		}
		prev = temp;
		temp = temp->next;
	}
	if(prev != NULL){
		prev -> next = temp->next;
		if(prev->next == NULL){
			tail = prev;
		}
	}
	if(head->next == NULL){
		tail = NULL;
	}
	temp->next = NULL;
	free(temp);
}
	



void clear_book(){
	book * temp1 = head;
	book * temp2 ;
	while(temp1){
		temp2 = temp1;
		temp1 = temp1->next;
		free(temp2);
		//printf("free %ld node ! \n",temp1->index);
	
	}

	head = NULL;
	tail = NULL;
	int num = 1;
	num = count_book();
	if(num == 0 ){
		printf("clear ALL! \n");
	}else{
		printf("left %d node ! \n",count_book());
		return;

	}

}

int count_book(){
	unsigned int cnt = 0;
	book * temp = head;
	while(temp != NULL){
		temp = temp->next;
		cnt ++;
	}
	return cnt;
}




void search_address(){
	char name[20];
	int i,cnt = 0;
	fputs("put address : ",stdout);
	scanf("%s",name);
	book * temp = head;
	while(temp){
		if(strcmp(temp->address, name) == 0){
			view_book(temp);
			cnt = 1;
		}
		temp = temp->next;
	}
	if(cnt == 0){
		fputs("no data in book !",stdout);
		return;
	}
}

