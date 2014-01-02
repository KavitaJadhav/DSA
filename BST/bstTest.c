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

void test_must_insert_integer_in_binary_tree(){
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