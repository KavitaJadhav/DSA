#include "hashmap.h"
#include <stdlib.h>

const int capasity = 10;
HashMap* create(HashFunc hashFunc, CompareFunc compare){
	HashMap* map = calloc(1, sizeof(HashMap));
	map->buckets = calloc(capasity, sizeof(List));
	map->noOfBuckets = capasity;
	map->hashFunc = hashFunc;
	map->compare = compare;
	return map;
}
Node* createNode(void* data){
	Node* node = calloc(1, sizeof(Node));
	node->next = NULL;
	node->prev = NULL;
	node->data = data;
	return node;
}
Data* getData(void *key, void *value){
	Data* data = calloc(1, sizeof(Data));
	data->key =key;
	data->value = value;
	return data;
}
List* getBucket(HashMap* map , int bucketNumber){
	return (List*)(map->buckets+(sizeof(List)*bucketNumber));
}
int put(HashMap *map, void *key, void *value){
	Data* data = getData(key, value);
	Node* node = createNode(data);
    int bucketNumber = map->hashFunc(key) % capasity;
    List* list = getBucket(map , bucketNumber);
	return insertNode(list, list->length,data);
}
void dispose(HashMap *map){
	free(map->buckets);
	free(map);
}

int searchData(HashMap* map , void* key){
    int bucketNumber = map->hashFunc(key) % capasity;
    List* list = getBucket(map , bucketNumber);
	return search(list, key,map->compare);
}
void* get(HashMap *map, void *key){
	Node* node;
	Data* data;
	int bucketNumber = map->hashFunc(key) % capasity;
	List* list = getBucket(map , bucketNumber);
	if(0 == list->length) return NULL;
	node = list->header;
	do{
		data = node->data;
		if (!map->compare(key ,data->key)) return data;
		node = node->next;
	}while(node->next != NULL);
	return NULL;
}
int getIndexInBucket(HashMap* map ,void* key ,List* list){
	Data* data;
	int index = 1 ;
	Node* node = list->header;
	do{
		data = node->data;
		if (!map->compare(key ,data->key)) return index;
		node = node->next;
		index++;
	}while(node->next != NULL);
	return index;
}

void* remove(HashMap *map, void *key){
	void* data = get(map, key);
	int index ,bucketNumber = map->hashFunc(key) % capasity;
	List* list = getBucket(map , bucketNumber);
	index = getIndexInBucket( map ,key ,list);
	deleteNode(list,index);
	return data;
}