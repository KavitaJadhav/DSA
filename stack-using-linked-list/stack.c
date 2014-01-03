#include "stack.h"
#include <string.h>
#include <stdlib.h>

Stack* createStack(){
	Stack* stack  =createList();
	return stack;
}
int push(Stack* stack,void* element){
	return insertNode(stack , stack->length, element);
}
void* pop(Stack* stack){
	void* data;
	if(stack->length == 0 ) return NULL;
	data = top(stack) ;
	deleteNode(stack, stack->length-1);
	return data;
}
void* top(Stack* stack){
	return getElement(stack, stack->length-1) ;
}

