#include "testUtils.h"
#include "priorityQueue.h"
#include <stdlib.h>
#include <stdio.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

// void test_create_queue(){
// 	Queue* queue = createQueue();
// 	ASSERT(queue->head == NULL);	 
// 	ASSERT(queue->length == 0);	 
// }
// void test_insert_data_in_queue(){
// 	Queue* queue = createQueue();
// 	int data = 10;
// 	int priority = 1;
// 	insertData(queue , &data , priority);
// 	ASSERT(queue->head->priority == 1);	 
// 	ASSERT(*(int*)queue->head->data == 10);	 
// 	ASSERT(queue->head != NULL);	 
// 	ASSERT(queue->length == 1);	 
// }

void test_insert_data_in_queue1(){
	Queue* queue = createQueue();
	int data1 = 10 , data2 = 20 , data3 = 30;
	int priority1 = 1 , priority2 =3 ,priority3 =2;
	insertData(queue , &data1 , priority1);
	insertData(queue , &data2 , priority2);
	insertData(queue , &data3 , priority3);
	ASSERT(queue->length == 3);	 
}
void test_delete_data_in_queue1(){
	Queue* queue = createQueue();
	int removedData;
	int data1 = 10 , data2 = 20 , data3 = 30;
	int priority1 = 1 , priority2 =3 ,priority3 =2;
	insertData(queue , &data1 , priority1);
	insertData(queue , &data2 , priority2);
	insertData(queue , &data3 , priority3);
	ASSERT(queue->length == 3);
	removedData = deleteData(queue);


}