#include "../doubly-linked-list/doublyLinkList.h"
typedef struct TreeNode{
	Node* node; 
	struct TreeNode* child;
} TreeNode;

typedef struct Tree{
	TreeNode* root;
}Tree;

int insertTreeNode(Tree* tree , void* data , void* parentData ,Compare compare);
void* getParentData(Tree* tree , void* data , Compare compare);
Tree* createTree();

// typedef int (*Compare)(void* element1 , void* element2);
