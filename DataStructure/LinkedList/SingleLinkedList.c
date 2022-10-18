#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct data{
	int num;
	char name[20];
	struct data * next;
	
}data;

data * g_head=NULL;
data * g_tail=NULL;

void printAll(){
	if(g_head == NULL){
		printf("no data \n");
		return;
	}
	data * temp = g_head;
	while(temp->next){
		printf("=====s====\n");
		printf("num : %d\n",temp->num);
		printf("name : %s\n",temp->name);
		temp = temp->next;
			
	} 
	printf("=====s====\n");
	printf("num : %d\n",temp->num);
	printf("name : %s\n",temp->name);
	
}


//insert _ mid
int insert_mid(int num, char *name,int new_num ){
	data * node = (data*)malloc(sizeof(data));  	
	node->num = new_num;
	if(name != NULL){
		strcpy(node->name, name);
	}
	if(g_head == NULL){
		g_head = node;
		g_tail = node;
		node->next = NULL;
		return 1; 
	}
	else{
		data * temp = g_head;
		while(temp){
			if(temp->num == num){
				break;
			}
			temp = temp->next;		
		}		
		node->next = temp->next;
		temp->next = node;
		if(node->next ==NULL){
			g_tail = node;
		}
		return 1;		
	}
	return 0;
	
}

// insert _initial,last
int insert(int num, char *name){
	
	data * node = (data*)malloc(sizeof(data));
	
	node->num = num;
	if(name != NULL){
		strcpy(node->name, name);
	}
	node->next = NULL;	
	
	if(g_head == NULL){
		g_head = node;
		g_tail = node;
		node->next = NULL;
		return 1; 
	}else{
		data * temp = g_head;
		while(temp->next){
			temp = temp->next;
		}
		temp->next = node;
		g_tail = node;
		return 1;
	}
	return 0;
}

int remove_node(int num){
	data * temp = g_head;
	data * before = NULL; 
	if(g_head == NULL){
		printf("non data\n");
		return 0;
	}
	else{
		while(temp){
			if(temp->num == num){
				break;
			}
			before = temp;
			temp = temp->next;
		}
		if(before != NULL){
			before->next = temp->next;	
			if(before->next ==NULL){
				g_tail = before;
			}
		}else{
			g_head = NULL;
			g_tail = NULL;
		}
		free(temp);
		 
	}
	
}

void free_All(){

}

data * find(int num){
	if(g_head == NULL){
		printf("no data\n");
		return NULL;
	}
	data * temp = g_head;
	while(temp){
		if(temp->num == num){
			return temp;
		}
		temp = temp->next;
	}
	//printf("wrong number.., no data...\n");
	return NULL;
}

data * stack_pop() {
	if(g_head == NULL){ //no data 
		return NULL;
	}
	data * node;
//	memcpy(node,g_tail,sizeof(data));
	node = g_tail;
	data * temp = g_head;
	data * before = NULL;
	while(temp->next){ // if there is only one node,  g_tail = before = Null therefore g_head should be null
		before = temp;
		temp = temp->next;
	}
	g_tail = before;
	if(before != NULL){
		before->next =NULL;
	}
	if(g_tail==NULL){
		g_head = NULL;
	}
	return node;
}


data * queue_pop(){
	if(g_head == NULL){
		return NULL;
	}
	data * node = g_head;
	if(g_head->next!=NULL){
		g_head = g_head -> next ;
	}else{
		g_head = NULL;
		g_tail = NULL;
	}
	return node;
}


int main(){
	char name[20] = "";
	int i,j = 0;
	int max = 10;
	for(i=1;i<=max;i++){
		sprintf(name,"test%d",i);
		insert(i,name);
	}
    printAll();
/* for(i=0;i<max;i++){
    	data * node1 = stack_pop();
    	printf("**********\n");
		printf("pop num : %d\n",node1->num);
		printf("pop name: %s\n",node1->name);
		printAll();
		free(node1);*/
/*	for(j=1;j<=max;j++){
		data * node2 = queue_pop();
		printf("**********\n");
		printf("queue num : %d\n",node2->num);
		printf("queue name: %s\n",node2->name);
		printAll();	
		free(node2);	
	}*/
	
/*	data * node = find(7);
	if(node != NULL){
		printf("find num: %d\n",node->num);
		printf("find name: %s\n",node->name);
	}
	else{
		printf("error\n");
	}*/
/*	char new_name[20]="";
	int new_num = 15;
	sprintf(new_name,"new_test%d",new_num);
	insert_mid(6,new_name,new_num);*/
//	remove_node(4);
//	printAll();
	free_All();
    printf("*****************\n");
	printAll();
	//printf("g_h : %d\n",g_head->num);
	printf("g_tail->num = :%d\n",g_tail);
	printf("*g_h : %d\n", &g_head);
	printf("*g_t : %d\n", &g_tail);
	return 0;
}
