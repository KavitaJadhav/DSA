#include "doublyLinkList.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

List* createList(){
	List* list =calloc(1, sizeof(List));
	list->header = NULL;
	list->length = 0;
	return list; 
}
void insertFirst(List* list , int index ,Node* node ){
	if (list->header == NULL) node->next = NULL;
	if (list->header !=NULL) node->next = list->header;
	list->header = node;
	node->prev = NULL;
}
void insertLast(List* list , int index ,Node* node ){
	Node* temp;
	temp = list->header;
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
