#include <stdbool.h>

typedef char string[50];

typedef struct Node{
	void* data;
	struct Node *next;
}Node;

typedef struct List{
	Node* header;
	int length;
}List;

List* createList();
void insertFirst(List* list , int index ,Node* node );
bool deleteNode(List* list , int index);

bool insertNode(List* list , int index , void* data);
void insertMiddle(List* list , int index ,Node* node );
void insertLast(List* list , int index ,Node* node );

void deleteFirst(List* list);
void deleteLast(List* list);
void deleteMiddle(List* list , int index);