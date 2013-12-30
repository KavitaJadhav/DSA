#include "../doubly-linked-list/doublyLinkList.h"

typedef int (*CompareFunc)(void* element1,void* element2);
typedef int (*HashFunc)(void* key , int capacity);

typedef struct HashMap{
	void** buckets;
	CompareFunc compare;
	HashFunc hashFunc;
	int noOfBuckets ;
}HashMap;

typedef struct HashElement{
	void* value;
	void* key;
}HashElement;

HashMap* create(HashFunc hashFunc, CompareFunc compare);
int put(HashMap *map, void *key, void *value);
void* get(HashMap *map, void *key);
int remove(HashMap *map, void *key);
int searchByKey(HashMap* map , void* key);
Iterator keys(HashMap *map);
void dispose(HashMap *map);