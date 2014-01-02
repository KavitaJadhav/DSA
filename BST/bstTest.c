#include "testUtils.h"
#include "bst.h"

int SUCCESS = 1;
int FAILURE = 0;
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

int compare(void* a , void* b){
        return *(int*)a - *(int*)b;
}

BST* tree;
void setup(){
	tree = createBST(compare);
}

void test_must_insert_root_data(){
	int data = 5;
	ASSERT(SUCCESS == insertInBST(tree,&data));
	ASSERT(SUCCESS == searchInBST(tree,&data));
}

void test_must_insert_large_data_on_right_side_of_root(){
	int data[] = {5,10};
	
	ASSERT(SUCCESS == insertInBST(tree,&data[0]));
	ASSERT(SUCCESS == insertInBST(tree,&data[1]));
	ASSERT(SUCCESS == searchInBST(tree,&data[1]));
}

void test_must_insert_small_data_on_left_side_of_root(){
	int data[] = {20,10};
	
	ASSERT(SUCCESS == insertInBST(tree,&data[0]));
	ASSERT(SUCCESS == insertInBST(tree,&data[1]));
	ASSERT(SUCCESS == searchInBST(tree,&data[1]));
}

void test_must_not_search_element_if_not_present(){
	int searchElement = 10;
	int data = 5;
	ASSERT(SUCCESS == insertInBST(tree,&data));
	ASSERT(FAILURE == searchInBST(tree,&searchElement));
}

void test_must_insert_data_at_second_level_on_right_side(){
	int data[] = {10,20,30};
	
	insertInBST(tree,&data[0]);
	insertInBST(tree,&data[1]);
	insertInBST(tree,&data[2]);
	ASSERT(SUCCESS == searchInBST(tree,&data[0]));
	ASSERT(SUCCESS == searchInBST(tree,&data[1]));
	ASSERT(SUCCESS == searchInBST(tree,&data[2]));
}

void test_must_insert_data_at_second_level_on_left_side(){
	int data[] = {30,20,10};
	
	insertInBST(tree,&data[0]);
	insertInBST(tree,&data[1]);
	insertInBST(tree,&data[2]);
	ASSERT(SUCCESS == searchInBST(tree,&data[0]));
	ASSERT(SUCCESS == searchInBST(tree,&data[1]));
	ASSERT(SUCCESS == searchInBST(tree,&data[2]));
}

void test_must_delete_root_data(){
	int data = 5;
	insertInBST(tree,&data);
	ASSERT(SUCCESS == deleteFromBST(tree,&data));
	ASSERT(FAILURE == searchInBST(tree,&data));
}

void test_shod_not_delete_data_that_not_exist(){
	int data = 5,elementToDelete = 10;
	insertInBST(tree,&data);
	ASSERT(FAILURE == deleteFromBST(tree,&elementToDelete));
}

void test_deletion_of_left_leaf_node(){
	int data[] = {30,20,10};
	
	insertInBST(tree,&data[0]);
	insertInBST(tree,&data[1]);
	insertInBST(tree,&data[2]);
	ASSERT(SUCCESS == deleteFromBST(tree,&data[2]));
	ASSERT(FAILURE == searchInBST(tree,&data[2]));
}

void test_deletion_of_right_leaf_node(){
	int data[] = {10,20,30};
	
	insertInBST(tree,&data[0]);
	insertInBST(tree,&data[1]);
	insertInBST(tree,&data[2]);
	ASSERT(SUCCESS == deleteFromBST(tree,&data[2]));
	ASSERT(FAILURE == searchInBST(tree,&data[2]));
}