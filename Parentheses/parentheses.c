#include "parentheses.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

Stack* create(int no_of_elements){
	Stack* stack = (Stack*)calloc(1,sizeof(Stack));
	stack->top=-1;
	stack->elements= calloc(no_of_elements,sizeof(char));
	stack->no_of_elements=no_of_elements;
	return stack;
}
bool push(Stack* stack,char* element)
{
	stack->top++;
	memcpy((stack->elements+(stack->top)) ,element,sizeof(char));
	memcpy(&stack->topElement,element,sizeof(char));
	return true;
}
char pop(Stack* stack)
{
	char element;
	if(isEmpty(stack)) return false;
	element=stack->topElement;
	stack->top--;
	stack->topElement = stack->elements[stack->top];
	return element;
}
bool isEmpty(Stack* stack)
{
	return (stack->top) == -1;
}
int getstatus(Stack* stack , char* data)
{
	int i;
	for(i = 0; i<strlen(data); i++)
		{
			switch(data[i]){
				case '{' :
				case '[' :
				case '(' :
					push(stack,&data[i]);
					break;
				case '}' :
					if(stack->topElement == '{') pop(stack) ;
					else push(stack,&data[i]);
					break;
				case ']' :
					if(stack->topElement == '[') pop(stack) ;
					else push(stack,&data[i]);
					break;
				case ')' :
	 				if(stack->topElement == '(') pop(stack) ;
					else push(stack,&data[i]);
					break;
				 default:
					break;
			}
		}	
	return stack->top;
}
int main()
{
	Stack* stack;
	int status;
	char* data="On {John McPhee's(Oranges):This[must be the {most [entertaining] }industrial ]report {in English.}}";
	stack=create(20);
	status = getstatus(stack,data);
	if(status== -1) printf("\nvalid statement");
	else printf("\nInvalid statement");
	return 0;
}
