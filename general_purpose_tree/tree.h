#include "../doubly-linked-list/doublyLinkList.h"

typedef int (*CompareFunc)(void* firstElement, void* secondElement);
typedef struct {
        CompareFunc compare;
        void *root;
} Tree;

typedef struct TreeNode{
        void* data;
        struct TreeNode* parent;
        List* children;
} TreeNode;
void* nextdata(Iterator* it);

Tree* createTree(CompareFunc cmp);
int insertToTree(Tree* tree, void* data, void* parentData);
Iterator getChildren(Tree* tree, void* parentData);
int deleteFromTree(Tree* tree, void* data);
int searchInTree(Tree* tree, void* data);