#include "../iterator/iterator.h"
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
void* getElement(List* list , int index);
typedef int (*Compare)(void* element1 , void* element2);
int search(List* list , void* element , Compare compare);

Iterator getIterator(List *list);
void* next(Iterator *it);
int hasNext(Iterator* it);