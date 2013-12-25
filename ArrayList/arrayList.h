#include "../iterator/iterator.h"

typedef struct {
	void** base;
	int capacity;
	int length;
} ArrayList;

ArrayList create(int capacity);

int insert(ArrayList *list, int index, void* data);

typedef int(*Compare)(void* element1 , void* element);
int search(ArrayList *list, void* element, Compare compare);

void* remove(ArrayList *list, int index );

int add(ArrayList *list, void* data);

void* get(ArrayList *list, int index);

void dispose(ArrayList *list);

Iterator getIterator(ArrayList* list);
void* getNextDataForArrayList(Iterator* it);
int hasNextForArrayList(Iterator* it);