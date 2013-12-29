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
void test_should_not_insert_Root_Node_if_parent_data_given(){
	int data = 10 , parent = 20;
	Tree* tree = createTree(compareInts);
	ASSERT(fail == insertToTree(tree, &data, &parent));
}
void test_should_not_insert_child_Node_if_parent_data_not_given(){
	int root = 34,node =24; 
	Tree *tree = createTree(compareInts);
	insertToTree(tree, &root, NULL);
	ASSERT(fail == insertToTree(tree, &node,NULL));
}
void test_insert_Data_As_child_to_root_Node(){
	int data[] ={10,5,3,7,1,20}; 
	Tree *tree = createTree(compareInts);
	Iterator it;

	insertToTree(tree, &data[0], NULL);
	insertToTree(tree, &data[1],&data[0]);
	insertToTree(tree, &data[2],&data[0]);

	it = getChildren(tree, &data[0]);
	// ASSERT(&data[1] == it.next(&it));
	// ASSERT(&data[2] == it.next(&it));
}
void test_insert_Data_As_desendent_to_root_Node(){
	int data[] ={10,5,3,7,1,20}; 
	Tree *tree = createTree(compareInts);
	Iterator  it;
	insertToTree(tree, &data[0], NULL);
	insertToTree(tree, &data[1],&data[0]);
	insertToTree(tree, &data[2],&data[1]);
	
	it = getChildren(tree,&data[1]);
	// ASSERT(&data[2] == it.next(&it));
}