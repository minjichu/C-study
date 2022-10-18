# include <stdio.h>
# include <stdlib.h>


typedef struct node {
	int data;
	struct node * prev;
	struct node * next;
} node;
node * g_head = NULL;
node * g_tail = NULL;


int countNode(){
	unsigned int cnt = 0;
	node * temp = g_head;
	while(temp != NULL){
		temp = temp -> next ;
		cnt++;
	}
	return cnt;
}	

int pushBack (int data){

	node * newNode = (node *)malloc(sizeof(node));
	newNode -> data = data; 
	newNode -> next = NULL;
	newNode -> prev = NULL;

	if(g_head == NULL){
		g_head = newNode;
		g_tail = newNode;
		newNode->next = NULL;
		newNode->prev = newNode;
		return 1;
	}
	else{
		node * temp = g_head;
		while(temp->next != NULL){
			temp = temp->next;
		}//tail node
		temp -> next = newNode;
		newNode-> prev = temp;
		g_tail = newNode;
		return 1;
	}
	return 0;
}

node * getNode(int position, double count){
	node * temp;
	if(position < count/2){
		temp = g_head;
		while(temp != NULL && (--position) >= 0){
			temp = temp->next;
		}
	}else{
		temp = g_tail;
		while(temp != g_head && (++position) < count){
			temp = temp->prev;
			}
	}
	
	return temp;
} 



void removeAll(){
	node * temp = g_tail;
	node * temp2 = g_tail->prev;
	while(temp != g_head){
		temp = temp->prev;
		free(temp->next);
		
	}
	free(temp);
	g_head = NULL;
	g_tail = NULL;
}

void insert(node * ptr , int data ){
	node * newnode = (node *) malloc(sizeof(node));
	newnode->data = data;
	newnode->next = ptr->next;
	newnode->prev = ptr;
	if(ptr->next != NULL){
		ptr->next->prev = newnode;
		ptr->next = newnode;
	}

}

void replaceNode(node * ptr, int data){
	if(g_head == ptr){
		g_head->data = data;
	}else{
		ptr->data = data;
	}
}

		

void remove_node( node * ptr){
	if(g_head == ptr){
		g_head = ptr->next;
		if(g_head != NULL){
			g_head->prev = NULL;
		}
		ptr->prev = NULL;
		ptr->next = NULL;
		free(ptr);
	
	}else{
		node * temp = ptr;
		if(ptr->prev != NULL){
			ptr->prev->next = temp->next;
		}
		if(ptr->next != NULL){
			ptr->next->prev = temp->prev;
		
		}
		free(ptr);
		ptr->prev = NULL;
		ptr->next = NULL;
	}
}

void print_node(){
	if(g_head == NULL){
		printf("Error : head is null \n");
	}
	else {
		node * temp = g_head;
		int i = 0; 
		while(temp){
			printf("node[%d] = %d ",i,temp->data); 
			temp = temp->next;
			i++;
		}
		printf("\n");
	//	printf("cnt  = %d \n", cnt);
	}
}

int main(){
	
	for(int i =0; i<9; i++){
		pushBack(i);
	}
	print_node();
	node * dump = getNode(0,10);
	insert(dump,40);
	replaceNode(dump,99);
	print_node();
	printf("cnt : %d \n",countNode());
	removeAll();
	print_node();
	return 0;
}	
						
