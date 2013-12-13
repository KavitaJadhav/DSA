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
bool insertNode(List* list , int index , void* data);
bool deleteNode(List* list , int index);

void insertFirst(List* list , int index ,Node* node );
void insertMiddle(List* list , int index ,Node* node );
void insertLast(List* list , int index ,Node* node );
