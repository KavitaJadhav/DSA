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
	if(stack->header != NULL ) data = top(stack);
	else return 0;
	deleteNode(stack, stack->length-1);
	return data;
}
void* top(Stack* stack){
	Node* node = stack->header;
	void *data;
	while(node->next != NULL) node = node->next;
	data = node->data;
	return data;
}

