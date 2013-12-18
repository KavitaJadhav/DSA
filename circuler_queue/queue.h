typedef struct{
	void* elements;
	int elementSize;
	int front;
	int rear;
	int no_of_elements;
}Queue;

Queue* create(int elementSize, int no_of_elements);
int enqueue(Queue* queue,void* element);
void* dequeue(Queue* queue);

