#include "cpuSheduling.h"
#include <string.h>
#include <stdlib.h>

Process* createProcess(string name,int priority,int exTime){
	Process* p1 = calloc(1,sizeof(Process));
	strcpy(p1->name , name);
	p1->priority = priority ;
	p1->exTime = exTime;
	p1->remainTime = exTime;
	p1->cpuAttempt = 0;
	return p1;
}
ProcessQueue* createProcessQueue(int time_slice){
	ProcessQueue* pq = calloc(1,sizeof(ProcessQueue));
	pq->time_slice = time_slice;
	pq->head = NULL;
	pq->length = 0;
	return pq;
}
void addFirst(ProcessQueue* pq ,Process* p1){
	pq->head = p1;
	p1->next = pq->head;
	p1->prev = pq->head;
}
void addByPriority(ProcessQueue* pq ,Process* p1){
	Process* temp ;
	temp = pq->head;
	while(p1->priority >= temp->priority && temp->next != pq->head)
		temp =temp->next;
	if(temp->priority > p1->priority){
		p1->next = temp;
		p1->prev = temp->prev;
		temp->prev->next = p1;
		temp->prev = p1;
	}
	else{
		p1->prev=temp;
		p1->next = temp->next;
		temp->next->prev = p1;
		temp->next = p1;
	}
}
bool addProcess(ProcessQueue* pq , Process* p1){
	if (pq->length == 0) addFirst(pq , p1);
	else addByPriority(pq , p1);
	pq->length++;
	return 1;
}
ProcessQueue* executeProcess(ProcessQueue* pq){
	Process* temp = pq->head;
	while(pq->length > 0)
	{	
		if(temp->remainTime > pq->time_slice )
			temp->remainTime = temp->remainTime - pq->time_slice;
		else{
			temp->remainTime = 0;
			temp->next->prev = temp->prev;
			temp->prev->next = temp->next;
			pq->length--;
		}
		temp->cpuAttempt ++;
		temp = temp->next;
	}
	return pq;
}
