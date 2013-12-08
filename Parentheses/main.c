#include "parentheses.h"
#include <stdio.h>

int main()
{
	Stack* stack;
	int status;
	char* data="On {John McPhee's(Oranges):This[must be the {most [entertaining] }industrial ]report {in English.}}";
	stack = create(20);
	status = matchBraces(stack,data);
	if(status == -1) printf("\nvalid statement");
	else printf("\nInvalid statement");
	return 0;
}