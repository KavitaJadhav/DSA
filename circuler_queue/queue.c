#include "customTypes.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

Queue* create(int elementSize, int no_of_elements){
	Queue* queue = calloc(1,sizeof(Queue));
	queue->front=-1;
	queue->rear=-1;
	queue->elements= calloc(no_of_elements,elementSize);
	queue->no_of_elements=no_of_elements;
	queue->elementSize=elementSize;
	return queue;
}
int enqueue(Queue* queue,void* element)
{
	if(isFull(queue)) return 0;
	queue->rear++;
	memcpy((queue->elements+(queue->elementSize*queue->rear)) , element,queue->elementSize);
	return 1;
}
void* dequeue(Queue* queue){
	void* element = malloc(queue->elementSize);
	if(isEmpty(queue)) return 0;
	queue->front++;
	memmove(element, queue->elements+(queue->elementSize*queue->front), queue->elementSize);
	return element;
}
int isFull(Queue* queue){ 

	if(queue->front == -1 && queue->rear == queue->no_of_elements-1) return 1;
	if((queue->rear == queue->no_of_elements-1)  && (queue->front > 0)) queue->rear = -1;
	return (queue->front == queue->rear+1);
}
int isEmpty(Queue* queue){
	if(queue->front ==-1 && queue->rear == -1) return 1;
	return (queue->front == queue->rear+1);
}
