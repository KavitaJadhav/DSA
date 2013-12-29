#include "testUtils.h"
#include "tree.h"
#include <stdlib.h>
#include <stdio.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed
const int fail =0;
int compareInts(void *a,void *b){
        return *(int*)a - *(int*)b;
}

void test_insert_Data_At_Root_Node(){
	int data = 10 ;
	Tree* tree = createTree(compareInts);
	ASSERT(insertToTree(tree, &data, NULL));
	ASSERT(searchInTree(tree,&data));
}