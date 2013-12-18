#include "testUtils.h" 
#include "queue.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void test_enqueue_char_element_at_rear_of_queue(){
	char c='a';
	Queue* queue = create(sizeof(char),5);
	enqueue(queue,&c);
	ASSERT('a' == *(char*)dequeue(queue));
	free(queue);
}
void test_enqueue_int_element_at_rear_of_queue(){
	int c=5;
	Queue* queue = create(sizeof(int),5);
	enqueue(queue,&c);
	ASSERT(5 == *(int*)dequeue(queue));
	free(queue);
}
void test_enqueue_float_element_at_rear_of_queue(){
	float c=1.5f ;
	Queue* queue = create(sizeof(float),5);
	enqueue(queue,&c);
	ASSERT(1.5f == *(float*)dequeue(queue));
	free(queue);
}
void test_enqueue_string_element_at_rear_of_queue(){
	string c = "hi";
	Queue* queue = create(sizeof(float),5);
	enqueue(queue,&c);
	ASSERT(!strcmp(*(string*)dequeue(queue) , "hi"));
	free(queue);
}
void test_dequeue_char_element_at_front_of_queue(){
		char data[] = {'b','c','d','d'};
		char element;
		Queue* queue = create(sizeof(char),5);;
		
		enqueue(queue,&data[0]);
		enqueue(queue,&data[1]);
		enqueue(queue,&data[2]);
		enqueue(queue,&data[3]);
		
		ASSERT('b' == *(char*)dequeue(queue));
		ASSERT('c' == *(char*)dequeue(queue));
		free(queue);
}
void test_33_dequeue_int_element_at_rear_of_queue(){
	int data[] = {10,20,30,400};
		Queue* queue = create(sizeof(int),5);;
		
		enqueue(queue,&data[0]);
		enqueue(queue,&data[1]);
		enqueue(queue,&data[2]);
		enqueue(queue,&data[3]);

		ASSERT(10 == *(int*)dequeue(queue));
		ASSERT(20 == *(int*)dequeue(queue));
		free(queue);
}
void test_3_dequeue_float_element_at_rear_of_queue(){
		float data[] = {1.0f,2.0f,3.0f,4.0f,0};
		Queue* queue = create(sizeof(float),5);;
		
		enqueue(queue,&data[0]);
		enqueue(queue,&data[1]);
		enqueue(queue,&data[2]);
		enqueue(queue,&data[3]);
		
		ASSERT(1.0f == *(float*)dequeue(queue));
		ASSERT(2.0f == *(float*)dequeue(queue));
		free(queue);
}
void test_3_dequeue_string_element_at_start_of_queue(){
		string data[] = {"hi","how","are","you","today"};
		Queue* queue = create(sizeof(string),5);;
		
		enqueue(queue,&data[0]);
		enqueue(queue,&data[1]);
		enqueue(queue,&data[2]);
		enqueue(queue,&data[3]);
		
		ASSERT(!strcmp("hi" , *(string*)dequeue(queue)));
		ASSERT(!strcmp("how" , *(string*)dequeue(queue)));
		free(queue);
}
void test_isFull_return_true_if_queue_is_full(){
	string data[] = {"hi","how","are","you","today"};
	Queue* queue = create(sizeof(string),4);;
	
	enqueue(queue,&data[0]);
	enqueue(queue,&data[1]);
	enqueue(queue,&data[2]);
	enqueue(queue,&data[3]);

	ASSERT(true == isFull(queue));
	free(queue);
}
void test_isFull_return_false_if_queue_is_not_full(){
	string data[] = {"hi","how","are","you","today"};
	Queue* queue = create(sizeof(string),4);;
	
	enqueue(queue,&data[0]);
	enqueue(queue,&data[1]);
	enqueue(queue,&data[2]);
	
	ASSERT(false == isFull(queue));
	free(queue);
}
void test_isEmpty_return_true_if_queue_is_empty(){
	Queue* queue = create(sizeof(int),5);
	ASSERT(true == isEmpty(queue));
	free(queue);
}
void test_isEmpty_return_false_if_queue_is_not_empty(){
	int data = 10;
	Queue* queue = create(sizeof(int),5);
	enqueue(queue,&data);
	ASSERT(false == isEmpty(queue));
	free(queue);
}