#include <stdbool.h>

typedef char string[50];
typedef struct Node{
	void* data;
	int priority;
	struct Node *next;
	struct Node *prev;
}Node;
typedef struct Queue{
	Node* head;
	int length;
}Queue;

Queue* createQueue();
int insertData( Queue* queue ,void* data,int priority);
void* DeleteData( Queue* queue);