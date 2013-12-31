#include "hashmap.h"
#include <stdlib.h>

const int capacity = 10;

HashMap* create(HashFunc hashFunc, CompareFunc compare){
	int i;
	HashMap* map = calloc(1, sizeof(HashMap));
	map->buckets = calloc(capacity, sizeof(List));
	for(i=0;i<capacity;i++) 	map->buckets[i] = createList();
	map->noOfBuckets = capacity;
	map->hashFunc = hashFunc;
	map->compare = compare;
	return map;
};

HashElement* gethashElement(void *key, void *value){
	HashElement* hashElement = calloc(1, sizeof(hashElement));
	hashElement->key =key;
	hashElement->value = value;
	return hashElement;
}
List* getBucket(HashMap* map , int bucketNumber){
	return (List*)(map->buckets[bucketNumber]);
}

int put(HashMap *map, void *key, void *value){
    int bucketNumber = map->hashFunc(key , capacity) ;    
    List* list = getBucket(map , bucketNumber);
	return insertNode(list, list->length,gethashElement(key, value));
}
void dispose(HashMap *map){
	free(map->buckets);
	free(map);
}
int searchByKey(HashMap* map , void* key){
    int bucketNumber = map->hashFunc(key , capacity) ;
    List* list = getBucket(map , bucketNumber);
	return search(list, key,map->compare);
}

void* get(HashMap *map, void *key){
	int bucketNumber = map->hashFunc(key , capacity) ;
	List* list = getBucket(map , bucketNumber);
	HashElement* hashElement;
	Node* node = list->header;
	while(node != NULL){
		hashElement = node->data;
		if (!map->compare(key ,hashElement->key)) return hashElement;
		node = node->next;
	};
	return NULL;
}
int getIndexInBucket(HashMap* map ,void* key ,List* list){
	HashElement* hashElement;
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
	int bucketNumber = map->hashFunc(key , capacity) ;
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
	for(i = 0 ; i < capacity ; i++){
		bucket = (List*)map->buckets[i];
		if(bucket->header != NULL){
			it = getIterator(bucket);
			while(it.hasNext(&it)){
				hashElement = (HashElement*) it.next(&it);
				insertNode(list, list->length, hashElement->key);
			}
		}
	}
	it = getIterator(list);
	return it;
}

void rehash(HashMap *map){
	List* list = createList();
	List* bucket;
	HashElement* hashElement;
	Iterator it;
	int i;
	for(i = 0 ; i < capacity ; i++){
		bucket = (List*)map->buckets[i];
		if(bucket->header != NULL){
			it = getIterator(bucket);
			while(it.hasNext(&it)){
				hashElement = (HashElement*) it.next(&it);
				insertNode(list, list->length, hashElement->key);
			}
		}
	}
	// it = getIterator(list);
	// return it;
}


