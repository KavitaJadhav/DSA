#include <stdbool.h>

typedef char string[50];

typedef struct{
	string name;
	int priority;
	int exTime;
	int remainTime;
	int cpuAttempt;
}Process;

typedef struct{
	Process* runningProcesses[10];
	int time_slice;
	int rear;
}ProcessQueue;

Process* createProcess(string name,int priority,int exTime);
ProcessQueue* createProcessQueue(int time_slice);
ProcessQueue* addProcess(ProcessQueue* pq , Process* p1);
ProcessQueue* scheduleProcesses(ProcessQueue* pq);

