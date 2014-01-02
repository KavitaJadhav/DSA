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
