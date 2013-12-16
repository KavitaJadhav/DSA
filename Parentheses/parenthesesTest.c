#include "testUtils.h"
#include "parentheses.h"

void test_1(){
	int status;
	Stack* stack;
	char* data;
	stack=create(20);
	data="On {John McPhee's( Oranges):This[must be the {most [entertaining] }industrial ]report {in English.}}";
	status = matchBraces(stack,data);
	ASSERT(-1==status);
};
void test_2(){
	int status;
	Stack* stack;
	char* data;
	stack=create(20);
	data="{}";
	status = matchBraces(stack,data);
	ASSERT(-1==status);
};
void test_3(){
	int status;
	Stack* stack;
	char* data;
	stack=create(20);
	data="[]";
	status = matchBraces(stack,data);
	ASSERT(-1==status);
};
void test_4(){
	int status;
	Stack* stack;
	char* data;
	stack=create(20);
	data="()";
	status = matchBraces(stack,data);
	ASSERT(-1==status);
};
void test_5(){
	int status;
	Stack* stack;
	char* data;
	stack=create(20);
	data="{[({}[])]}";
	status = matchBraces(stack,data);
	ASSERT(-1==status);
};
void test_6(){
	int status;
	Stack* stack;
	char* data;
	stack=create(20);
	data="{([)}";
	status = matchBraces(stack,data);
	ASSERT(4==status);
};
void test_7(){
	int status;
	Stack* stack;
	char* data;
	stack=create(20);
	data="{()[}";
	status = matchBraces(stack,data);
	ASSERT(2==status);
};
void test_8(){
	int status;
	Stack* stack;
	char* data;
	stack=create(20);
	data="";
	status = matchBraces(stack,data);
	ASSERT(-1==status);
};