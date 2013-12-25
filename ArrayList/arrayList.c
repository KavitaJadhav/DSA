#include "arrayList.h"
#include <stdlib.h>

ArrayList create(int capacity) {
	ArrayList list;
	list.base = (void*)malloc(sizeof(void*) * capacity);
	list.capacity = capacity;
	list.length = 0;
	return list;
}

void shiftElementsIfNeeded(ArrayList *list, int index) {
	int i;
	if (index < list->length) {
		for (i = list->length - 1; i >= index; i--) {
			list->base[i+1] = list->base[i];
		}
	}	
}

void shiftElementsAfterDelete(ArrayList *list, int index) {
	int i;
	if (index < list->length) {
		for (i = index; i <= list->length-1; i++) {
			list->base[i] = list->base[i+1];
		}
	}	
}
int isFull(ArrayList *list) {
	return list->length == list->capacity;
}

void increaseCapacity(ArrayList *list) {
	int targetCapacity;
	if (isFull(list)) {
		targetCapacity = list->capacity * 2;
		list->base = realloc(list->base, targetCapacity * sizeof(void*));
		list->capacity = targetCapacity;
	}	
}

int insert(ArrayList *list, int index, void* data) {
	if (list == NULL) return 0;
	if (index < 0 || index > list->length) return 0;
	increaseCapacity(list);
	shiftElementsIfNeeded(list, index);
	list->base[index] = data;
	list->length++;
	return 1;
}

int add(ArrayList *list, void* data){
	return insert(list, list->length, data);
}

void* remove(ArrayList *list, int index){
	void* removedElement;
	if (list == NULL) return NULL;
	if (index < 0 || index > list->length) return NULL;
	removedElement = list->base[index];
	shiftElementsAfterDelete(list , index);
	list->length--;
	return removedElement;
}

void* get(ArrayList *list, int index) {
	if (index < 0 || index >= list->length) return NULL;
	return list->base[index];
}

int search(ArrayList* list , void* element , Compare compare){
	int index;
	if (list->length == 0) return -1;
	for(index = 0 ; index < list->length ; index++)
		if(0 == compare (list->base[index] , element)) return index;
	return -1;
}

void dispose(ArrayList *list) {
	free(list->base);
}

int hasNextForArrayList(Iterator* it){
    ArrayList *list = it->list;
    if(list->length <= it->position) return 0;
    return 1;
}
void* getNextDataForArrayList(Iterator* it){
        ArrayList* list = it->list;
    if(!hasNextForArrayList(it)) return NULL;
    return list->base[it->position++];
}
Iterator getIterator(ArrayList* list){
    Iterator it;
    it.list = list;
    it.position = 0;
    it.hasNext = &hasNextForArrayList;
    it.next = &getNextDataForArrayList;
    return it;
}