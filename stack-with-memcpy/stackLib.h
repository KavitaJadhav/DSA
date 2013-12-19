#include <stdbool.h>

typedef char string[50];
typedef struct{
	void* elements;
	int elementSize;
	int top;
	int no_of_elements;
}Stack;

Stack* create(int,int);
int push(Stack* stack,void* element);
void* pop(Stack* stack);
int isFull(Stack* stack);
int isEmpty(Stack* stack);
void* top(Stack* stack);
