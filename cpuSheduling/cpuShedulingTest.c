#include "testUtils.h"
#include "cpuSheduling.h"
#include <string.h>
#include <stdio.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed
void checkPriority(ProcessQueue* pq){
	Process* p1;
	p1 = pq->head;
	while(p1->next != pq->head){
		ASSERT(p1->priority <= p1->next->priority);
		p1 = p1->next;
	}
}

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

	ASSERT(0 == pq->length);
	ASSERT(!pq->head);
	ASSERT(50 == pq->time_slice);
}
void test_add_new_process_in_processQueue(){
	ProcessQueue* pq = createProcessQueue(50);
	Process* p1 = createProcess("Browser",1,100);
	Process* p2 = createProcess("Calculater",3,200);
	Process* p3 = createProcess("Sublime",2,150);

	addProcess(pq , p1);
	addProcess(pq , p2);
	addProcess(pq , p3);

	ASSERT(3 == pq->length);
	checkPriority(pq);
	ASSERT(50 == pq->time_slice);
}
void test_scheduleQueue_shedules_process_in_processQueue(){
	ProcessQueue* pq = createProcessQueue(50);

	Process* p1 = createProcess("Browser",1,100);
	Process* p2 = createProcess("Calculater",3,200);
	Process* p3 = createProcess("Sublime",2,150);
	Process* p4 = createProcess("gitBash",1,160);

	addProcess(pq , p1);
	addProcess(pq , p2);
	addProcess(pq , p3);
	addProcess(pq , p4);

	checkPriority(pq);
	ASSERT(4 == pq->length);
	pq = scheduleProcesses(pq);
	ASSERT(0 == pq->length);

	ASSERT(p1->cpuAttempt == 2);
	ASSERT(p2->cpuAttempt == 4);
	ASSERT(p3->cpuAttempt == 3);
	ASSERT(p4->cpuAttempt == 4);
}