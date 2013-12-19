#include "parentheses.h"
#include <string.h>
#include <stdlib.h>

int matchBracket(Stack* stack , char* data){
	int i;
	for(i = 0; i<strlen(data); i++){
		switch(data[i]){
			case '{' :
			case '[' :
			case '(' :
				push(stack,&data[i]);
				break;
			case '}' :
				if(*(char*)top(stack) == '{') pop(stack) ;
				else push(stack,&data[i]);
				break;
			case ']' :
				if(*(char*)top(stack) == '[') pop(stack) ;
				else push(stack,&data[i]);
				break;
			case ')' :
 				if(*(char*)top(stack) == '(') pop(stack) ;
				else push(stack,&data[i]);
				break;
			 default:
				break;
		}
	}	
	return stack->top;
}

