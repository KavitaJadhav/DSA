#include "priorityQueue.h"
#include <stdio.h>
#include <stdlib.h>

Queue* createQueue(){
	Queue* queue = calloc(1,sizeof(Queue));
	queue->head = NULL;
	queue->length = 0;
	return queue;
}
void insertFirst(Queue* queue ,Node* node ){
	node->next = NULL;
	queue->head = node;
	node->prev = NULL;
}
void insertbyPriority(Queue* queue ,Node* node ){
	Node* temp ;
	temp = queue->head;
	while(node->priority >= temp->priority && temp->next!=NULL)
		temp =temp->next;
	if(temp->priority > node->priority){
		node->next = temp;
		node->prev = temp->prev;
		temp->prev->next = node;
		temp->prev = node;
	}
	else{
		node->prev=temp;
		node->next = temp->next;
		if(temp->next != NULL) temp->next->prev = node;
		temp->next = node;
	}
}
int insertData( Queue* queue , void* data , int priority){
	int i=0;
	Node* node = calloc(1,sizeof(Node));
	node->data = data;
	node->priority = priority;
	if (queue->length == 0)	insertFirst(queue, node);
	else insertbyPriority(queue,node);
	queue->length++;
	return 1;
}
void* deleteData( Queue* queue){
	Node* node;
	if(queue->head == NULL) return NULL;
	node = queue->head;
	queue->head = node->next;
	queue->length--;
	return node->data;
}