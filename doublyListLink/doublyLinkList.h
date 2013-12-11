#include <stdbool.h>

typedef char string[50];

typedef struct Node{
	void* data;
	struct Node *next;
	struct Node *prev;
}Node;

typedef struct List{
	Node* header;
	int length;
}List;

List* createList();
bool insert(List* list , int index , void* data);