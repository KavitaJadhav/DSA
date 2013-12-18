#include <stdbool.h>
#include "../doubly-linked-list/doublyLinkList.h"

typedef  List Stack;

Stack* createStack();
int push(Stack* stack,void* element);
void* pop(Stack* stack);
void* top(Stack* stack);