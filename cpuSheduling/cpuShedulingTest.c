#include "testUtils.h"
#include "cpuSheduling.h"
#include <string.h>
#include <stdio.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

void test_create_process_return_new_process(){
	Process* p1;
	p1 = createProcess("Browser",1,100);
	ASSERT(1 == p1->priority);
	ASSERT(100 == p1->exTime);
	ASSERT(100 == p1->remainTime);
	ASSERT(0 == p1->cpuAttempt);
	ASSERT(!strcmp("Browser" , p1->name));
}
void test_create_processQueue_return_new_processQueue(){
	ProcessQueue* pq;
	pq = createProcessQueue(50);
	ASSERT(0 == pq->rear);
	ASSERT(50 == pq->time_slice);
}
void test_add_new_process_in_processQueue(){
	ProcessQueue* pq = createProcessQueue(50);
	Process* p1 = createProcess("Browser",1,100);
	Process* p2 = createProcess("Calculater",2,200);
	pq = addProcess(pq , p1);
	pq = addProcess(pq , p2);
	ASSERT(2 == pq->rear);
	ASSERT(pq->runningProcesses[0] == p1);
	ASSERT(pq->runningProcesses[1] == p2);
	ASSERT(50 == pq->time_slice);
}