#include "testUtils.h"
#include "queue.h"
#include <stdlib.h>
#include <string.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed
typedef char string[50];

void test_dequeue_element_when_queue_is_empty(){
	Queue* queue = create(sizeof(char),5);
	ASSERT(!dequeue(queue));
	free(queue);
} 
void test_enqueue_char_element_at_rear_of_queue(){
	char c='A';
	Queue* queue = create(sizeof(char),5);
	enqueue(queue,&c);
	ASSERT('A'==*(char*)dequeue(queue));
	free(queue);
}
void test_enqueue_char_element_at_rear_of_queue_rear_is_at_middle(){
	char data[] = {'A','B','C','D'};
	Queue* queue = create(sizeof(char),6);
	enqueue(queue,&data[0]);
	enqueue(queue,&data[1]);
	enqueue(queue,&data[2]);

	ASSERT('A' == *(char*)dequeue(queue));
	ASSERT('B' == *(char*)dequeue(queue));
	ASSERT('C' == *(char*)dequeue(queue));
	free(queue);
}
void test_enqueue_char_element_return_false_when_queue_is_full(){
	char data[] = {'A','B','C','D'};
	Queue* queue = create(sizeof(char),3);
	enqueue(queue,&data[0]);
	enqueue(queue,&data[1]);
	enqueue(queue,&data[2]);
	ASSERT(!enqueue(queue,&data[3]));
	free(queue);
}
void test_enqueue_int_element_at_rear_of_queue(){
	int c=100 , element;
	Queue* queue = create(sizeof(int),5);
	ASSERT(enqueue(queue,&c));
	ASSERT(100 == *(int*)dequeue(queue));
	free(queue);
}
void test__enqueue_int_element_at_front_of_queue_when_rear_reach_to_end(){
	int data[] = {10,20,30,40};
	Queue* queue = create(sizeof(int),6);
	enqueue(queue,&data[0]);
	enqueue(queue,&data[1]);
	enqueue(queue,&data[2]);

	ASSERT( 10 == *(int*)dequeue(queue));
	enqueue(queue,&data[2]);
	free(queue);
}
void test_enqueue_float_element_at_rear_of_queue(){
	float c=1.5 ;
	Queue* queue = create(sizeof(float),5);
	ASSERT(enqueue(queue,&c));
	ASSERT(1.5 ==  *(float*)dequeue(queue));
	free(queue);
}
void test_enqueue_string_element_at_rear_of_queue(){
	string c = "hi";
	Queue* queue = create(sizeof(string),5);
	ASSERT(enqueue(queue,&c));
	ASSERT(!strcmp("hi" , *(string*) dequeue(queue)));
	free(queue);
}
void test_enqueue_int_element_at_rear_of_queue_rear_is_at_middle(){
	int data[] = {1,2,3,4,5};
	Queue* queue = create(sizeof(int),6);
	enqueue(queue,&data[0]);
	enqueue(queue,&data[1]);
	enqueue(queue,&data[2]);

	ASSERT(*(int*)dequeue(queue) == 1);
	ASSERT(*(int*)dequeue(queue) == 2);
	ASSERT(*(int*)dequeue(queue) == 3);
	free(queue);
}
void test_enqueue_float_element_at_rear_of_queue_rear_is_at_middle(){
	float data[] = {1.5f,2.5f,3.5f,4.5f,5.5f};
	float element;
	Queue* queue = create(sizeof(float),6);
	ASSERT(enqueue(queue,&data[0]));
	ASSERT(enqueue(queue,&data[1]));
	ASSERT(enqueue(queue,&data[2]));

	ASSERT(1.5f == *(float*)dequeue(queue));
	ASSERT(2.5f == *(float*)dequeue(queue));
	ASSERT(3.5f == *(float*)dequeue(queue));
	free(queue);
}
void test_enqueue_float_element_return_false_when_queue_is_full(){
	float data[] = {1.5f,2.5f,3.5f,4.5f};
	Queue* queue = create(sizeof(float),3);
	enqueue(queue,&data[0]);
	enqueue(queue,&data[1]);
	enqueue(queue,&data[2]);
	ASSERT(!enqueue(queue,&data[3]));
	free(queue);
}
void test_enqueue_string_element_at_rear_of_queue_rear_is_at_middle(){
	string data[] = {"AAA","BBB","CCC","DDD","EEE"};
	Queue* queue = create(sizeof(string),6);
	enqueue(queue,&data[0]);
	enqueue(queue,&data[1]);
	enqueue(queue,&data[2]);

	ASSERT(!strcmp(*(string*)dequeue(queue) , "AAA"));
	ASSERT(!strcmp(*(string*)dequeue(queue) , "BBB"));
	ASSERT(!strcmp(*(string*)dequeue(queue) , "CCC"));
	free(queue);
}
