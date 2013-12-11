#include "cpuSheduling.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

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
	pq->rear = 0;
	return pq;
}
ProcessQueue* addProcess(ProcessQueue* pq , Process* p1){
	int i = 0;
	Process* temp = calloc(1,sizeof(Process));
	pq->runningProcesses[pq->rear] = p1;
	printf("%d\n",pq->rear );
	pq->rear++;
	return pq;	
}
ProcessQueue* scheduleProcesses(ProcessQueue* pq){
	int i;
	int procRemainTime ;
	for(i = 0 ;i <= pq->rear ; i++){
		procRemainTime = (pq->runningProcesses[i])->remainTime;
		
		if(procRemainTime > 0 && procRemainTime < pq->time_slice)
			procRemainTime = 0;
		else 
			procRemainTime -= pq->time_slice; 
	}
	return pq;
}
