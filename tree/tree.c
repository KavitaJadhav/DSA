#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

Tree* createTree(){
	Tree* tree  = calloc(1,sizeof(Tree));
	tree->root = NULL;
	return tree;
}

TreeNode* createTreeNode(void *data){
	TreeNode* tn = calloc(1,sizeof(TreeNode));
	tn->node = calloc(1,sizeof(Node));
	tn->child = calloc(1,sizeof(List));
	tn->node->data = data;
	tn->node->next = NULL;
	tn->node->prev = NULL;
	tn->child = NULL;
	return tn;

}

void* traverseToNode(Tree* tree ,TreeNode* tn ,void* parentData ,Compare compare){
	TreeNode* treeNode = tree->root;
	while(treeNode->node->next != NULL)
	{
		if(treeNode->child){
			treeNode = treeNode->child;
			if (0 == compare(treeNode->node->data ,parentData)) 
				return treeNode;
		}
	}
	return NULL;
}

int insertTreeNode(Tree *tree, void *data, void *parentData ,Compare compare){
	TreeNode* tn = createTreeNode(data);
	TreeNode* parentNode;
	if(NULL == tree->root) tree->root = tn;
	else{
		parentNode = traverseToNode(tree , tn ,parentData , compare);
		// parentNode->child->node->data = data;
	}
	return 1;
}

void* getParentData(Tree* tree, void *data , Compare compare){
	if (0 == compare(tree->root->node->data , data)) return NULL;
	return NULL;
}