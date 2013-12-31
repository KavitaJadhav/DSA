#include "doublyLinkList.h"
#include <stdlib.h>
#include <string.h>

List* createList(){
	List* list =calloc(1, sizeof(List));
	list->header = NULL;
	list->length = 0;
	return list; 
}
void insertFirst(List* list , int index ,Node* node ){
	node->next = list->header;
	list->header = node;
	node->prev = NULL;
}
void insertLast(List* list , int index ,Node* node ){
	Node* temp = calloc(1, sizeof(Node*));
	temp = list->header;
	if(temp ==NULL) return;
	while(NULL!=temp->next)
		temp =temp->next;
	node->prev=temp;
	temp->next =node;
	node->next = NULL;
}
void insertMiddle(List* list , int index ,Node* node ){
	Node* temp;
	int i=0;
	temp = list->header;
	while(i++ < index-1) temp =temp->next ;
	node->prev=temp;
	node->next=temp->next;
	temp->next =node;
	(node->next)->prev =node;
}
bool insertNode(List* list , int index , void* data){
	Node* node = calloc(1,sizeof(node));
	if (index > list->length) return false;
	
	if (index == 0)	insertFirst(list, index, node);
	else if(index == list->length)	insertLast(list, index,node);
	else insertMiddle(list, index, node);
	
	node->data = data;
	list->length++;
	return true;
};

void deleteFirst(List* list){
	Node* node = list->header;
	if(list->length == 1) list->header = NULL;
	else {
		list->header = list->header->next;
		list->header->prev = NULL;
	}
	free(node);
}
void deleteLast(List* list){
	Node* temp = list->header;
	while(NULL!=temp->next)
		temp =temp->next;
	temp->prev->next = NULL;
	free(temp);
}
void deleteMiddle(List* list , int index){
	Node* temp;
	int i=0;
	temp = list->header;
	while(i++ < index) temp =temp->next ;
	temp->prev->next = temp->next;
	temp->next->prev = temp->prev;
	free(temp);
}
bool deleteNode(List* list , int index){
	if(index >= list->length || index < 0) return false;
	if(index == 0) deleteFirst(list);
	else if(index == list->length-1)  deleteLast(list);
	else deleteMiddle( list , index);
	list->length--;
	return true;
}
void* getElement(List* list , int index){
	int i=0;
	void* data;
	Node* node;
	if(index >= list->length) return NULL;
	else{
		node = list->header;
		while(i++ < index) node = node->next ;
	}
	return node->data;
}
int search(List* list , void* element , Compare compare){
	Node* node;
	int index= 0;
	if(0 == list->length) return -1;
	node = list->header;
	if(node==NULL) return -1;
	while(node->next != NULL){
		if (!compare(element , node->data)) return index;
		index++;
		node = node->next;
	}
	return -1;
}

int hasNext(Iterator* it){
	List* list = (List*)it->list;
	if(it->position >= list->length) return 0;
	return 1;
}
void* next(Iterator *it){
	List *list;
	int i = 0;
	Node* temp;
	if(0 == hasNext(it)) return NULL;
	list = (List*)it->list;
	temp = list->header;
	for(i = 0;i < it->position;i++)
	        temp = temp->next;
	it->position++;
	return temp->data;
}
Iterator getIterator(List *list){
        Iterator iterator;
        iterator.position = 0;
        iterator.list = list;
        iterator.hasNext = &hasNext;
        iterator.next = &next;
        return iterator;
}