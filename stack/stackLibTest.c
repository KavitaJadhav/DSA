#include "testUtils.h"
#include "stackLib.h"
#include <string.h>

void test_create_stack_allocates_memory_for_five_int_elements(){
	int i;
	Stack* stack;
	int test_arr[] = {0,0,0,0,0};
	stack = create(sizeof(int),5);
	i=memcmp(test_arr,stack->elements,5);
	ASSERT(!i);
	ASSERT(stack->elementSize == 4);
	ASSERT(stack->top == -1);
	ASSERT(stack->no_of_elements == 5);
}
void test_create_stack_allocates_memory_for_five_float_elements(){
	int i;
	Stack* stack;
	int test_arr[] = {0,0,0,0,0};
	stack = create(sizeof(float),5);
	i=memcmp(test_arr,stack->elements,5);
	ASSERT(!i);
	ASSERT(stack->elementSize==sizeof(float));
	ASSERT(stack->top==-1);
	ASSERT(stack->no_of_elements==5);
}
void test_create_stack_allocates_memory_for_five_char_strings(){
	int i;
	Stack* stack;
	string test_arr[] = {0,0,0};
	stack = create(sizeof(string),3);
	i=memcmp(test_arr,stack->elements,3);
	ASSERT(!i);
	ASSERT(stack->elementSize==sizeof(string));
	ASSERT(stack->top==-1);
	ASSERT(stack->no_of_elements==3);
}

void test_push_int_element_at_top_of_stack(){
	int i;
	Stack* stack;
	int c=5;
	int test_arr[]={5,0,0,0,0};
	stack = create(sizeof(int),5);
	ASSERT(true == push(stack,&c));
	i=memcmp(test_arr,stack->elements,5);
	ASSERT(!i);
	ASSERT(stack->elementSize==sizeof(int));
	ASSERT(stack->top==0);
	ASSERT(stack->no_of_elements==5);
}
void test_push_float_element_at_top_of_stack(){
	float i;
	Stack* stack;
	float c=1.5;
	float test_arr[]={5.5,6.5,1.5,0,0};
	stack = create(sizeof(float),5);
	stack->top = 1;
	stack->elements = test_arr ;
	ASSERT(true == push(stack,&c));
	i=memcmp(test_arr,stack->elements,5);
	ASSERT(!i);
	ASSERT(stack->elementSize == sizeof(float));
	ASSERT(stack->top == 2);
	ASSERT(stack->no_of_elements == 5);
}
void test_push_string_element_at_top_of_stack(){
	int i;
	Stack* stack;
	string c = "hi";
	string test_arr[] = {"hi",0,0,0,0};
	stack = create(sizeof(string),5);
	stack->top = -1;
	ASSERT(true == push(stack,&c));
	i = memcmp(test_arr,stack->elements,5);
	ASSERT(!i);
	ASSERT(stack->elementSize == sizeof(string));
	ASSERT(stack->top == 0);
	ASSERT(stack->no_of_elements == 5);
}
void test_3_pop_float_element_at_top_of_stack(){
	int i;
	float element;
	Stack* stack;
	float test_arr[]={1.0,2.0,3.0,4.0,0};
	stack = create(sizeof(float),5);
	stack->elements = test_arr ;
	stack->top=3; 
	element = *(float*)pop(stack);
	i=memcmp(test_arr,stack->elements,5);
	ASSERT(!i);
	ASSERT((float)element == 4.0);
	ASSERT(stack->elementSize==sizeof(float));
	ASSERT(stack->top==2);
	ASSERT(stack->no_of_elements==5);
}

void test_3_pop_int_element_at_top_of_stack(){
	int i , element;
	Stack* stack;
	int test_arr[]={1,2,3,4,0};
	stack = create(sizeof(int),5);
	stack->elements = test_arr ;
	stack->top=3; 
	element = (int)pop(stack);
	i=memcmp(test_arr,stack->elements,5);
	ASSERT(!i);
	ASSERT(*(int*)element == 4);
	ASSERT(stack->elementSize==4);
	ASSERT(stack->top==2);
	ASSERT(stack->no_of_elements==5);
}
void test_3_pop_string_element_at_top_of_stack(){
	int i ;
	string element;
	Stack* stack;
	string test_arr[]={"hi","hello",0,0,0};
	stack = create(sizeof(string),5);
	stack->elements = test_arr ;
	stack->top=1; 
	strcpy(element ,pop(stack));
	i=memcmp(test_arr,stack->elements,5);
	ASSERT(!i);
	ASSERT(!strcmp("hello", element));
	ASSERT(stack->elementSize == sizeof(string) );
	ASSERT(stack->top == 0);
	ASSERT(stack->no_of_elements == 5);
}
void test_isFull_return_true_if_stack_is_full(){
	Stack* stack;
	int test_arr[]={1,2,3,4,0};
	stack = create(sizeof(int),5);
	stack->elements = test_arr ;
	stack->top=4; 
	ASSERT(true == isFull(stack));
}
void test_isFull_return_false_if_stack_is_not_full(){
	Stack* stack;
	int test_arr[]={1,2,3,0,0};
	stack = create(sizeof(int),5);
	stack->elements = test_arr ;
	stack->top=3; 
	ASSERT(false == isFull(stack));
}
void test_isEmpty_return_true_if_stack_is_empty(){
	Stack* stack;
	int test_arr[]={0,0,0,0,0};
	stack = create(sizeof(int),5);
	stack->elements = test_arr ;
	stack->top=-1; 
	ASSERT(true == isEmpty(stack));
}
void test_isEmpty_return_false_if_stack_is_not_empty(){
	Stack* stack;
	int test_arr[]={1,2,3,0,0};
	stack = create(sizeof(int),5);
	stack->elements = test_arr ;
	stack->top=2; 
	ASSERT(false == isEmpty(stack));
}