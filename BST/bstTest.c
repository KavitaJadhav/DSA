#include "testUtils.h"
#include "bst.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed
int compare(void* a , void* b){
        return *(int*)a - *(int*)b;
}

void test_must_insert_integer_in_binary_tree(){
	BST* tree;
	int data = 5;
	tree = createBST(compare);
	ASSERT(1 == insertInBST(tree,&data));
	ASSERT(1 == searchInBST(tree,&data));
}

void test_must_insert_large_data_on_right_side_of_root(){
	BST* tree;
	int data[] = {5,10};
	tree = createBST(compare);
	
	ASSERT(1 == insertInBST(tree,&data[0]));
	ASSERT(1 == insertInBST(tree,&data[1]));
	ASSERT(1 == searchInBST(tree,&data[1]));
}

void test_must_insert_small_data_on_left_side_of_root(){
	BST* tree;
	int data[] = {20,10};
	tree = createBST(compare);
	
	ASSERT(1 == insertInBST(tree,&data[0]));
	ASSERT(1 == insertInBST(tree,&data[1]));
	ASSERT(1 == searchInBST(tree,&data[1]));
}