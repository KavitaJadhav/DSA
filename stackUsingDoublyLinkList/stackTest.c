#include "testUtils.h"
#include "stack.h"
#include <stdlib.h>
#include <string.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

void test_pop_element_of_empty_stack_return_false(){
	Stack* stack = createStack();
	ASSERT(!pop(stack));	 
}
void test_push_char_element_at_top_of_stack(){
	char element = 'k';
	Stack* stack = createStack();
	push(stack , &element);
	ASSERT('k' == *(char*)pop(stack));	 
}
void test_push_int_element_at_top_of_stack(){
	int element = 50;
	Stack* stack = createStack();
	push(stack , &element);
	ASSERT(50 == *(int*)pop(stack));	
}
void test_push_string_element_at_top_of_stack(){
	string element = "AAA";
	Stack* stack = createStack();
	push(stack , &element);
	ASSERT(!strcmp("AAA" , *(string*)pop(stack)));	 
}
void test_push_float_element_at_top_of_stack(){
	float element = 50.10f;
	Stack* stack = createStack();
	push(stack , &element);
	ASSERT(50.10f == *(float*)pop(stack));
}
void test_push_int_element_at_top_of_stack1(){
	int elements[] = {10,20,30,40,50};
	Stack* stack = createStack();

	push(stack , &elements[0]);
	push(stack , &elements[1]);
	push(stack , &elements[2]);

	ASSERT(30 == *(int*)pop(stack));	 
	ASSERT(20 == *(int*)pop(stack));	 
	ASSERT(10 == *(int*)pop(stack));	 
}
void test_push_float_element_at_top_of_stack1(){
	float elements[] = {10.5f,20.5f,30.5f,40.5f,50.5f};
	Stack* stack = createStack();

	push(stack , &elements[0]);
	push(stack , &elements[1]);
	push(stack , &elements[2]);

	ASSERT(30.5f == *(float*)pop(stack));	 
	ASSERT(20.5f == *(float*)pop(stack));	 
	ASSERT(10.5f == *(float*)pop(stack));	 
}
void test_push_char_element_at_top_of_stack1(){
	int elements[] = {'A','B','C','D','E'};
	Stack* stack = createStack();

	push(stack , &elements[0]);
	push(stack , &elements[1]);
	push(stack , &elements[2]);

	ASSERT('C' == *(int*)pop(stack));	 
	ASSERT('B' == *(int*)pop(stack));	 
	ASSERT('A' == *(int*)pop(stack));	 
}
void test_pop_string_element_at_top_of_stack(){
	string elements[] = {"AAA","BBB","CCC","DDD","EEE"};
	Stack* stack = createStack();

	push(stack , &elements[0]);
	push(stack , &elements[1]);
	push(stack , &elements[2]);

	ASSERT(!strcmp ("CCC", *(string*)pop(stack)));	 
	ASSERT(!strcmp ("BBB" , *(string*)pop(stack)));	 
	ASSERT(!strcmp ("AAA" , *(string*)pop(stack))); 
}
void test_top_ggives_top_element_of_stack1(){
	int elements[] = {10,20,30,40,50};
	Stack* stack = createStack();

	push(stack , &elements[0]);
	push(stack , &elements[1]);
	push(stack , &elements[2]);

	ASSERT(30 == *(int*)top(stack));	 
}