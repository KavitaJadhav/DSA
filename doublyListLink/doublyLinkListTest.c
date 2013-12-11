#include "testUtils.h"
#include "doublyLinkList.h"
#include <stdlib.h>
#include <string.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

void test_createList_function_call_assigns_header_to_null_and_length_to_zero(){
	List* list;
	list = createList();
	ASSERT(NULL == list->header);
	ASSERT(0 == list->length);
}
void test_insert_node_with_int_data_at_starting_of_linked_list(){
	List* list;
	int data = 10;
	list = createList();
	ASSERT(insert(list,0,&data));
	ASSERT(1 == list->length);
	ASSERT(*(int*)list->header->data == 10);
	ASSERT(list->header->prev == NULL);
	ASSERT(list->header->next == NULL);
}
void test_insert_node_with_int_data_at_end_of_linked_list(){
	List* list;
	int data1 = 10,data2= 20;
	Node* node = calloc(1,sizeof(node));
	list = createList();
	ASSERT(insert(list,0,&data1));
	ASSERT(insert(list,1,&data2));
	ASSERT(2 == list->length);
	ASSERT(list->header->prev == NULL);
	ASSERT(list->header->next != NULL);
	ASSERT(*(int*)list->header->data == 10);
	node = list->header;
	ASSERT(*(int*)(node->next->data) == 20);
}
void test_insert_node_with_float_data_at_end_of_linked_list(){
	List* list;
	float data1 = 10.5f,data2= 20.5f;
	Node* node = calloc(1,sizeof(node));
	list = createList();
	ASSERT(insert(list,0,&data1));
	ASSERT(insert(list,1,&data2));
	ASSERT(2 == list->length);
	ASSERT(list->header->prev == NULL);
	ASSERT(list->header->next != NULL);
	ASSERT(*(float*)list->header->data == 10.5f);
	node = list->header;
	ASSERT(*(float*)(node->next->data) == 20.5f);
}
void test_insert_node_with_string_data_at_end_of_linked_list(){
	List* list;
	string data1,data2;
	Node* node = calloc(1,sizeof(node));
	strcpy(data1 , "hi");
	strcpy(data2 , "hello");
	list = createList();
	ASSERT(insert(list,0,&data1));
	ASSERT(insert(list,1,&data2));
	ASSERT(2 == list->length);
	ASSERT(list->header->prev == NULL);
	ASSERT(list->header->next != NULL);
	ASSERT(!strcmp(*(string*)list->header->data , "hi"));
	node = list->header;
	ASSERT(!strcmp(*(string*)(node->next->data) , "hello"));
}
void test_insert_node_with_char_data_at_end_of_linked_list(){
	List* list;
	char data1 = 'k',data2 = 'j';
	Node* node = calloc(1,sizeof(node));
	list = createList();
	ASSERT(insert(list,0,&data1));
	ASSERT(insert(list,1,&data2));
	ASSERT(2 == list->length);
	ASSERT(list->header->prev == NULL);
	ASSERT(list->header->next != NULL);
	ASSERT(*(char*)list->header->data = 'k');
	node = list->header;
	ASSERT(*(char*)(node->next->data) = 'j');
}

void test_insert_node_at_index_which_not_exist_return_false(){
	List* list;
	int data1 = 10,data2= 20;
	Node* node = calloc(1,sizeof(node));
	list = createList();
	ASSERT(insert(list,0,&data1));
	ASSERT(!insert(list,4,&data2));
	ASSERT(1 == list->length);
	ASSERT(*(int*)list->header->data == 10);
}
void test_insert_node_with_string_data_at_starting_of_linked_list(){
	List* list;
	string data = "hello";
	list = createList();
	ASSERT(insert(list,0,&data));
	ASSERT(1 == list->length);
	ASSERT(!strcmp(*(string*)list->header->data , "hello"));
	ASSERT(list->header->prev == NULL);
	ASSERT(list->header->next == NULL);
}
void test_insert_node_with_Float_data_at_starting_of_linked_list(){
	List* list;
	float data = 1.5f;
	list = createList();
	ASSERT(insert(list,0,&data));
	ASSERT(1 == list->length);
	ASSERT(*(float*)list->header->data == 1.5f);
	ASSERT(list->header->prev == NULL);
	ASSERT(list->header->next == NULL);
}
void test_insert_node_with_char_data_at_starting_of_linked_list(){
	List* list;
	char data = 'k';
	list = createList();
	ASSERT(insert(list,0,&data));
	ASSERT(1 == list->length);
	ASSERT(*(char*)list->header->data == 'k');
	ASSERT(list->header->prev == NULL);
	ASSERT(list->header->next == NULL);
}