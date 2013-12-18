#include <stdbool.h>

typedef char string[50];

typedef struct Process{
	struct Process* prev;
	struct Process* next;
	string name;
	int priority;
	int exTime;
	int remainTime;
	int cpuAttempt;
} Process;

typedef struct{
	Process* head;
	int time_slice;
	int length;
}ProcessQueue;

Process* createProcess(string name,int priority,int exTime);
ProcessQueue* createProcessQueue(int time_slice);
bool addProcess(ProcessQueue* pq , Process* p1);
ProcessQueue* executeProcess(ProcessQueue* pq);

