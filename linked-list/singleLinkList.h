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
int insertNode(List* list , int index , void* data);
int deleteNode(List* list , int index);
void* getElement(List* list , int index);
typedef int (*Compare)(void* element1 , void* element2);
int search(List* list , void* element , Compare compare);
