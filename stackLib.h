#include <stdbool.h>

typedef char string[50];
typedef struct{
	void* elements;
	int elementSize;
	int top;
	int no_of_elements;
}Stack;

Stack* create(int,int);
bool push(Stack* stack,void* element);
void* pop(Stack* stack);
bool isFull(Stack* stack);
bool isEmpty(Stack* stack);

