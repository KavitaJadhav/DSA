#include "stackLib.h"
#include <string.h>
#include <stdlib.h>

Stack* create(int elementSize, int no_of_elements){
	Stack* stack = (Stack*)calloc(1,sizeof(Stack));
	stack->top=-1;
	stack->elements= calloc(no_of_elements,elementSize);
	stack->no_of_elements=no_of_elements;
	stack->elementSize=elementSize;
	return stack;
}
int push(Stack* stack,void* element)
{
	if(isFull(stack)) return 0;
	stack->top++;
	memcpy((stack->elements+(stack->elementSize*stack->top)) , element,stack->elementSize);
	return 1;
}

void* pop(Stack* stack)
{
	void* element;
	if(isEmpty(stack)) return 0;
	element = stack->elements+(stack->elementSize*stack->top);
	stack->top--;
	return element;
}

int isFull(Stack* stack)
{
	return (stack->top+1) == stack->no_of_elements ;
}

int isEmpty(Stack* stack)
{
	return (stack->top) == -1;
}
