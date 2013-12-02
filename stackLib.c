#include "stackLib.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

Stack* create(int elementSize, int no_of_elements){
	Stack* stack = (Stack*)calloc(1,sizeof(Stack));
	stack->top=-1;
	stack->elements= calloc(no_of_elements,elementSize);
	stack->no_of_elements=no_of_elements;
	stack->elementSize=elementSize;
	return stack;
}
bool push(Stack* stack,void* element)
{
	stack->top++;
	memcpy((stack->elements+(stack->elementSize*stack->top)) , element,stack->elementSize);
	return true;
}

void* pop(Stack* stack)
{
	void* element;
	element = stack->elements+(stack->elementSize*stack->top);
	stack->top--;
	return element;
}

bool isFull(Stack* stack)
{
	return (stack->top+1) == stack->no_of_elements ;
}

bool isEmpty(Stack* stack)
{
	return (stack->top) == -1;
}
