#include "testUtils.h"
#include "priorityQueue.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

void checkPriority(Queue* queue){
	Node* node;
	node = queue->head;
	while(node->next != NULL){
		ASSERT(node->priority <= node->next->priority);
		node = node->next;
	}
}
void test_create_queue(){
	Queue* queue = createQueue();
	ASSERT(queue->head == NULL);	 
	ASSERT(queue->length == 0);	 
}
void test_insert_integer_data_in_Start_of_queue(){
	Queue* queue = createQueue();
	int data = 10;
	int priority = 1;
	insertData(queue , &data , priority);
	ASSERT(queue->head->priority == 1);	 
	ASSERT(*(int*)queue->head->data == 10);	 
	ASSERT(queue->length == 1);	 
}
void test_insert_integer_data_in_queue1(){
	Queue* queue = createQueue();
	Node* node;
	int data1 = 10 , data2 = 20 , data3 = 30;

	insertData(queue , &data1 , 1);
	insertData(queue , &data2 , 3);
	insertData(queue , &data3 , 2);
	insertData(queue , &data3 , 1);

	checkPriority(queue);
	ASSERT(queue->length == 4);	 
}
void test_insert_float_data_in_queue1(){
	Queue* queue = createQueue();
	Node* node;
	float data1 = 10.5 , data2 = 20.5 , data3 = 30.5;

	insertData(queue , &data1 , 1);
	insertData(queue , &data2 , 5);
	insertData(queue , &data3 , 2);
	insertData(queue , &data3 , 3);

	checkPriority(queue);
	ASSERT(queue->length == 4);	 
}
void test_insert_string_data_in_queue1(){
	Queue* queue = createQueue();
	string data1 = "shital" , data2 = "shweta" , data3 = "shabarin";

	insertData(queue , &data1 , 1);
	insertData(queue , &data2 , 5);
	insertData(queue , &data3 , 2);
	insertData(queue , &data3 , 3);

	checkPriority(queue);
	ASSERT(queue->length == 4);	 
}
void test_delete_integer_data_in_queue1(){
	Queue* queue = createQueue();
	int removedData;
	int data1 = 10 , data2 = 20 , data3 = 30;

	insertData(queue , &data1 , 1);
	insertData(queue , &data2 , 3);
	insertData(queue , &data3 , 2);

	ASSERT(queue->length == 3);
	removedData =*(int*)deleteData(queue);
	ASSERT(queue->length == 2);
	ASSERT(removedData == 10);
}
void test_delete_float_data_in_queue1(){
	Queue* queue = createQueue();
	float deletedData;
	float data1 = 10.5 , data2 = 20.5 , data3 = 30.5;

	insertData(queue , &data1 , 1);
	insertData(queue , &data2 , 5);
	insertData(queue , &data3 , 2);
	insertData(queue , &data3 , 3);

	ASSERT(queue->length == 4);	 
	checkPriority(queue);
	deletedData  = *(float*)deleteData(queue);
	ASSERT(queue->length == 3);	 
	ASSERT(deletedData == 10.5);	 
}
void test_delete_string_data_in_queue(){
	Queue* queue = createQueue();
	string deletedData;
	string data1 = "shital" , data2 = "shweta" , data3 = "shabarin";

	insertData(queue , &data1 , 1);
	insertData(queue , &data2 , 5);
	insertData(queue , &data3 , 2);
	insertData(queue , &data3 , 3);

	ASSERT(queue->length == 4);	
	checkPriority(queue);
	strcpy(deletedData  , *(string*)deleteData(queue));
	ASSERT(!strcmp(deletedData , "shital"));
	ASSERT(queue->length == 3);	
}