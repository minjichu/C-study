#ifndef __ADDRESS_H__
#define __ADDRESS_H__
#define MAX_SIZE 20

unsigned long bookNum;
unsigned long last_index;
typedef struct book {
	unsigned long index;
	char name[MAX_SIZE];
	char phoneNum[MAX_SIZE];
	char address[MAX_SIZE];
	struct book * next;
}book;

void init_book();
void clear_book();
int delete_book(int l);
int add_book(book data);
void printAll_book();
void view_book(book * data);




#endif
