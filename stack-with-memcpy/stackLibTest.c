#include "testUtils.h"
#include "stackLib.h"
#include <string.h>

void test_pop_return_false_if_stack_is_empty(){
	Stack* stack = create(sizeof(int),3);
	ASSERT(!pop(stack));
}
void test_push_return_false_if_stack_is_not_full(){
	int elements[] = {5,6,7,8,9};
	Stack* stack = create(sizeof(int),5);
	ASSERT(push(stack , &elements[0]));
	ASSERT(push(stack , &elements[0]));
	ASSERT(push(stack , &elements[0]));
	ASSERT(push(stack , &elements[0]));
}
void test_push_int_element_at_top_of_stack(){
	int element = 5;
	Stack* stack = create(sizeof(int),5);
	push(stack , &element);
	ASSERT(5 == *(int*)pop(stack));
}
void test_push_float_element_at_top_of_stack(){
	float element = 5.5f;
	Stack* stack = create(sizeof(float),5);
	push(stack , &element);
	ASSERT(5.5f == *(float*)pop(stack));
}
void test_push_string_element_at_top_of_stack(){
	string element = "AAA";
	Stack* stack = create(sizeof(string),5);
	push(stack , &element);
	ASSERT(!strcmp("AAA" , *(string*)pop(stack)));
}
void test_isFull_return_true_if_stack_is_full(){
	int elements[] = {5,6,7,8,9};
	Stack* stack = create(sizeof(int),3);
	push(stack , &elements[0]);
	push(stack , &elements[1]);
	push(stack , &elements[2]);
	ASSERT(!push(stack , &elements[0]));
}
void test_top_return_top_element_of_stack(){
	int elements[] = {5,6,7,8,9};
	Stack* stack = create(sizeof(int),3);
	push(stack , &elements[0]);
	push(stack , &elements[1]);
	push(stack , &elements[2]);
	ASSERT(elements[2] == *(int*)top(stack));
}
void test_top_return_top_null_of_stack_if_stack_empty(){
	Stack* stack = create(sizeof(int),3);
	ASSERT(!top(stack));
}
