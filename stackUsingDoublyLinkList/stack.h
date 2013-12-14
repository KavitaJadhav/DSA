#include <stdbool.h>
#include "../doublyListLink/doublyLinkList.h"

typedef  List Stack;

Stack* createStack();
bool push(Stack* stack,void* element);
void* pop(Stack* stack);
void* top(Stack* stack);