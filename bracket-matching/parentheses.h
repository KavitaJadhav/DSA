#include <stdbool.h>
typedef char string[50];

typedef struct{
	char* elements;
	int top ;
	char topElement;
	int no_of_elements;
}Stack;

Stack* create(int no_of_elements);
bool push(Stack* stack,char* element);
char pop(Stack* stack);
bool isEmpty(Stack* stack);
int matchBracket(Stack* stack , char* data);