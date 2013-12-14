#include "testUtils.h"
#include "stack.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

void test_create_stack(){
	Stack* stack;
	stack = createStack();
	ASSERT(stack->header == NULL);	 
	ASSERT(stack->length == 0);	 
}
void test_push_char_element_at_start_of_stack(){
	Stack* stack;
	char element = 'k';
	stack = createStack();
	push(stack , &element);
	ASSERT(stack->header != NULL);	 
	ASSERT(*(char*)stack->header->data == 'k');	 
	ASSERT(stack->length == 1);	 
}
void test_push_int_element_at_start_of_stack(){
	Stack* stack;
	int element = 10;
	stack = createStack();
	push(stack , &element);
	ASSERT(stack->header != NULL);	 
	ASSERT(*(int*)stack->header->data == 10);	 
	ASSERT(stack->length == 1);	 
}
void test_push_string_element_at_start_of_stack(){
	Stack* stack;
	string element;
	strcpy(element , "Shital");
	stack = createStack();
	push(stack , &element);
	ASSERT(stack->header != NULL);	 
	ASSERT(!strcmp(*(string*)stack->header->data , "Shital"));	 
	ASSERT(stack->length == 1);	 
}
void test_push_float_element_at_start_of_stack(){
	Stack* stack;
	float element = 10.5f;
	stack = createStack();
	push(stack , &element);
	ASSERT(stack->header != NULL);	 
	ASSERT(*(float*)stack->header->data == 10.5f);	 
	ASSERT(stack->length == 1);	 
}
void test_push_int_element_at_top_of_stack(){
	Stack* stack;
	int element1 = 10,element2 = 20,element3 = 30;
	stack = createStack();
	push(stack , &element1);
	push(stack , &element2);
	push(stack , &element3);
	ASSERT(*(int*)stack->header->data == 10);	 
	ASSERT(*(int*)stack->header->next->data == 20);	 
	ASSERT(*(int*)stack->header->next->next->data == 30);	 
	ASSERT(stack->length == 3);	 
}
void test_pop_int_element_at_top_of_stack(){
	Stack* stack;
	int data;
	int element1 = 10,element2 = 20,element3 = 30;
	stack = createStack();
	push(stack , &element1);
	push(stack , &element2);
	push(stack , &element3);
	ASSERT(stack->length == 3);
	data =(int)pop(stack);	 
	ASSERT(stack->length == 2);	 
	ASSERT(*(int*)data == 30);	 
}
void test_pop_float_element_at_top_of_stack(){
	Stack* stack;
	int data;
	float element1 = 10.5f,element2 = 20.5f,element3 = 30.5f;
	stack = createStack();
	push(stack , &element1);
	push(stack , &element2);
	push(stack , &element3);
	ASSERT(stack->length == 3);
	data =(int)pop(stack);	 
	ASSERT(stack->length == 2);	 
	ASSERT(*(float*)data == 30.5);	 
}
void test_pop_string_element_at_top_of_stack(){
	Stack* stack;
	int data;
	string element1 , element2 , element3 ;
	strcpy(element1 , "kajal");
	strcpy(element2 , "manali");
	strcpy(element3 , "shweta");
	stack = createStack();
	push(stack , &element1);
	push(stack , &element2);
	push(stack , &element3);
	ASSERT(stack->length == 3);
	data =(int)pop(stack);	 
	ASSERT(stack->length == 2);	 
	ASSERT(!strcmp(*(string*)data , "shweta"));	 
}
void test_top_gives_element_at_top_of_stack(){
	Stack* stack;
	int data;
	int element1 = 10,element2 = 20,element3 = 30;
	stack = createStack();
	push(stack , &element1);
	push(stack , &element2);
	push(stack , &element3);
	ASSERT(30 == *(int*)top(stack));
}
