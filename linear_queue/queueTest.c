#include "testUtils.h" 
#include "queue.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

// Queue* queue;
// void tearDown(){
// 	free(queue->elements);
// 	free(queue);
// };

void test_create_queue_allocates_memory_for_five_char_elements(){
	int i;
	Queue* queue;
	int test_arr[] = {0,0,0,0,0};
	queue = create(sizeof(char),5);
	i=memcmp(test_arr,queue->elements,5);
	ASSERT(!i);
	ASSERT(queue->elementSize == sizeof(char));
	ASSERT(queue->rear == -1);
	ASSERT(queue->no_of_elements == 5);
}
void test_create_queue_allocates_memory_for_five_int_elements(){
	int i;
	Queue* queue;
	int test_arr[] = {0,0,0,0,0};
	queue = create(sizeof(int),5);
	i=memcmp(test_arr,queue->elements,5);
	ASSERT(!i);
	ASSERT(queue->elementSize == 4);
	ASSERT(queue->rear == -1);
	ASSERT(queue->no_of_elements == 5);
}
void test_create_queue_allocates_memory_for_five_float_elements(){
	int i;
	Queue* queue;
	int test_arr[] = {0,0,0,0,0};
	queue = create(sizeof(float),5);
	i=memcmp(test_arr,queue->elements,5);
	ASSERT(!i);
	ASSERT(queue->elementSize==sizeof(float));
	ASSERT(queue->rear==-1);
	ASSERT(queue->no_of_elements==5);
	free(queue);
}
void test_create_queue_allocates_memory_for_five_char_strings(){
	int i;
	Queue* queue;
	string test_arr[] = {0,0,0};
	queue = create(sizeof(string),3);
	i=memcmp(test_arr,queue->elements,3);
	ASSERT(!i);
	ASSERT(queue->elementSize==sizeof(string));
	ASSERT(queue->rear==-1);
	ASSERT(queue->no_of_elements==3);
	free(queue);
}
void test_enqueue_char_element_at_rear_of_queue(){
	Queue* queue;
	int c='a';
	queue = create(sizeof(char),5);
	ASSERT(enqueue(queue,&c));
	ASSERT(*(char*)(queue->elements)=='a');
	ASSERT(queue->rear==0);
	ASSERT(queue->no_of_elements==5);
	free(queue);
}
void test_enqueue_int_element_at_rear_of_queue(){
	Queue* queue;
	int c=5;
	queue = create(sizeof(int),5);
	ASSERT(enqueue(queue,&c));
	ASSERT(*(int*)(queue->elements)==5);
	ASSERT(queue->rear==0);
	ASSERT(queue->no_of_elements==5);
	free(queue);
}
void test_enqueue_float_element_at_rear_of_queue(){
	Queue* queue;
	float c=1.5;
	queue = create(sizeof(float),5);
	queue->rear = 1;
	ASSERT(enqueue(queue,&c));
	ASSERT(queue->rear == 2);
	ASSERT(queue->no_of_elements == 5);
	ASSERT(*(float*)(queue->elements+queue->rear*queue->elementSize)==1.5);
	free(queue);
}
void test_enqueue_string_element_at_rear_of_queue(){
	Queue* queue;
	string c = "hi";
	queue = create(sizeof(string),5);
	ASSERT(enqueue(queue,&c));
	ASSERT(!strcmp("hi", *(string*)queue->elements));
	ASSERT(queue->rear == 0);
	ASSERT(queue->no_of_elements == 5);
	free(queue);
}
void test_33_dequeue_char_element_at_rear_of_queue(){
		int i;
		char* element;
		Queue* queue;
		char test_arr1[] = {'b','c','d','d',0};
		char test_arr[]={'a','b','c','d',0};
		queue = create(sizeof(char),5);
		queue->elements = test_arr ;
		queue->rear=3; 
		element = dequeue(queue);
		i=memcmp(test_arr1,queue->elements,5*sizeof(char));
		ASSERT(!i);
		ASSERT(*element == 'a');
		ASSERT(queue->elementSize==sizeof(char));
		ASSERT(queue->rear==2);
		free(queue);
}
void test_33_dequeue_int_element_at_rear_of_queue(){
		int i , element;
		Queue* queue;
		int test_arr1[] = {2,3,4,4,0};
		int test_arr[]={1,2,3,4,0};
		queue = create(sizeof(int),5);
		queue->elements = test_arr ;
		queue->rear=3; 
		element = (int)dequeue(queue);
		i=memcmp(test_arr1,queue->elements,5);
		ASSERT(!i);
		ASSERT(*(int*)element == 1);
		ASSERT(queue->elementSize==4);
		ASSERT(queue->rear==2);
		free(queue);
}
void test_3_dequeue_float_element_at_rear_of_queue(){
	int i;
	void* element;
	Queue* queue;
	float test_arr[]={1.0,2.0,3.0,4.0,0};
	float test_arr1[]={2.0,3.0,4.0,4.0,0};
	queue = create(sizeof(float),5);
	queue->elements = test_arr ;
	queue->rear=3; 
	element = dequeue(queue);
	i=memcmp(test_arr1,queue->elements,5);
	ASSERT(!i);
	ASSERT(*(float*)element == 1.0);
	ASSERT(queue->rear==2);
}
void test_3_dequeue_string_element_at_start_of_queue(){
	void* element;
	int i;
	Queue* queue;
	string* data;
	queue = create(sizeof(string),4);
	data = (string*)queue->elements;
	strcpy(data[0],"hi");
	strcpy(data[1],"hw");
	strcpy(data[2],"r");
	strcpy(data[3],"u");
	queue->rear=3; 
	element = dequeue(queue);
	ASSERT(!strcmp("hw",queue->elements));
	i=strcmp("hi",*(string*)element);
	ASSERT(!i);
	ASSERT(queue->rear==2);
};
void test_isFull_return_true_if_queue_is_full(){
	Queue* queue;
	int test_arr[]={1,2,3,4,0};
	queue = create(sizeof(int),5);
	queue->elements = test_arr ;
	queue->rear=4; 
	ASSERT(true == isFull(queue));
	free(queue);
}
void test_isFull_return_false_if_queue_is_not_full(){
	Queue* queue;
	int test_arr[]={1,2,3,0,0};
	queue = create(sizeof(int),5);
	queue->elements = test_arr ;
	queue->rear=3; 
	ASSERT(false == isFull(queue));
	free(queue);
}
void test_isEmpty_return_true_if_queue_is_empty(){
	Queue* queue;
	int test_arr[]={0,0,0,0,0};
	queue = create(sizeof(int),5);
	queue->elements = test_arr ;
	queue->rear=-1; 
	ASSERT(true == isEmpty(queue));
	free(queue);
}
void test_isEmpty_return_false_if_queue_is_not_empty(){
	Queue* queue;
	int test_arr[]={1,2,3,0,0};
	queue = create(sizeof(int),5);
	queue->elements = test_arr ;
	queue->rear=2; 
	ASSERT(false == isEmpty(queue));
	free(queue);
}