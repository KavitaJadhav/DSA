#include "testUtils.h"
#include "parentheses.h"

void test_fail(){
	int status;
	Stack* stack;
	char* data;
	stack=create(20);
	data="On {John McPhee's( Oranges):This[must be the {most [entertaining] }industrial ]report {in English.}}";
	status = matchBraces(stack,data);
	ASSERT(-1==status);
};
