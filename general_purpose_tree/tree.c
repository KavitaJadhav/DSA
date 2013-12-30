#include "tree.h"
#include <stdlib.h>
#include <stdio.h>

void* (*listNext)(struct iterator *it);

Tree* createTree(CompareFunc compare){
	Tree* tree = calloc(1, sizeof(Tree));
	tree->compare = compare;
	tree->root = NULL;
	return tree;
};	
TreeNode* createTreeNode(void* data){
	TreeNode* tn = calloc(1, sizeof(TreeNode));
	tn->parent = NULL;
	tn->children = NULL;
	tn->data = data;
	return tn;
};
int hasChild(TreeNode* treenode){
	if(NULL == treenode->children) return 0;
	return 1;
};
void* traverseInside(Tree* tree , TreeNode* tn){
	Iterator it;
	if(hasChild(tn)) return tn->children->header;
	it = getIterator(tn->parent->children );
	if(it.hasNext(&it)) return nextdata(&it);
	do{
		tn = tn->parent;
		if(it.hasNext(&it))  return it.next(&it);
	}while(!it.hasNext(&it) && tn->parent != tree->root);
	return NULL;
};
void* traverse(Tree* tree,void* parentData){
	TreeNode* tn = tree->root;
	Node* node;
	if(0 == tree->compare(tn->data , parentData)) return tn;
	if(tn->children ==NULL) return NULL;
	do{
		tn = traverseInside(tree , tn);
		if(NULL == tn) return NULL;
		if(0 == tree->compare(tn->data , parentData)) return tn;
	}while(tn != tree->root);
	return tn;
};
int insertToTree(Tree* tree, void* data, void* parentData){
	TreeNode* tn = createTreeNode(data);
	TreeNode* parentNode;
	List* childList;
	if(tree->root == NULL ){
		if(parentData != NULL) return 0;
		tree->root = tn;
		return 1;
	}
	if(parentData == NULL) return 0;
	parentNode = traverse(tree,parentData);
	if(parentNode == NULL) return 0;
	if(parentNode->children == NULL) {
		parentNode->children = (List*)createList();
		tn->parent = parentNode;
		insertNode(parentNode->children, 0, tn);
	}
	else{
		childList = parentNode->children;
			tn->parent = parentNode;
			insertNode(childList, childList->length, tn);
	}
	return 0;
};
int searchInTree(Tree* tree, void* data){
	TreeNode* tn = createTreeNode(data);
	tn = (TreeNode*)traverse(tree,data);
	if(NULL ==tn) return 0;
	if(tn->data == data) return 1;
	return 0;
};
void* nextdata(Iterator* it){
	TreeNode* node=listNext(it);
	return node->data;
}
Iterator getChildren(Tree* tree,void* parentData){
	List* children;
	Iterator it;
	TreeNode* parentNode = traverse(tree,parentData);
	children = (List*)parentNode->children;
	it = getIterator(children);
	listNext = it.next;
	it.next= &nextdata;
	return it;
};