#include "testUtils.h"
#include "doublyLinkList.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

bool confirmHeader(List* list){
	return (list->header->next ==NULL && list->header->prev == NULL);
}
void test_createList_function_call_assigns_header_to_null_and_length_to_zero(){
	List* list = createList();
	ASSERT(NULL == list->header);
	ASSERT(0 == list->length);
}
void test_insert_node_at_index_which_not_exist_return_false(){
	int data1 = 10,data2= 20;
	Node* node = calloc(1,sizeof(node));
	List* list = createList();

	ASSERT(insertNode(list,0,&data1));
	ASSERT(!insertNode(list,4,&data2));
	ASSERT(1 == list->length);
}
void test_insert_node_with_int_data_at_starting_of_linked_list(){
	int data = 10;
	List* list = createList();
	ASSERT(insertNode(list,0,&data));
	ASSERT(1 == list->length);
	ASSERT(confirmHeader(list));
}
void test_insert_node_with_string_data_at_starting_of_linked_list(){
	string data = "hello";
	List* list = createList();
	ASSERT(insertNode(list,0,&data));
	ASSERT(1 == list->length);
	ASSERT(confirmHeader(list));
}
void test_insert_node_with_Float_data_at_starting_of_linked_list(){
	float data = 1.5f;
	List* list = createList();
	ASSERT(insertNode(list,0,&data));
	ASSERT(1 == list->length);
	ASSERT(confirmHeader(list));
}
void test_insert_node_with_char_data_at_starting_of_linked_list(){
	char data = 'k';
	List* list = createList();
	ASSERT(insertNode(list,0,&data));
	ASSERT(1 == list->length);
	ASSERT(confirmHeader(list));
}
void test_insert_node_with_int_data_at_end_of_linked_list(){
	int data1 = 10,data2= 20;
	Node* node = calloc(1,sizeof(node));
	List* list = createList();
	insertNode(list,0,&data1);
	insertNode(list,1,&data2);
	ASSERT(2 == list->length);
	ASSERT(*(int*)list->header->data == 10);
	node = list->header;
	ASSERT(*(int*)(node->next->data) == 20);
}
void test_insert_node_with_float_data_at_end_of_linked_list(){
	float data1 = 10.5f,data2= 20.5f;
	Node* node = calloc(1,sizeof(node));
	List* list = createList();
	insertNode(list,0,&data1);
	insertNode(list,1,&data2);
	ASSERT(2 == list->length);
	ASSERT(*(float*)list->header->data == 10.5f);
	node = list->header;
	ASSERT(*(float*)(node->next->data) == 20.5f);
}
void test_insert_node_with_string_data_at_end_of_linked_list(){
	string data1 = "hi" ,data2 = "hello";
	Node* node = calloc(1,sizeof(node));
	List* list = createList();
	insertNode(list,0,&data1);
	insertNode(list,1,&data2);
	ASSERT(2 == list->length);
	ASSERT(!strcmp(*(string*)list->header->data , "hi"));
	node = list->header;
	ASSERT(!strcmp(*(string*)(node->next->data) , "hello"));
}
void test_insert_node_with_char_data_at_end_of_linked_list(){
	char data1 = 'k',data2 = 'j';
	Node* node = calloc(1,sizeof(node));
	List* list = createList();
	insertNode(list,0,&data1);
	insertNode(list,1,&data2);
	ASSERT(2 == list->length);
	ASSERT(*(char*)list->header->data = 'k');
	node = list->header;
	ASSERT(*(char*)(node->next->data) = 'j');
}
void test_insert_node_with_int_data_at_middle_of_linked_list(){
	int data1 = 10,data2= 20,data3=30;
	Node* node = calloc(1,sizeof(node));
	List* list = createList();

	insertNode(list,0,&data1);
	insertNode(list,1,&data2);
	insertNode(list,1,&data3);

	ASSERT(3 == list->length);
	ASSERT(*(int*)list->header->data == 10);
	node = (list->header)->next;
	ASSERT(*(int*)(node->data) == 30);
	node = node->next;
	ASSERT(*(int*)(node->data) == 20);
}
void test_insert_node_with_float_data_at_middle_of_linked_list(){
	float data1 = 10.5f,data2= 20.5f,data3=30.5f;
	Node* node = calloc(1,sizeof(node));
	List* list = createList();

	insertNode(list,0,&data1);
	insertNode(list,1,&data2);
	insertNode(list,1,&data3);

	ASSERT(3 == list->length);
	ASSERT(*(float*)list->header->data == 10.5f);
	node = (list->header)->next;
	ASSERT(*(float*)(node->data) == 30.5f);
	node = node->next;
	ASSERT(*(float*)(node->data) == 20.5f);
}
void test_insert_node_with_double_data_at_middle_of_linked_list(){
	double data1 = 10.5,data2= 20.5,data3=30.5;
	Node* node = calloc(1,sizeof(node));
	List* list = createList();

	insertNode(list,0,&data1);
	insertNode(list,1,&data2);
	insertNode(list,1,&data3);

	ASSERT(3 == list->length);
	ASSERT(*(double*)list->header->data == 10.5);
	node = (list->header)->next;
	ASSERT(*(double*)(node->data) == 30.5);
	node = node->next;
	ASSERT(*(double*)(node->data) == 20.5);
}
void test_insert_node_with_string_data_at_middle_of_linked_list(){
	string data1 = "kajal", data2 = "shital", data3 = "manali";
	Node* node = calloc(1,sizeof(node));
	List* list = createList();

	insertNode(list,0,&data1);
	insertNode(list,1,&data2);
	insertNode(list,1,&data3);

	ASSERT(3 == list->length);
	ASSERT(!strcmp(*(string*)list->header->data , "kajal"));
	node = (list->header)->next;
	ASSERT(!strcmp(*(string*)(node->data) , "manali"));
	node = node->next;
	ASSERT(!strcmp(*(string*)(node->data) , "shital"));
}
void test_insert_node_with_int_data_at_middle_of_linked_list1(){
	int data1 = 10,data2= 20,data3=30,data4=40;
	Node* node = calloc(1,sizeof(node));
	List* list = createList();

	insertNode(list,0,&data1);
	insertNode(list,1,&data2);
	insertNode(list,2,&data3);
	insertNode(list,2,&data4);

	ASSERT(4 == list->length);
	ASSERT(*(int*)list->header->data == 10);
	node = (list->header)->next;
	ASSERT(*(int*)(node->data) == 20);
	node = node->next;
	ASSERT(*(int*)(node->data) == 40);
	node = node->next;
	ASSERT(*(int*)(node->data) == 30);
}

void test_insert_node_with_int_data_at_start_of_linked_list(){
	int data1 = 10,data2= 20,data3=30;
	Node* node = calloc(1,sizeof(node));
	List* list = createList();

	insertNode(list,0,&data1);
	insertNode(list,1,&data2);
	insertNode(list,0,&data3);

	ASSERT(3 == list->length);
	ASSERT(*(int*)list->header->data == 30);
	node = (list->header)->next;
	ASSERT(*(int*)(node->data) == 10);
	node = node->next;
	ASSERT(*(int*)(node->data) == 20);
}
void test_delete_node_with_int_data_at_starting_of_linked_list_which_length_is_1(){
	int data = 10;
	List* list = createList();
	insertNode(list,0,&data);

	ASSERT(1 == list->length);
	ASSERT(*(int*)list->header->data == 10);
	deleteNode(list,0);
	ASSERT(0 == list->length);
}
void test_delete_node_with_index_that_not_exist_return_false(){
	int data = 10;
	List* list = createList();
	insertNode(list,0,&data);
	ASSERT(1 == list->length);
	ASSERT(!deleteNode(list,2));
}
void test_delete_node_with_float_data_at_starting_of_linked_list_which_length_is_1(){
	float data = 10.5f;
	List* list = createList();
	insertNode(list,0,&data);
	ASSERT(1 == list->length);
	ASSERT(*(float*)list->header->data == 10.5f);
	deleteNode(list,0);
	ASSERT(0 == list->length);
}
void test_delete_node_with_double_data_at_starting_of_linked_list_which_length_is_1(){
	double data = 10.555;
	List* list = createList();
	insertNode(list,0,&data);
	ASSERT(1 == list->length);
	ASSERT(*(double*)list->header->data == 10.555);
	deleteNode(list,0);
	ASSERT(list->header == NULL);
	ASSERT(0 == list->length);
}
void test_delete_node_with_string_data_at_starting_of_linked_list_which_length_is_1(){
	string data = "Samiksha";
	List* list = createList();
	insertNode(list,0,&data);
	ASSERT(1 == list->length);
	ASSERT(!strcmp(*(string*)list->header->data , "Samiksha"));
	deleteNode(list,0);
	ASSERT(list->header == NULL);
	ASSERT(0 == list->length);
}
void test_delete_node_with_int_data_at_end_of_linked_list_which_length_is(){
	Node* node;
	int data1 = 10 , data2 = 20 , data3 = 30;
	List* list = createList();

	insertNode(list,0,&data1);
	insertNode(list,1,&data2);
	insertNode(list,1,&data3);

	ASSERT(3 == list->length);
	deleteNode(list,2);

	ASSERT(*(int*)list->header->data == 10);
	node = list->header->next;
	ASSERT(*(int*)node->data == 30);
	node = node->next;
	ASSERT(2 == list->length);
}
void test_delete_node_with_float_data_at_end_of_linked_list_which_length_is(){
	Node* node;
	int data1 = 10 , data2 = 20 , data3 = 30;
	List* list = createList();

	insertNode(list,0,&data1);
	insertNode(list,1,&data2);
	insertNode(list,2,&data3);

	ASSERT(3 == list->length);
	deleteNode(list,2);

	ASSERT(*(int*)list->header->data == 10);
	node = list->header->next;
	ASSERT(*(int*)node->data == 20);
	node = node->next;
	ASSERT(2 == list->length);
}
void test_delete_node_with_int_data_at_middle_of_linked_list(){
	int data1 = 10,data2= 20,data3=30,data4=40;
	Node* node = calloc(1,sizeof(node));
	List* list = createList();

	insertNode(list,0,&data1);
	insertNode(list,1,&data2);
	insertNode(list,2,&data3);
	insertNode(list,3,&data4);

	ASSERT(4 == list->length);
	deleteNode(list, 1);

	ASSERT(*(int*)list->header->data == 10);
	node = (list->header)->next;
	ASSERT(*(int*)(node->data) == 30);
	node = node->next;
	ASSERT(*(int*)(node->data) == 40);
	ASSERT(3 == list->length);
}
void test_delete_node_with_float_data_at_middle_of_linked_list(){
	float data1 = 10.5f,data2= 20.5f,data3=30.5f;
	Node* node = calloc(1,sizeof(node));
	List* list = createList();

	insertNode(list,0,&data1);
	insertNode(list,1,&data2);
	insertNode(list,2,&data3);

	ASSERT(3 == list->length);
	deleteNode(list, 1);
	ASSERT(*(float*)list->header->data == 10.5f);
	node = (list->header)->next;
	ASSERT(*(float*)(node->data) == 30.5f);
	ASSERT(2 == list->length);
}
void test_delete_node_with_string_data_at_middle_of_linked_list(){
	List* list  = createList();
	string data1 = "kajal",data2 = "shital",data3 ="manali";
	Node* node = calloc(1,sizeof(node));
	insertNode(list,0,&data1);
	insertNode(list,1,&data2);
	insertNode(list,1,&data3);
	ASSERT(3 == list->length);
	deleteNode(list, 1);
	ASSERT(!strcmp(*(string*)list->header->data , "kajal"));
	node = (list->header)->next;
	ASSERT(!strcmp(*(string*)(node->data) , "shital"));
}

