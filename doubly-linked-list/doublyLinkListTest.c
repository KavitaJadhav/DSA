#include "testUtils.h"
#include "doublyLinkList.h"
#include <stdlib.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

bool confirmHeader(List* list){
	return (list->header->next ==NULL && list->header->prev == NULL);
}


void test_insert_data_at_index_which_not_exist_return_false(){
	int data = 10;
	List* list = createList();
	ASSERT(!insertNode(list,4,&data));
}
void test_insert_int_data_at_starting_of_linked_list(){
	int data = 10;
	List* list = createList();
	ASSERT(insertNode(list,0,&data));
	ASSERT(&data == getElement(list, 0));
}
void test_getElement_give_element_at_index(){
	string data1 = "kajal" ,data2 = "shital" ,data3 = "manali";
	List* list = createList();

	insertNode(list,0,&data1);
	insertNode(list,1,&data2);
	insertNode(list,1,&data3);

	ASSERT(&data1 == getElement(list, 0));
}
void test_insert_char_data_at_starting_of_linked_list(){
	char data = 'A';
	List* list = createList();
	ASSERT(insertNode(list,0,&data));
	ASSERT(&data == getElement(list, 0));
}
void test_insert_string_data_at_starting_of_linked_list(){
	string data = "AAAAA";
	List* list = createList();
	ASSERT(insertNode(list,0,&data));
	ASSERT(&data == getElement(list, 0));
}
void test_insert_float_data_at_starting_of_linked_list(){
	float data = 10.5f;
	List* list = createList();
	ASSERT(insertNode(list,0,&data));
	ASSERT(&data == getElement(list, 0));
}
void test_insert_node_with_int_data_in_linked_list(){
	List* list = createList();
	int data[] = {10,20,30,40,50};

	insertNode(list,0,&data[0]);
	insertNode(list,1,&data[1]);
	insertNode(list,2,&data[2]);
	insertNode(list,3,&data[3]);

	ASSERT(&data[0] == getElement(list, 0));
	ASSERT(&data[1] == getElement(list, 1));
	ASSERT(&data[2] == getElement(list, 2));
	ASSERT(&data[3] == getElement(list, 3));
}
void test_insert_node_with_float_data_in_linked_list(){
	List* list = createList();
	float data[] = {10.05f,20.05f,30.05f,40.05f,50.05f};

	insertNode(list,0,&data[0]);
	insertNode(list,1,&data[1]);
	insertNode(list,2,&data[2]);
	insertNode(list,3,&data[3]);

	ASSERT(&data[0] == getElement(list, 0));
	ASSERT(&data[1] == getElement(list, 1));
	ASSERT(&data[2] == getElement(list, 2));
	ASSERT(&data[3] == getElement(list, 3));
}
void test_insert_node_with_string_data_in_linked_list(){
	List* list = createList();
	string data[] = {"AAA","BBB","CCC","DDD","EEE"};

	insertNode(list,0,&data[0]);
	insertNode(list,1,&data[1]);
	insertNode(list,2,&data[2]);
	insertNode(list,3,&data[3]);

	ASSERT(&data[0] == getElement(list, 0));
	ASSERT(&data[1] == getElement(list, 1));
	ASSERT(&data[2] == getElement(list, 2));
	ASSERT(&data[3] == getElement(list, 3));
}
void test_insert_node_with_string_data_in_middle_of_linked_list(){
	List* list = createList();
	string data[] = {"AAA","BBB","CCC","DDD","EEE"};

	insertNode(list,0,&data[0]);
	insertNode(list,1,&data[1]);
	insertNode(list,1,&data[2]);

	ASSERT(&data[0] == getElement(list, 0));
	ASSERT(&data[2] == getElement(list, 1));
	ASSERT(&data[1] == getElement(list, 2));
}
void test_insert_node_with_integer_data_in_middle_of_linked_list(){
	List* list = createList();
	int data[] = {100,200,300,400};

	insertNode(list,0,&data[0]);
	insertNode(list,1,&data[1]);
	insertNode(list,1,&data[2]);

	ASSERT(&data[0] == getElement(list, 0));
	ASSERT(&data[2] == getElement(list, 1));
	ASSERT(&data[1] == getElement(list, 2));
}
void test_delete_data_at_index_that_not_exist(){
	List* list = createList();
	ASSERT(!deleteNode(list,0));
}
void test_delete_data_at_given_index(){
	List* list = createList();
	int data[] = {100,200,300,400};

	insertNode(list,0,&data[0]);
	insertNode(list,1,&data[1]);
	insertNode(list,2,&data[2]);

	ASSERT(deleteNode(list,2));
	ASSERT(deleteNode(list,1));
	ASSERT(deleteNode(list,0));
	ASSERT(!getElement(list, 0));
}

int  compareIntData(void* element1 , void* element2){
	return *(int*)element1 - *(int*)element2;
}
void test_search_data_in_given_list_return_index(){
	List* list = createList();
	int data[] = {100,200,300,400};

	insertNode(list,0,&data[0]);
	insertNode(list,1,&data[1]);
	insertNode(list,2,&data[2]);

	ASSERT(1 == search(list, &data[1], compareIntData));
}
void test_search_data_in_empty_list_return_minus_one(){
	List* list = createList();
	int data = 10;
	ASSERT(-1 == search(list, &data, compareIntData));
}
void test_search_gives_minus_one_if_data_not_found(){
	List* list = createList();
	int data[] = {100,200,300,400};
	int element = 10;

	insertNode(list,0,&data[0]);
	insertNode(list,1,&data[1]);
	insertNode(list,2,&data[2]);

	ASSERT(-1 == search(list, &element, compareIntData));
}
void test_hasnext_of_getiterator_gives_false_if_list_not_empty(){
	List* list = createList();
	Iterator it = getIterator(list);
	ASSERT(0 == it.hasNext(&it));
}
void test_hasnext_of_getiterator_gives_true_if_list_not_empty(){
	List* list = createList();
	Iterator it;
	int data[] = {100,200,300,400};
	insertNode(list,0,&data[0]);
	it = getIterator(list);
	ASSERT(1 == it.hasNext(&it));
}
void test_next_of_getiterator_gives_next_data(){
	List* list = createList();
	Iterator it;
	int data[] = {100,200,300,400};
	insertNode(list,0,&data[0]);
	it = getIterator(list);
	if(it.hasNext(&it))
	ASSERT(&data[0] == it.next(&it));
}
void test_should_give_all_values_using_iterator(){
	List* list = createList();
	Iterator it;
	int i = 0;
	int numbers[] = {5,10,15,20,30,40};
	insertNode(list, 0, numbers);
	insertNode(list, 1, &numbers[1]);
	insertNode(list, 2, &numbers[2]);
	insertNode(list, 3, &numbers[3]);
	insertNode(list, 4, &numbers[4]);
	insertNode(list, 5, &numbers[5]);
	it = getIterator(list);
	while(it.hasNext(&it)){                
	        ASSERT(numbers[i] == *(int*)it.next(&it));
	        i++;
	}
}
void test_testing_hasNext(){
	List* list = createList();
	Iterator it;
	int i = 0;
	int numbers[] = {5,10,15,20,30,40};
	insertNode(list, 0, numbers);
	insertNode(list, 1, &numbers[1]);
	insertNode(list, 2, &numbers[2]);
	insertNode(list, 3, &numbers[3]);
	insertNode(list, 4, &numbers[4]);
	insertNode(list, 5, &numbers[5]);
	it = getIterator(list);
	while(it.hasNext(&it)){                
	        ASSERT(numbers[i] == *(int*)it.next(&it));
	        i++;
}
}