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
Node* createNode(void* hashElement){
	Node* node = calloc(1, sizeof(Node));
	node->next = NULL;
	node->prev = NULL;
	node->data = hashElement;
	return node;
}
HashElement * gethashElement(void *key, void *value){
	HashElement * hashElement = calloc(1, sizeof(hashElement));
	hashElement->key =key;
	hashElement->value = value;
	return hashElement;
}
List* getBucket(HashMap* map , int bucketNumber){
	return (List*)(map->buckets+(sizeof(List)*bucketNumber));
}
int put(HashMap *map, void *key, void *value){
	HashElement * hashElement = gethashElement(key, value);
	Node* node = createNode(hashElement);
    int bucketNumber = map->hashFunc(key) % capasity;
    List* list = getBucket(map , bucketNumber);
	return insertNode(list, list->length,hashElement);
}
void dispose(HashMap *map){
	free(map->buckets);
	free(map);
}

int searchByKey(HashMap* map , void* key){
    int bucketNumber = map->hashFunc(key) % capasity;
    List* list = getBucket(map , bucketNumber);
	return search(list, key,map->compare);
}
void* get(HashMap *map, void *key){
	Node* node;
	HashElement* hashElement;
	int bucketNumber = map->hashFunc(key) % capasity;
	List* list = getBucket(map , bucketNumber);
	node = list->header;
	while(node != NULL){
		hashElement = node->data;
		if (!map->compare(key ,hashElement->key)) return hashElement;
		node = node->next;
	};
	return NULL;
}
int getIndexInBucket(HashMap* map ,void* key ,List* list){
	HashElement * hashElement;
	int index = 0 ;
	Node* node = list->header;
	while(node != NULL){
		hashElement = node->data;
		if (!map->compare(key ,hashElement->key)) return index;
		node = node->next;
		index++;
	};
	return -1;
}
int remove(HashMap *map, void *key){
	int bucketNumber = map->hashFunc(key) % capasity;
	List* list = getBucket(map , bucketNumber);
	int index  = getIndexInBucket( map ,key ,list);
	return deleteNode(list,index);
}
Iterator keys(HashMap *map){
	List* list = createList();
	List* bucket;
	HashElement* hashElement;
	Iterator it;
	int i;
	for(i = 0 ; i < capasity ; i++){
		bucket =  (List*)(map->buckets+(sizeof(List)*i));
		it = getIterator(bucket);
		
		while(it.hasNext(&it)){
			hashElement = (HashElement*) it.next(&it);
			printf("%d %d %d\n",list->length,it.position,*(int*)hashElement->key);
			insertNode(list, list->length, hashElement);
		}
	}
	it = getIterator(list);
	return it;
}

