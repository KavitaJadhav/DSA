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
bool insert(List* list , int index , void* data){
	int i=0;
	Node* temp,*node = calloc(1,sizeof(node));
	if (index > list->length) return false;
	if (list->header == NULL){
		list->header = node;
		node->prev = NULL;
	}
	else{
		temp = list->header;
		while(NULL!=temp->next)
			temp =temp->next;
		node->prev=temp;
		temp->next =node; 
	}
	node->next = NULL;
	node->data = data;
	list->length++;
	return true;
}