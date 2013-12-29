#include "../doubly-linked-list/doublyLinkList.h"
typedef int (*CompareFunc)(void* element1,void* element2);
typedef int (*HashFunc)(void* key);

typedef struct HashMap{
	void** buckets;
	CompareFunc compare;
	HashFunc hashFunc;
	int noOfBuckets ;
}HashMap;

typedef struct Data{
	void* value;
	void* key;
}Data;

HashMap* create(HashFunc hashFunc, CompareFunc compare);
int put(HashMap *map, void *key, void *value);
void* get(HashMap *map, void *key);
int remove(HashMap *map, void *key);
int searchData(HashMap* map , void* key);
// void* keys(HashMap *map) ;
void dispose(HashMap *map);