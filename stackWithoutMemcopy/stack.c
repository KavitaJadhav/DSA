#include "stack.h"
#include <stdlib.h>
#include <memory.h>

Stack* create(int length){
    Stack* stack = calloc(1 , sizeof(Stack));
    stack->elements = calloc(length , sizeof(void*));
    stack->top = -1;
    stack->length = length;
    return stack;

}
void isFull(Stack* stack){
    if (stack->top+1 == stack->length){
    	stack->length *= 2;
    	stack->elements = realloc(stack->elements, stack->length* sizeof(void*));
    }
}
int isEmpty(Stack* stack){
    return stack->top == -1;
}
int push(Stack* stack,void* element){
	isFull(stack);
    stack->top++;
    *(stack->elements + (stack->top * sizeof(void*))) = element;
    return 1;
}
void* pop(Stack* stack){
	void* popElement;
    if(isEmpty(stack)) return NULL;
    popElement = top(stack);
    stack->top--;
    return popElement;
}
void* top(Stack* stack){
    if(isEmpty(stack)) return NULL;
    return *(stack->elements + (stack->top * sizeof(stack->elements)));
}
void dispose(Stack* stack){
    free(stack->elements);
    free(stack);
};