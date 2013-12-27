#include "testUtils.h"
#include "tree.h"
#include <stdlib.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

int compareInts(void *a,void *b){
        return *(int*)a - *(int*)b;
}

void test_insert_Data_At_Root_Node(){
	int data = 10;
	Tree *tree = createTree(compareInts);
	TreeNode *child;
	ASSERT(insertNode(tree, &data, NULL));
	ASSERT(NULL == getchildren(tree,&data));
}

