#include "tree.h"
#include <stdlib.h>
#include <stdio.h>

Tree* createTree(CompareFunc compare){
	Tree* tree = calloc(1, sizeof(Tree));
	tree->compare = compare;
	tree->root = NULL;
	return tree;
}	
TreeNode* createTreeNode(void* data){
	TreeNode* tn = calloc(1, sizeof(TreeNode));
	tn->parent = NULL;
	tn->children = NULL;
	tn->data = data;
	return tn;
}
int hasChild(TreeNode* treenode){
	if(NULL == treenode->children) return 0;
	return 1;
}

void* traverseInside(Tree* tree , TreeNode* tn ,Iterator it){
	if(hasChild(tn)) return tn->children;
	if(it.hasNext(&it)) return it.next(&it);
	do{
		tn = tn->parent;
		if(it.hasNext(&it))  return it.next(&it);
	}while(!it.hasNext(&it) && tn->parent != tree->root);
	return NULL;
}
void* traverse(Tree* tree,void* parentData){
	TreeNode* tn = tree->root;
	Iterator it;
	if(0 == tree->compare(tn->data , parentData)) return tn;
	do{
		it  = getIterator(tn->children);
		tn = traverseInside(tree , tn,it);
		if(NULL == tn) return NULL;
		if(0 == tree->compare(tn->data , parentData)) return tn;
	}while(tn != tree->root);
	return tn;
}
int insertToTree(Tree* tree, void* data, void* parentData){
	

	TreeNode* tn = createTreeNode(data);
	Iterator it;
	TreeNode* parentNode;
	List* childList;
	if(tree->root == NULL){
		tree->root = tn;
		return 1;
	}
	return 0;
}
int searchInTree(Tree* tree, void* data){
	TreeNode* tn = createTreeNode(data);
	tn = (TreeNode*)traverse(tree,data);
	if(NULL ==tn) return 0;
	if(tn->data == data) return 1;
	return 0;
}
