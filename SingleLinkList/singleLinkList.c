#include "singleLinkList.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

List* createList(){
	List* list =calloc(1, sizeof(List));
	list->length = 0;
	return list; 
};
void insertFirst(List* list , int index ,Node* node ){
	if (list->header == NULL) node->next = NULL;
	if (list->header !=NULL) node->next = list->header;
	list->header = node;
};
bool insertNode(List* list , int index , void* data){
	int i=0;
	Node* node = calloc(1,sizeof(node));
	if (index > list->length) return false;
	if (index == 0)	insertFirst(list, index, node);
	else if(index == list->length)	insertLast(list, index,node);
	else insertMiddle(list, index, node);
	node->data = data;
	list->length++;
	return true;
}
void insertLast(List* list , int index ,Node* node ){
	Node* temp = calloc(1, sizeof(Node*));
	temp = list->header;
	while(NULL!=temp->next)
		temp =temp->next;
	temp->next =node;
	node->next = NULL;
}
void insertMiddle(List* list , int index ,Node* node ){
	Node* temp;
	int i=0;
	temp = list->header;
	while(i++ < index-1) temp =temp->next ;
	node->next=temp->next;
	temp->next =node;
}
void deleteFirst(List* list){
	Node* node = list->header;
	if(list->length == 1) list->header = NULL;
	else {
		list->header = list->header->next;
	}
	free(node);
}
void deleteLast(List* list){
	Node* temp , *pre = calloc(1, sizeof(Node*));
	temp = list->header;
	while(NULL!=temp->next){
		pre = temp;
		temp = temp->next;
	}
	pre->next = NULL;
	free(temp);
}
void deleteMiddle(List* list , int index){
	int i=0;
	Node* temp , *node;
	printf("here\n");
	temp = list->header;
	while(i++ < (index - 1)) temp = temp->next ;
	node = temp->next;
	temp->next = node->next;
	free(node);
}
bool deleteNode(List* list , int index){
	if(index >= list->length) return false;
	if(index == 0) deleteFirst(list);
	else if(index == list->length-1)  deleteLast(list);
	else deleteMiddle( list , index);
	list->length--;
	return true;
}