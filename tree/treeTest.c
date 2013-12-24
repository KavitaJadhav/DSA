#include "testUtils.h"
#include "tree.h"
#include <stdlib.h>
#include <stdio.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed
int areNumberSame(void* num1 ,void* num2){
	if( *(int*)num1 == *(int*)num2) return 0;
	return 1;
}
void test_insert_Data_At_Root_Node(){
	int data = 10;
	Tree* tree = createTree();
	insertTreeNode(tree, &data, NULL);
	ASSERT(!getParentData(tree , &data ,areNumberSame));
}
void test_insert_Data_As_child_of_Root_Node(){
	int data[] = {10 , 20};
	Tree* tree = createTree();
	insertTreeNode(tree, &data[0], NULL);
	insertTreeNode(tree, &data[1], NULL);
	printf("%d\n",*(int*)tree->root->node->data );
	ASSERT(&data[0] == getParentData(tree , &data[1] , areNumberSame));
}