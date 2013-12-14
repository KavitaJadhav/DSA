#include "stack.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

Stack* createStack(){
	Stack* stack  =createList();
	return stack;
}
bool push(Stack* stack,void* element){
	return insertNode(stack , stack->length, element);
}
void* pop(Stack* stack){
	void* data = top(stack);
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

